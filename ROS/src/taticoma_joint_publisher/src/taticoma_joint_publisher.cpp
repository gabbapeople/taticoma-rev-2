
#include "ros/ros.h"
#include <sensor_msgs/JointState.h>

#include "taticoma_msgs/LegsJointsState.h"

typedef boost::shared_ptr<taticoma_msgs::LegsJointsState const> LegsStateConstPtr;

const std::string suffixes[6] = { "_r1", "_r2", "_r3", "_l1", "_l2", "_l3" };
const std::string names[3] = { "coha_joint", "femur_joint", "tibia_joint" };

ros::Publisher joint_msg_pub;
ros::Subscriber sub;

sensor_msgs::JointState joint_msg;

void chatterLegsState(const LegsStateConstPtr& state) {
    std::string joint_name;
    for (int name = 0; name < 3; name++) {
        for (int suf = 0; suf < 6; suf++) {
            joint_name = names[name] + suffixes[suf];
            joint_msg.name.push_back(joint_name.c_str());
            joint_msg.position.push_back(state->joints_state[suf].joint[name]);
        }
    }
    joint_msg_pub.publish(joint_msg);
    joint_msg.name.clear();
    joint_msg.position.clear();
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "taticoma_joint_publisher");
    ros::NodeHandle node;
    ROS_WARN("Node Ready : taticoma_joint_publisher");

    joint_msg_pub = node.advertise<sensor_msgs::JointState>("taticoma_joint_publisher", 1);
    sub = node.subscribe("/taticoma_joints_to_controller", 1, chatterLegsState);

    //	ros::Rate loop_rate(30);

    ros::spin();

    return 0;
}