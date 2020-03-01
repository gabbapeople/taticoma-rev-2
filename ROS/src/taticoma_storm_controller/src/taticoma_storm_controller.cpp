
#include "taticoma_storm_controller.hpp"

StormController::StormController() {

    teleop_sub = node.subscribe<taticoma_msgs::TeleopCommand>("/teleop_joy", 1, &StormController::teleopCallback, this);

    ros::param::get("/storm_port", _port);
    ros::param::get("/storm_baudrate", _baudrate);

    _serial.setPort(_port);
    _serial.setBaudrate(_baudrate);

    serial::Timeout to = serial::Timeout::simpleTimeout(10);
    _serial.setTimeout(to);
    _serial.open();

    while (true) {
        if (_serial.isOpen()) {
            ROS_WARN("Node Msg : taticoma_storm_controller : Serial Port initialized");
            break;
        } else
            ROS_WARN("Node Error : taticoma_storm_controller: Serial port is not open");
    }

    ROS_WARN("Node Ready : taticoma_storm_controller");
}

void StormController::sendCmdToStorm(uint8_t payloadLen, uint8_t cmd, uint8_t* payload) {
    
    size_t msgLength = 2 + payloadLen;
    uint8_t msg[msgLength];
    uint8_t lo, hi;

    _serial.write(&_header, 1);

    msg[0] = payloadLen;
    msg[1] = cmd;

    if (payloadLen > 0)
        for (uint8_t i = 2; i < msgLength; i++)
            msg[i] = payload[i - 2];

    _serial.write(msg, msgLength);

    uint16_t crc = crc_calculate(msg, msgLength);
    hi = (uint8_t)(crc >> 8);
    lo = (uint8_t)crc;
    _serial.write(&lo, 1);
    _serial.write(&hi, 1);
}

void StormController::setYaw(uint16_t yaw) {
    uint8_t yaw_hi = (uint8_t)(yaw >> 8);
    uint8_t yaw_lo = (uint8_t)yaw;
    uint8_t yawBuff[] = { yaw_lo, yaw_hi };
    sendCmdToStorm(0x02, 0x0C, yawBuff);
}

void StormController::setRoll(uint16_t roll) {
    uint8_t roll_hi = (uint8_t)(roll >> 8);
    uint8_t roll_lo = (uint8_t)roll;
    uint8_t rollBuff[] = { roll_lo, roll_hi };
    sendCmdToStorm(0x02, 0x0B, rollBuff);
}

void StormController::setPitch(uint16_t pitch) {
    uint8_t pitch_hi = (uint8_t)(pitch >> 8);
    uint8_t pitch_lo = (uint8_t)pitch;
    uint8_t pitchBuff[] = { pitch_lo, pitch_hi };
    sendCmdToStorm(0x02, 0x0A, pitchBuff);
}

void StormController::recenter() {
    setPitch(0);
    setRoll(0);
    setYaw(0);
}

uint16_t map(double x) {
    return (3000 + 1600 * x) / 2;
}

void StormController::teleopCallback(const taticoma_msgs::TeleopCommand::ConstPtr& teleop) {
    switch (teleop->mode) {
    case MODE_CAMERA:

        if (teleop->p_buttons[R1] == 1)
            if (_roll != 0 || _pitch != 0 || _yaw != 0)
                recenter();

        if (teleop->p_buttons[L1] == 1 && teleop->p_buttons[R1] == 0) {
            _yaw = map(teleop->axes[RX]);
            setYaw(_yaw);
            ROS_WARN("%d", _yaw);
        }
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "taticoma_storm_controller");
    StormController stormController;
    ros::spin();
}
