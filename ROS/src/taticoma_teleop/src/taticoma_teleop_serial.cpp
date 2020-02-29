#include "taticoma_teleop_serial.hpp"

TeleopSerial::TeleopSerial() {
    teleop_joy_pub = node.advertise<taticoma_msgs::TeleopCommand>("/teleop_joy", 1);

    // timer = node.createTimer(ros::Rate(100), &TeleopSerial::scanData, this);

    _serial.setPort("/dev/ttyUSB0");
    _serial.setBaudrate(115200);
    serial::Timeout to = serial::Timeout::simpleTimeout(10);
    _serial.setTimeout(to);
    _serial.open();

    while (true) {
        if (_serial.isOpen()) {
            ROS_WARN("Node Msg : taticoma_teleop_command : Serial Port initialized");
            break;
        } else
            ROS_WARN("Node Error : taticoma_teleop_command : Serial port is not open");
    }

    firstPublish();
    setBuffers();

    receiveFlag = false;
    counter = 0;

    ROS_WARN("Node Ready : taticoma_teleop_command");

    scanData();
}

void TeleopSerial::firstPublish() {
    teleop_command.buttons[0] = options_mem;
    teleop_command.axes[0] = map((double)lx_mem);
    teleop_command.axes[1] = -1 * map((double)ly_mem);
    teleop_command.axes[2] = map((double)rx_mem);
    teleop_command.axes[3] = -1 * map((double)ry_mem);
    teleop_command.a_buttons[0] = (1 / 255.0f * (float)l2_mem);
    teleop_command.a_buttons[1] = (1 / 255.0f * (float)r2_mem);
    teleop_command.p_buttons[0] = l1_mem;
    teleop_command.p_buttons[1] = r1_mem;
    teleop_command.buttons[1] = triangle_mem;

    teleop_command.mode = mode;
    teleop_command.gait_mode = gait_mode;

    teleop_joy_pub.publish(teleop_command);
}

double TeleopSerial::map(double x) {
    if (x == 127.0f) {
        return 0;
    } else {
        return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
    }
}

void TeleopSerial::setBuffers() {
    sendBuffer3 = new uint8_t[3 * sizeof(uint8_t)];
    memset(sendBuffer3, 0, 3 * sizeof(uint8_t));
    readBuffer3 = new uint8_t[3 * sizeof(uint8_t)];
    memset(readBuffer3, 0, 3 * sizeof(uint8_t));

    for (uint16_t i = 0; i < MSG_BUFFER_SIZE; i++) {
        outputMsgBuffer[i].data = 0;
    }

    outputMsgBuffer[0].cmd = FEED_MODE;
    outputMsgBuffer[1].cmd = FEED_GAIT_MODE;
}

uint8_t* TeleopSerial::prepareSimpleMsg3Bytes(uint8_t* buffer, uint8_t cmd, uint8_t data) {
    sendChecksum = 0;
    buffer[0] = cmd;
    buffer[1] = data;
    sendChecksum += buffer[0];
    sendChecksum += buffer[1];
    buffer[2] = sendChecksum & CHECKSUM;
    return buffer;
}

void TeleopSerial::sendMsg(uint8_t feed, uint8_t data) {
    sendBuffer3 = prepareSimpleMsg3Bytes(sendBuffer3, feed, data);
    uint8_t _sendByte = FEEDBACK;
    _serial.write(&_sendByte, 1);
    _serial.write(sendBuffer3, 3);
}

