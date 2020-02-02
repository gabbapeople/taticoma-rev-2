
#include "taticoma_dynamixel_controller.hpp"

Controller::Controller()
{
    node.param<std::string>("dynamixel_serial_port", serial_port, "0");
    node.param<int>("dynamixel_serial_baudrate", serial_baudrate, 0);
    
    ttcm_dxl_pos_sub = node.subscribe("/taticoma_joints_to_controller", 1, &Controller::chatterLegsState, this);
    
    ROS_WARN("Node Ready : taticoma_dynamixel_controller");

    if (scanDynamixels()) {
        setMovingSpeed();
        //ledsOn();    
    }
}

void Controller::setMovingSpeed()
{
    int32_t speed = 0;
    for (uint8_t i = 0; i < ttcm_dxl_total; i++) {
        dxl_wb.goalVelocity(ttcm_dxl_id[i], speed);
    }
    //ROS_WARN("Node Msg : taticoma_dynamixel_controller : Moving speed : %s", log);
}

void Controller::setLedsOn()
{
	for (uint8_t i = 0; i < ttcm_dxl_total; i++)
	{
		dxl_wb.ledOn(ttcm_dxl_id[i]);
	}
}

double Controller::map(double x)
{
    return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void Controller::chatterLegsState(const LegsStateConstPtr& state)
{

    //double target_pos = -1 * state->joints_state[0].joint[0];
    //ROS_WARN("%f %d ",target_pos, (int32_t)map(target_pos));
    //dxl_wb.goalPosition(ttcm_dxl_id[0], (int32_t)map(target_pos));

    dxl_wb.goalPosition(ttcm_dxl_id[0], (int32_t)map(-1 * state->joints_state[0].joint[0]));
    dxl_wb.goalPosition(ttcm_dxl_id[1], (int32_t)map(state->joints_state[0].joint[1]));
    dxl_wb.goalPosition(ttcm_dxl_id[2], (int32_t)map(-1 * state->joints_state[0].joint[2]));

    dxl_wb.goalPosition(ttcm_dxl_id[3], (int32_t)map(-1 * state->joints_state[1].joint[0]));
    dxl_wb.goalPosition(ttcm_dxl_id[4], (int32_t)map(state->joints_state[1].joint[1]));
    dxl_wb.goalPosition(ttcm_dxl_id[5], (int32_t)map(-1 * state->joints_state[1].joint[2]));

    dxl_wb.goalPosition(ttcm_dxl_id[6], (int32_t)map(-1 * state->joints_state[2].joint[0]));
    dxl_wb.goalPosition(ttcm_dxl_id[7], (int32_t)map(state->joints_state[2].joint[1]));
    dxl_wb.goalPosition(ttcm_dxl_id[8], (int32_t)map(-1 * state->joints_state[2].joint[2]));

    dxl_wb.goalPosition(ttcm_dxl_id[9], (int32_t)map(-1 * state->joints_state[3].joint[0]));
    dxl_wb.goalPosition(ttcm_dxl_id[10], (int32_t)map(state->joints_state[3].joint[1]));
    dxl_wb.goalPosition(ttcm_dxl_id[11], (int32_t)map(-1 * state->joints_state[3].joint[2]));

    dxl_wb.goalPosition(ttcm_dxl_id[12], (int32_t)map(-1 * state->joints_state[4].joint[0]));
    dxl_wb.goalPosition(ttcm_dxl_id[13], (int32_t)map(state->joints_state[4].joint[1]));
    dxl_wb.goalPosition(ttcm_dxl_id[14], (int32_t)map(-1 * state->joints_state[4].joint[2]));

    dxl_wb.goalPosition(ttcm_dxl_id[15], (int32_t)map(-1 * state->joints_state[5].joint[0]));
    dxl_wb.goalPosition(ttcm_dxl_id[16], (int32_t)map(state->joints_state[5].joint[1]));
    dxl_wb.goalPosition(ttcm_dxl_id[17], (int32_t)map(-1 * state->joints_state[5].joint[2]));

}

bool Controller::scanDynamixels()
{
    const char* _serial_port = serial_port.c_str();
    result = dxl_wb.init(_serial_port, (uint32_t)serial_baudrate, &log);
    if (result == false) {
        ROS_WARN("Node Error : taticoma_dynamixel_controller : %s", log);
        ROS_WARN("Node Error : taticoma_dynamixel_controller : Failed to init");
    } else {
        ROS_WARN("Node Msg : taticoma_dynamixel_controller : Succeed to init(%d)", serial_baudrate);
    }
    dxl_cnt = 0;
    for (uint8_t num = 0; num < 100; num++) {
        scanned_id[num] = 0;
    }

    ROS_WARN("Node Msg : taticoma_dynamixel_controller : Wait for scan");

    result = dxl_wb.scan(scanned_id, &dxl_cnt, range, &log);
    if (result == false) {
        ROS_WARN("Node Error : taticoma_dynamixel_controller : %s", log);
        ROS_WARN("Node Error : taticoma_dynamixel_controller : Failed to scan");
    } else {
        ROS_WARN("Node Msg : taticoma_fynamixel_controller : Find %d Dynamixels", dxl_cnt);
    }

    if (dxl_cnt == ttcm_dxl_total) {
        for (uint8_t cnt = 0; cnt < dxl_cnt; cnt++) {
            ttcm_dxl_id.push_back(scanned_id[cnt]);
            ROS_WARN("Node Msg : taticoma_dynamixel_controller : %d, Real ID : %d, Model: %s", ttcm_dxl_id[cnt], scanned_id[cnt], dxl_wb.getModelName(scanned_id[cnt]));
        }
        return true;
    } else {
        ROS_WARN("Node Error : taticoma_dynamixel_controller : Failed to find all Servos");
        return false;
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "taticoma_dynamixel_controller");
    Controller Controller;
    ros::spin();
    return 0;
}