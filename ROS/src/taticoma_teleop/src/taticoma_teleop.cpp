#include "taticoma_teleop.hpp"

Teleop::Teleop() {
    node.param("clearance", _z, 0.0);
    node.param("leg_radius", _leg_radius, 0.0);

    body_state.leg_radius = _leg_radius;
    body_state.z = -_z;

    teleop_sub = node.subscribe<taticoma_msgs::TeleopCommand>("/teleop_joy", 1, &Teleop::teleopCallback, this);

    body_cmd_pub = node.advertise<taticoma_msgs::BodyCommand>("/teleop/body_command", 1);
    gait_cmd_pub = node.advertise<taticoma_msgs::GaitCommand>("/teleop/gait_control", 1);
    move_body_pub = node.advertise<taticoma_msgs::BodyState>("/teleop/move_body", 1);

    ROS_WARN("Node Ready : taticoma_teleop");
}

void Teleop::teleopCallback(const taticoma_msgs::TeleopCommand::ConstPtr& teleop) {

    switch (teleop->mode) {
    case MODE_MOVEMENT:

        double K_ROLL = 0.22;
        double K_PITCH = -0.22;
        double K_YAW = 0.28;

        if (teleop->a_buttons[L2] > 0) {
            body_state.roll = K_ROLL * teleop->axes[LY];
            body_state.pitch = K_PITCH * teleop->axes[LX];
            body_state.yaw = K_YAW * teleop->axes[RX];
            move_body_pub.publish(body_state);
        }

        double K_Z_DOWN = 0.052;
        double K_Z_UP = 0.082;
        double K_XY = 0.05;

        if (teleop->a_buttons[R2] > 0) {
            body_state.y = -1 * K_XY * teleop->axes[LY];
            body_state.x = -1 * K_XY * teleop->axes[LX];
            if (teleop->axes[RY] < 0) {
                body_state.z = (-1 * K_Z_DOWN * teleop->axes[RY]) - _z;
            } else {
                body_state.z = (-1 * K_Z_UP * teleop->axes[RY]) - _z;
            }
            move_body_pub.publish(body_state);
        }

        if (teleop->p_buttons[L1] == 1) {
            if (teleop->axes[LX] != 0 || teleop->axes[LY] != 0) {

                switch (teleop->gait_mode) {
                case TRIPOD:
                    gait_command.cmd = gait_command.RUNTRIPOD;
                    break;
                case RIPPLE:
                    gait_command.cmd = gait_command.RUNRIPPLE;
                    break;
                }

                float a, b, xinv;
                a = pow(teleop->axes[LY], 2);
                b = pow(teleop->axes[LX], 2);
                xinv = 1 * teleop->axes[LX];

                gait_command.fi = atan2(teleop->axes[LY], xinv);
                gait_command.scale = pow(a + b, 0.5) > 1 ? 1 : pow(a + b, 0.5);
                gait_command.alpha = 0;
            }

            if (teleop->axes[RX] != 0 || teleop->axes[RY] != 0) {

                switch (teleop->gait_mode) {
                case TRIPOD:
                    gait_command.cmd = gait_command.RUNTRIPOD;
                    break;
                case RIPPLE:
                    gait_command.cmd = gait_command.RUNRIPPLE;
                    break;
                }

                gait_command.fi = (teleop->axes[RY] >= 0) ? 3.14 / 2 : -3.14 / 2;
                gait_command.scale = teleop->axes[RY];
                if (gait_command.scale < 0)
                    gait_command.scale *= -1;
                gait_command.alpha = ((teleop->axes[RX] >= 0) ? -1 : 1) * 0.065 * (1 - gait_command.scale) + 0.19 * -1 * teleop->axes[RX];

                ROS_WARN("fi: %f scale: %f alpha: %f", gait_command.fi, gait_command.scale, gait_command.alpha);
            }

            gait_cmd_pub.publish(gait_command);
        }

        if (teleop->p_buttons[L1] == 0) {
            gait_command.cmd = gait_command.PAUSE;
            gait_cmd_pub.publish(gait_command);
        }

        break;
    }

}

int main(int argc, char** argv) {
    ros::init(argc, argv, "taticoma_teleop");
    Teleop teleop;
    ros::spin();
}