void TeleopSerial::parseMsg(uint8_t cmd, uint8_t data) {
    if (cmd == CMD_OPTIONS) {
        if (options_mem != data) {
            options_mem = data;
            mode = mode + 1;
            if (mode == 4)
                mode = 0;
        }

        teleop_command.buttons[0] = options_mem;
        teleop_command.mode = mode;
        teleop_joy_pub.publish(teleop_command);

        outputMsgBuffer[0].cmd = FEED_MODE;
        outputMsgBuffer[0].data = mode;
    }

    if (cmd == CMD_CHANGE_TRIANGLE) {

        if (triangle_mem != data) {
            triangle_mem = data;
            if (mode == 3) {
                gait_mode = !gait_mode;
            }
        }

        teleop_command.buttons[1] = triangle_mem;
        teleop_command.gait_mode = gait_mode;
        teleop_joy_pub.publish(teleop_command);

        outputMsgBuffer[1].cmd = FEED_GAIT_MODE;
        outputMsgBuffer[1].data = gait_mode;
    }

    if (cmd == CMD_CHANGE_HAT_LX) {
        lx_mem = data;
        teleop_command.axes[0] = map((double)lx_mem);
        //teleop_command.axes[0] = lx_mem;
        teleop_joy_pub.publish(teleop_command);
    }

    if (cmd == CMD_CHANGE_HAT_LY) {
        ly_mem = data;
        teleop_command.axes[1] = -1 * map((double)ly_mem);
        //teleop_command.axes[1] = ly_mem;
        teleop_joy_pub.publish(teleop_command);
    }

    if (cmd == CMD_CHANGE_HAT_RX) {
        rx_mem = data;
        teleop_command.axes[2] = map((double)rx_mem);
        //teleop_command.axes[2] = rx_mem;
        teleop_joy_pub.publish(teleop_command);
    }

    if (cmd == CMD_CHANGE_HAT_RY) {
        ry_mem = data;
        teleop_command.axes[3] = -1 * map((double)ry_mem);
        //teleop_command.axes[3] = ry_mem;
        teleop_joy_pub.publish(teleop_command);
    }

    if (cmd == CMD_CHANGE_L2) {
        l2_mem = data;
        teleop_command.a_buttons[0] = (1 / 255.0f * (float)l2_mem);
        //teleop_command.a_buttons[0] = l2_mem;
        teleop_joy_pub.publish(teleop_command);
    }

    if (cmd == CMD_CHANGE_R2) {
        r2_mem = data;
        teleop_command.a_buttons[1] = (1 / 255.0f * (float)r2_mem);
        //teleop_command.a_buttons[1] = r2_mem;
        teleop_joy_pub.publish(teleop_command);
    }

    if (cmd == CMD_CHANGE_L1) {
        l1_mem = data;
        teleop_command.p_buttons[0] = l1_mem;
        teleop_joy_pub.publish(teleop_command);
    }
    if (cmd == CMD_CHANGE_R1) {
        r1_mem = data;
        teleop_command.p_buttons[1] = r1_mem;
        teleop_joy_pub.publish(teleop_command);
    }
}

bool TeleopSerial::readMsg() {
    _serial.read(readBuffer3, 3);
    readChecksum = 0;
    originalChecksum = readBuffer3[2];
    readChecksum += readBuffer3[0];
    readChecksum += readBuffer3[1];
    uint8_t result = readChecksum & CHECKSUM;
    if (originalChecksum == result) {
        parseMsg(readBuffer3[0], readBuffer3[1]);
        // ROS_WARN("GOOD PACKAGE");
        return true;
    } else {
        // ROS_WARN("BAD PACKAGE");
        return false;
    }
}

void TeleopSerial::scanData(const ros::TimerEvent&) {}
//void TeleopSerial::scanData() {}

void TeleopSerial::scanData() {
    //ros::Rate sleep_rate(100000);

    while (ros::ok) {
        if (receiveFlag == false) {

            if (_serial.available()) {
                _serial.read(&_byte, 1);

                if (_byte == HEADER) {
                    //ROS_WARN("READ");
                    if (readMsg()) {
                        receiveFlag = true;
                    }
                }
            }
        }

        if (receiveFlag == true) {
            switch (counter) {
            case 0:
                sendMsg(outputMsgBuffer[0].cmd, outputMsgBuffer[0].data);
                counter++;
                receiveFlag = false;
                break;
            case 1:
                sendMsg(outputMsgBuffer[1].cmd, outputMsgBuffer[1].data);
                counter++;
                receiveFlag = false;
                break;
            case MSG_BUFFER_SIZE:
                counter = 0;
                break;
            }
        }
        //sleep_rate.sleep();
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "taticoma_teleop_command");
    TeleopSerial teleopSerial;
    ros::spin();
    return 0;
}
