
#ifndef TATICOMA_TELEOP_SERIAL_HPP_
#define TATICOMA_TELEOP_SERIAL_HPP_

#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include "taticoma_msgs/TeleopCommand.h"

#define CHECKSUM 0x10
#define FEEDBACK 0x20
#define HEADER 0x71

#define CMD_OPTIONS 0x68
#define CMD_CHANGE_HAT_LX 0x80
#define CMD_CHANGE_HAT_LY 0x81
#define CMD_CHANGE_HAT_RX 0x82
#define CMD_CHANGE_HAT_RY 0x83
#define CMD_CHANGE_L2 0x84
#define CMD_CHANGE_R2 0x85
#define CMD_CHANGE_L1 0x86
#define CMD_CHANGE_R1 0x87
#define CMD_CHANGE_TRIANGLE 0x88

#define FEED_MODE 0x58
#define FEED_GAIT_MODE 0x59

#define MSG_BUFFER_SIZE 2

class TeleopSerial
{
public:

	TeleopSerial();
    
private:

	ros::NodeHandle node;

    ros::Timer timer; 

    taticoma_msgs::TeleopCommand teleop_command;

    ros::Publisher teleop_joy_pub;

    serial::Serial _serial;

    struct Msg {
        uint8_t cmd;
        uint8_t data;
    };

    Msg outputMsgBuffer[MSG_BUFFER_SIZE];
    uint8_t counter;

    uint8_t _byte;
    uint16_t sendChecksum;
    uint16_t readChecksum;
    uint8_t originalChecksum;

    bool receiveFlag;

    double in_min = 0.0;
    double in_max = 255.0;
    double out_min = -1.0;
    double out_max = 1.0;

    uint8_t options_mem = 0;
    uint8_t lx_mem = 127;
    uint8_t ly_mem = 127;
    uint8_t rx_mem = 127;
    uint8_t ry_mem = 127;
    uint8_t l2_mem = 0;
    uint8_t r2_mem = 0;
    uint8_t l1_mem = 0;
    uint8_t r1_mem = 0;
    uint8_t triangle_mem = 0;
    
    uint8_t mode = 0;
    uint8_t gait_mode = 0;

    uint8_t* sendBuffer3;
    uint8_t* readBuffer3;

    double map(double x);

    void setBuffers();
    void firstPublish();

    uint8_t* prepareSimpleMsg3Bytes(uint8_t* buffer, uint8_t cmd, uint8_t data);

    bool readMsg();
    void sendMsg(uint8_t feed, uint8_t data);

    void parseMsg(uint8_t cmd, uint8_t data);

    void scanData();
    void scanData(const ros::TimerEvent&);

};

#endif /* TATICOMA_TELEOP_SERIAL_HPP_ */