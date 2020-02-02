
#ifndef TATICOMA_DYNAMIXEL_CONTROLLER_HPP_
#define TATICOMA_DYNAMIXEL_CONTROLLER_HPP_


#include "taticoma_msgs/LegsJointsState.h"
#include <dynamixel_workbench_toolbox/dynamixel_workbench.h>
#include <ros/ros.h>
#include <string.h>

typedef boost::shared_ptr<taticoma_msgs::LegsJointsState const> LegsStateConstPtr;

class Controller {
public:
    Controller();
private:
    ros::NodeHandle node;
    
    ros::Subscriber ttcm_dxl_pos_sub;

    DynamixelWorkbench dxl_wb;

    std::string serial_port;
    int32_t serial_baudrate;

    const char* log;
    bool result = false;

    uint8_t scanned_id[100];
    uint8_t range = 50;
    uint8_t dxl_cnt = 0;

    static const uint8_t num_joints = 3;
    static const uint8_t num_legs = 6;
    static const uint8_t ttcm_dxl_total = num_legs * num_joints;

    double in_min = -1.657;
    double in_max = 1.657;
    double out_min = 186.0;
    double out_max = 840.0;
    
    std::vector<uint8_t> ttcm_dxl_id;

    double target_pos[ttcm_dxl_total];
    const int8_t rotation_direction_leg[ttcm_dxl_total] = {
        -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1,
    };

    double map(double x);

    bool scanDynamixels();
    //void moveAlltoMidPos();
    void setLedsOn();
    void setMovingSpeed();

    void chatterLegsState(const LegsStateConstPtr& state);
    //void chatterLegsState(const taticoma_msgs::LegsJointsStateConstPtr& legs_jnts);
};

#endif /* TATICOMA_DYNAMIXEL_CONTROLLER_HPP_ */
