#include "body_kinematics.hpp"

BodyKinematics::BodyKinematics() {}

const static std::string suffixes[6] = { "_r1", "_r2", "_r3", "_l1", "_l2", "_l3" };

bool BodyKinematics::init() {
    std::string robot_desc_string;
    // Get URDF XML
    if (!node.getParam("robot_description", robot_desc_string)) {
        ROS_ERROR("Node Error : taticoma_body_kinematics : Could not load the xml from parameter: robot_description");
        return false;
    }

    // Get Root and Tip From Parameter Server
    node.param("root_name_body", root_name, std::string("leg_center"));
    node.param("tip_name_body", tip_name, std::string("coha"));
    node.param("clearance", _z, 0.0);
    node.param("leg_radius", _leg_radius, 0.0);

    //bs.leg_radius = _leg_radius;
    bs.leg_radius = 0.1224;
    bs.z = -_z;

    // Load and Read Models
    if (!loadModel(robot_desc_string)) {
        ROS_ERROR("Node Error : taticoma_body_kinematics : Could not load models");
        return false;
    }

    client = node.serviceClient<taticoma_msgs::GetLegIKSolver>("/taticoma_leg_kinematics/get_ik");
    joints_pub = node.advertise<taticoma_msgs::LegsJointsState>("/taticoma_joints_to_controller", 1);
    body_move_sub = node.subscribe<taticoma_msgs::BodyState>("/teleop/move_body", 1, &BodyKinematics::teleopBodyMove, this);
    //body_cmd_sub = node.subscribe<taticoma_msgs::BodyCommand>("/teleop/body_command", 1, &BodyKinematics::teleopBodyCmd, this);

    ros::Duration(1).sleep();
    if (calculateKinematics(&bs)) {
        joints_pub.publish(legs);
    }

    ROS_WARN("Node Ready : taticoma_body_kinematics");

    return true;
}

bool BodyKinematics::loadModel(const std::string xml) {
    //Construct tree with kdl_parser
    KDL::Tree tree;

    if (!kdl_parser::treeFromString(xml, tree)) {
        ROS_ERROR("Node Error : taticoma_body_kinematics : Could not initialize tree object");
        return false;
    }

    ROS_WARN("Node Msg   : taticoma_body_kinematics : Construct tree");

    //Get coxa and leg_center frames via segments (for calculating vectors)
    std::map<std::string, KDL::TreeElement>::const_iterator segments_iter;
    std::string link_name_result;
    for (int i = 0; i < num_legs; i++) {
        link_name_result = root_name + suffixes[i];
        segments_iter = tree.getSegment(link_name_result);
        frames.push_back((*segments_iter).second.segment.getFrameToTip());
    }
    for (int i = 0; i < num_legs; i++) {
        link_name_result = tip_name + suffixes[i];
        segments_iter = tree.getSegment(link_name_result);
        frames.push_back((*segments_iter).second.segment.getFrameToTip());
    }

    ROS_WARN("Node Msg   : taticoma_body_kinematics : Get frames");

    //Vector iterators
    for (int i = 0; i < num_legs; i++) {
        frames[i] = frames[i] * frames[i + num_legs];
    }
    frames.resize(num_legs);

    for (int i = 0; i < num_legs; i++) {
        for (int j = 0; j < num_joints; j++) {
            legs.joints_state[i].joint[j] = 0;
        }
    }

    return true;
}

bool BodyKinematics::calculateKinematics(taticoma_msgs::BodyState* body_ptr) {

    //Body rotation
    rotation = KDL::Rotation::RPY(body_ptr->roll, body_ptr->pitch, body_ptr->yaw);

    //Distance from body center to leg tip
    femur_frame = KDL::Frame(KDL::Vector(body_ptr->leg_radius, 0, 0));

    //Offset from center
    offset_vector = KDL::Vector(body_ptr->x, body_ptr->y, body_ptr->z);
    rotate_correction = KDL::Vector(body_ptr->z * tan(body_ptr->pitch), -(body_ptr->z * tan(body_ptr->roll)), 0);

    for (int i = 0; i < num_legs; i++) {
        //Get tip frames
        tibia_foot_frame = frames[i] * femur_frame;
        //Get tip vectors with body position
        final_vector[i] = (rotation * tibia_foot_frame.p) + offset_vector + rotate_correction;
        //	ROS_INFO("Position vector leg%s\tx: %f\ty: %f\tz: %f", suffixes[i].c_str(),
        //final_vector[i](0),final_vector[i](1),final_vector[i](2));
    }

    //ROS_INFO("Call service: /leg_ik_service/get_ik");
    if (!callService(final_vector)) {
        return 0;
    }

    return true;
}

