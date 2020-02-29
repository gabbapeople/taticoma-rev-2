// Generated by gencpp from file taticoma_msgs/LegIKRequest.msg
// DO NOT EDIT!

#ifndef TATICOMA_MSGS_MESSAGE_LEGIKREQUEST_H
#define TATICOMA_MSGS_MESSAGE_LEGIKREQUEST_H

#include <map>
#include <string>
#include <vector>

#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>
#include <ros/serialization.h>
#include <ros/types.h>

#include <taticoma_msgs/LegJointsState.h>
#include <taticoma_msgs/LegPositionState.h>

namespace taticoma_msgs {
template <class ContainerAllocator>
struct LegIKRequest_ {
    typedef LegIKRequest_<ContainerAllocator> Type;

    LegIKRequest_()
        : leg_number(0)
        , current_joints()
        , target_position() {
    }
    LegIKRequest_(const ContainerAllocator& _alloc)
        : leg_number(0)
        , current_joints(_alloc)
        , target_position(_alloc) {
        (void)_alloc;
    }

    typedef int32_t _leg_number_type;
    _leg_number_type leg_number;

    typedef ::taticoma_msgs::LegJointsState_<ContainerAllocator> _current_joints_type;
    _current_joints_type current_joints;

    typedef ::taticoma_msgs::LegPositionState_<ContainerAllocator> _target_position_type;
    _target_position_type target_position;

    typedef boost::shared_ptr<::taticoma_msgs::LegIKRequest_<ContainerAllocator>> Ptr;
    typedef boost::shared_ptr<::taticoma_msgs::LegIKRequest_<ContainerAllocator> const> ConstPtr;

}; // struct LegIKRequest_

typedef ::taticoma_msgs::LegIKRequest_<std::allocator<void>> LegIKRequest;

typedef boost::shared_ptr<::taticoma_msgs::LegIKRequest> LegIKRequestPtr;
typedef boost::shared_ptr<::taticoma_msgs::LegIKRequest const> LegIKRequestConstPtr;

// constants requiring out of line definition

template <typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::taticoma_msgs::LegIKRequest_<ContainerAllocator>& v) {
    ros::message_operations::Printer<::taticoma_msgs::LegIKRequest_<ContainerAllocator>>::stream(s, "", v);
    return s;
}

} // namespace taticoma_msgs

namespace ros {
namespace message_traits {

    // BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
    // {'taticoma_msgs': ['/home/ubuntu/taticoma-rev-2/ROS/src/taticoma_msgs/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

    // !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

    template <class ContainerAllocator>
    struct IsFixedSize<::taticoma_msgs::LegIKRequest_<ContainerAllocator>>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsFixedSize<::taticoma_msgs::LegIKRequest_<ContainerAllocator> const>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsMessage<::taticoma_msgs::LegIKRequest_<ContainerAllocator>>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsMessage<::taticoma_msgs::LegIKRequest_<ContainerAllocator> const>
        : TrueType {};

    template <class ContainerAllocator>
    struct HasHeader<::taticoma_msgs::LegIKRequest_<ContainerAllocator>>
        : FalseType {};

    template <class ContainerAllocator>
    struct HasHeader<::taticoma_msgs::LegIKRequest_<ContainerAllocator> const>
        : FalseType {};

    template <class ContainerAllocator>
    struct MD5Sum<::taticoma_msgs::LegIKRequest_<ContainerAllocator>> {
        static const char* value() {
            return "bcb4917a6750a0f98ecbb5e98212cbec";
        }

        static const char* value(const ::taticoma_msgs::LegIKRequest_<ContainerAllocator>&) { return value(); }
        static const uint64_t static_value1 = 0xbcb4917a6750a0f9ULL;
        static const uint64_t static_value2 = 0x8ecbb5e98212cbecULL;
    };

    template <class ContainerAllocator>
    struct DataType<::taticoma_msgs::LegIKRequest_<ContainerAllocator>> {
        static const char* value() {
            return "taticoma_msgs/LegIKRequest";
        }

        static const char* value(const ::taticoma_msgs::LegIKRequest_<ContainerAllocator>&) { return value(); }
    };

    template <class ContainerAllocator>
    struct Definition<::taticoma_msgs::LegIKRequest_<ContainerAllocator>> {
        static const char* value() {
            return "int32 leg_number\n"
                   "taticoma_msgs/LegJointsState current_joints\n"
                   "taticoma_msgs/LegPositionState target_position\n"
                   "\n"
                   "================================================================================\n"
                   "MSG: taticoma_msgs/LegJointsState\n"
                   "float64[3] joint\n"
                   "\n"
                   "================================================================================\n"
                   "MSG: taticoma_msgs/LegPositionState\n"
                   "float64 x\n"
                   "float64 y\n"
                   "float64 z\n";
        }

        static const char* value(const ::taticoma_msgs::LegIKRequest_<ContainerAllocator>&) { return value(); }
    };

} // namespace message_traits
} // namespace ros

namespace ros {
namespace serialization {

    template <class ContainerAllocator>
    struct Serializer<::taticoma_msgs::LegIKRequest_<ContainerAllocator>> {
        template <typename Stream, typename T>
        inline static void allInOne(Stream& stream, T m) {
            stream.next(m.leg_number);
            stream.next(m.current_joints);
            stream.next(m.target_position);
        }

        ROS_DECLARE_ALLINONE_SERIALIZER
    }; // struct LegIKRequest_

} // namespace serialization
} // namespace ros

namespace ros {
namespace message_operations {

    template <class ContainerAllocator>
    struct Printer<::taticoma_msgs::LegIKRequest_<ContainerAllocator>> {
        template <typename Stream>
        static void stream(Stream& s, const std::string& indent, const ::taticoma_msgs::LegIKRequest_<ContainerAllocator>& v) {
            s << indent << "leg_number: ";
            Printer<int32_t>::stream(s, indent + "  ", v.leg_number);
            s << indent << "current_joints: ";
            s << std::endl;
            Printer<::taticoma_msgs::LegJointsState_<ContainerAllocator>>::stream(s, indent + "  ", v.current_joints);
            s << indent << "target_position: ";
            s << std::endl;
            Printer<::taticoma_msgs::LegPositionState_<ContainerAllocator>>::stream(s, indent + "  ", v.target_position);
        }
    };

} // namespace message_operations
} // namespace ros

#endif // TATICOMA_MSGS_MESSAGE_LEGIKREQUEST_H
