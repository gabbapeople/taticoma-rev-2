// Generated by gencpp from file taticoma_msgs/BodyCommand.msg
// DO NOT EDIT!

#ifndef TATICOMA_MSGS_MESSAGE_BODYCOMMAND_H
#define TATICOMA_MSGS_MESSAGE_BODYCOMMAND_H

#include <map>
#include <string>
#include <vector>

#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>
#include <ros/serialization.h>
#include <ros/types.h>

namespace taticoma_msgs {
template <class ContainerAllocator>
struct BodyCommand_ {
    typedef BodyCommand_<ContainerAllocator> Type;

    BodyCommand_()
        : cmd(0) {
    }
    BodyCommand_(const ContainerAllocator& _alloc)
        : cmd(0) {
        (void)_alloc;
    }

    typedef int32_t _cmd_type;
    _cmd_type cmd;

    enum {
        STAND_UP_CMD = 1,
        SEAT_DOWN_CMD = 2,
        IMU_START_CMD = 3,
        IMU_STOP_CMD = 4,
    };

    typedef boost::shared_ptr<::taticoma_msgs::BodyCommand_<ContainerAllocator>> Ptr;
    typedef boost::shared_ptr<::taticoma_msgs::BodyCommand_<ContainerAllocator> const> ConstPtr;

}; // struct BodyCommand_

typedef ::taticoma_msgs::BodyCommand_<std::allocator<void>> BodyCommand;

typedef boost::shared_ptr<::taticoma_msgs::BodyCommand> BodyCommandPtr;
typedef boost::shared_ptr<::taticoma_msgs::BodyCommand const> BodyCommandConstPtr;

// constants requiring out of line definition

template <typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::taticoma_msgs::BodyCommand_<ContainerAllocator>& v) {
    ros::message_operations::Printer<::taticoma_msgs::BodyCommand_<ContainerAllocator>>::stream(s, "", v);
    return s;
}

} // namespace taticoma_msgs

namespace ros {
namespace message_traits {

    // BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
    // {'taticoma_msgs': ['/home/ubuntu/taticoma-rev-2/ROS/src/taticoma_msgs/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

    // !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

    template <class ContainerAllocator>
    struct IsFixedSize<::taticoma_msgs::BodyCommand_<ContainerAllocator>>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsFixedSize<::taticoma_msgs::BodyCommand_<ContainerAllocator> const>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsMessage<::taticoma_msgs::BodyCommand_<ContainerAllocator>>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsMessage<::taticoma_msgs::BodyCommand_<ContainerAllocator> const>
        : TrueType {};

    template <class ContainerAllocator>
    struct HasHeader<::taticoma_msgs::BodyCommand_<ContainerAllocator>>
        : FalseType {};

    template <class ContainerAllocator>
    struct HasHeader<::taticoma_msgs::BodyCommand_<ContainerAllocator> const>
        : FalseType {};

    template <class ContainerAllocator>
    struct MD5Sum<::taticoma_msgs::BodyCommand_<ContainerAllocator>> {
        static const char* value() {
            return "1abfa573ddc640038a45f99b26d93a23";
        }

        static const char* value(const ::taticoma_msgs::BodyCommand_<ContainerAllocator>&) { return value(); }
        static const uint64_t static_value1 = 0x1abfa573ddc64003ULL;
        static const uint64_t static_value2 = 0x8a45f99b26d93a23ULL;
    };

    template <class ContainerAllocator>
    struct DataType<::taticoma_msgs::BodyCommand_<ContainerAllocator>> {
        static const char* value() {
            return "taticoma_msgs/BodyCommand";
        }

        static const char* value(const ::taticoma_msgs::BodyCommand_<ContainerAllocator>&) { return value(); }
    };

    template <class ContainerAllocator>
    struct Definition<::taticoma_msgs::BodyCommand_<ContainerAllocator>> {
        static const char* value() {
            return "int32 cmd\n"
                   "\n"
                   "int32 STAND_UP_CMD=1\n"
                   "int32 SEAT_DOWN_CMD=2\n"
                   "int32 IMU_START_CMD=3\n"
                   "int32 IMU_STOP_CMD=4\n"
                   "\n";
        }

        static const char* value(const ::taticoma_msgs::BodyCommand_<ContainerAllocator>&) { return value(); }
    };

} // namespace message_traits
} // namespace ros

namespace ros {
namespace serialization {

    template <class ContainerAllocator>
    struct Serializer<::taticoma_msgs::BodyCommand_<ContainerAllocator>> {
        template <typename Stream, typename T>
        inline static void allInOne(Stream& stream, T m) {
            stream.next(m.cmd);
        }

        ROS_DECLARE_ALLINONE_SERIALIZER
    }; // struct BodyCommand_

} // namespace serialization
} // namespace ros

namespace ros {
namespace message_operations {

    template <class ContainerAllocator>
    struct Printer<::taticoma_msgs::BodyCommand_<ContainerAllocator>> {
        template <typename Stream>
        static void stream(Stream& s, const std::string& indent, const ::taticoma_msgs::BodyCommand_<ContainerAllocator>& v) {
            s << indent << "cmd: ";
            Printer<int32_t>::stream(s, indent + "  ", v.cmd);
        }
    };

} // namespace message_operations
} // namespace ros

#endif // TATICOMA_MSGS_MESSAGE_BODYCOMMAND_H