bool BodyKinematics::callService(KDL::Vector* vector) {
    taticoma_msgs::LegPositionState leg_pos_buf;
    srv.request.leg_number.clear();
    srv.request.target_position.clear();
    srv.request.current_joints.clear();

    //Creating message to request
    for (int i = 0; i < num_legs; i++) {
        srv.request.leg_number.push_back(i);
        leg_pos_buf.x = vector[i].x();
        leg_pos_buf.y = vector[i].y();
        leg_pos_buf.z = vector[i].z();
        srv.request.target_position.push_back(leg_pos_buf);
        srv.request.current_joints.push_back(legs.joints_state[i]);
    }
    //Call service and parsing response
    if (client.call(srv)) {
        if (srv.response.error_codes == srv.response.IK_FOUND) {
            for (int i = 0; i < num_legs; i++) {
                for (int j = 0; j < num_joints; j++) {
                    legs.joints_state[i].joint[j] = srv.response.target_joints[i].joint[j];
                }
                //ROS_INFO("Joints received leg%s\t1: %f\t2: %f\t3: %f", suffixes[i].c_str(),
                //legs.joints_state[i].joint[0],
                //legs.joints_state[i].joint[1],
                //legs.joints_state[i].joint[2]);
            }
        } else {
            ROS_ERROR("Node Error : taticoma_body_kinematics : An IK solution could not be found");
            return 0;
        }
    } else {
        ROS_ERROR("Node Error : taticoma_body_kinematics : Failed to call service");
        return 0;
    }
    return true;
}

void BodyKinematics::teleopBodyMove(const taticoma_msgs::BodyStateConstPtr& body_state) {
    bs.x = body_state->x;
    bs.y = body_state->y;
    bs.z = body_state->z;
    bs.pitch = body_state->pitch;
    bs.roll = body_state->roll;
    bs.yaw = body_state->yaw;
    bs.leg_radius = body_state->leg_radius;

    //ROS_INFO("KINEMATICS ROLL PITCH ROLL: %f PITCH: %f YAW: %f",bs.roll, bs.pitch, bs.yaw);

    if (calculateKinematics(&bs)) {
        joints_pub.publish(legs);
    }
}

// void BodyKinematics::teleopBodyCmd(const taticoma_msgs::BodyCommandConstPtr &body_cmd)
// {
// 	if (body_cmd->cmd == body_cmd->STAND_UP_CMD)
// 	{
// 		ROS_ERROR("STAND_UP_CMD");
// 		ros::Rate r(25);
// 		while (bs.z >= -z)
// 		{
// 			bs.z -= 0.0025;
// 			r.sleep();
// 			if (calculateKinematics(&bs))
// 			{
// 				joints_pub.publish(legs);
// 			}
// 		}
// 	}
// 	if (body_cmd->cmd == body_cmd->SEAT_DOWN_CMD)
// 	{
// 		ROS_ERROR("SEAT_DOWN_CMD");
// 		ros::Rate r(25);
// 		while (bs.z <= -0.07)
// 		{
// 			bs.z += 0.0025;
// 			r.sleep();
// 			if (calculateKinematics(&bs))
// 			{
// 				joints_pub.publish(legs);
// 			}
// 		}
// 	}
// }

int main(int argc, char** argv) {
    ros::init(argc, argv, "body_kinematics");
    BodyKinematics k;
    if (k.init() < 0) {
        ROS_ERROR("Node Error : taticoma_body_kinematics : Could not initialize kinematics node");
        return -1;
    }

    ros::spin();
    return 0;
}
