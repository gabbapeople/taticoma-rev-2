
#ifndef TATICOMA_TELEOP_HPP_
#define TATICOMA_TELEOP_HPP_

#include <ros/ros.h>

#include "taticoma_msgs/BodyCommand.h"
#include "taticoma_msgs/BodyState.h"
#include "taticoma_msgs/GaitCommand.h"

#include "taticoma_msgs/TeleopCommand.h"

#define LX 0
#define LY 1
#define RX 2
#define RY 3

#define L1 0
#define R1 1

#define L2 0
#define R2 1

#define RIPPLE 0
#define TRIPOD 1

#define MODE_0 0
#define MODE_1 1
#define MODE_2 2
#define MODE_MOVEMENT 3

class Teleop {
public:
    Teleop();

private:
    ros::NodeHandle node;

    taticoma_msgs::BodyState body_state;
    taticoma_msgs::BodyCommand body_command;
    taticoma_msgs::GaitCommand gait_command;

    taticoma_msgs::TeleopCommand teleop_command;

    ros::Subscriber teleop_sub;

    ros::Publisher move_body_pub;
    ros::Publisher body_cmd_pub;
    ros::Publisher gait_cmd_pub;

    double _z;
    double _leg_radius;

    void teleopCallback(const taticoma_msgs::TeleopCommand::ConstPtr& teleop);
};

#endif /* TATICOMA_TELEOP_HPP_ */
