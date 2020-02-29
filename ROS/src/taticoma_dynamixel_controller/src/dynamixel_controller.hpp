
#ifndef DYNAMIXEL_CONTROLLER_HPP_
#define DYNAMIXEL_CONTROLLER_HPP_

#include "std_msgs/Float64.h"
#include "taticoma_msgs/LegsJointsState.h"
#include <ros/ros.h>
#include <termios.h>
#include <vector>

class Controller {
public:
    Controller();

    const static unsigned int num_joints = 3;
    const static unsigned int num_legs = 6;

private:
    const int rotation_direction_leg[18] = { -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1 };
    double target_pos[18];

    ros::NodeHandle node;
    ros::Subscriber dynamixel_pos_sub;
    std::vector<ros::Publisher> dynamixel_pos_pub;

    std_msgs::Float64 pos_msg;

    void chatterLegsState(const taticoma_msgs::LegsJointsStateConstPtr& legs_jnts);
};

#endif /* DYNAMIXEL_CONTROLLER_HPP_ */
