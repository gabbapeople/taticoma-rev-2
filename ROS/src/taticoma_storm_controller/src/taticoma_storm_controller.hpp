
#ifndef TATICOMA_STORM_CONTROLLER_HPP_
#define TATICOMA_STORM_CONTROLLER_HPP_

#include "taticoma_msgs/TeleopCommand.h"

#include <ros/ros.h>
#include <serial/serial.h>
#include "checksum.h"

#define LX 0
#define LY 1
#define RX 2
#define RY 3

#define L1 0
#define R1 1

#define L2 0
#define R2 1

#define MODE_0 0
#define MODE_1 1
#define MODE_CAMERA 2
#define MODE_MOVEMENT 3

class StormController {
public:
    StormController();

private:

    std::string _port;
    int _baudrate;

    uint16_t _yaw = 0;
    uint16_t _roll = 0;
    uint16_t _pitch = 0;

    const uint8_t _header = 0xFA;
    
    ros::NodeHandle node;
    ros::Subscriber teleop_sub;

    serial::Serial _serial;

    void setYaw(uint16_t yaw);
    void setRoll(uint16_t roll);
    void setPitch(uint16_t pitch);

    void recenter(); 

    void sendCmdToStorm(uint8_t payloadLen, uint8_t cmd, uint8_t* payload = nullptr);
    void teleopCallback(const taticoma_msgs::TeleopCommand::ConstPtr& teleop);
};

#endif // TATICOMA_STORM_CONTROLLER_HPP_
