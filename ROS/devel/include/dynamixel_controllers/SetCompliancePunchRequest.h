// Generated by gencpp from file dynamixel_controllers/SetCompliancePunchRequest.msg
// DO NOT EDIT!

#ifndef DYNAMIXEL_CONTROLLERS_MESSAGE_SETCOMPLIANCEPUNCHREQUEST_H
#define DYNAMIXEL_CONTROLLERS_MESSAGE_SETCOMPLIANCEPUNCHREQUEST_H

#include <map>
#include <string>
#include <vector>

#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>
#include <ros/serialization.h>
#include <ros/types.h>

namespace dynamixel_controllers {
template <class ContainerAllocator>
struct SetCompliancePunchRequest_ {
    typedef SetCompliancePunchRequest_<ContainerAllocator> Type;

    SetCompliancePunchRequest_()
        : punch(0) {
    }
    SetCompliancePunchRequest_(const ContainerAllocator& _alloc)
        : punch(0) {
        (void)_alloc;
    }

    typedef uint8_t _punch_type;
    _punch_type punch;

    typedef boost::shared_ptr<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>> Ptr;
    typedef boost::shared_ptr<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetCompliancePunchRequest_

typedef ::dynamixel_controllers::SetCompliancePunchRequest_<std::allocator<void>> SetCompliancePunchRequest;

typedef boost::shared_ptr<::dynamixel_controllers::SetCompliancePunchRequest> SetCompliancePunchRequestPtr;
typedef boost::shared_ptr<::dynamixel_controllers::SetCompliancePunchRequest const> SetCompliancePunchRequestConstPtr;

// constants requiring out of line definition

template <typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>& v) {
    ros::message_operations::Printer<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>>::stream(s, "", v);
    return s;
}

} // namespace dynamixel_controllers

namespace ros {
namespace message_traits {

    // BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
    // {}

    // !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

    template <class ContainerAllocator>
    struct IsFixedSize<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsFixedSize<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator> const>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsMessage<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>>
        : TrueType {};

    template <class ContainerAllocator>
    struct IsMessage<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator> const>
        : TrueType {};

    template <class ContainerAllocator>
    struct HasHeader<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>>
        : FalseType {};

    template <class ContainerAllocator>
    struct HasHeader<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator> const>
        : FalseType {};

    template <class ContainerAllocator>
    struct MD5Sum<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>> {
        static const char* value() {
            return "6f1db06d3f143058321215213d1c3bef";
        }

        static const char* value(const ::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>&) { return value(); }
        static const uint64_t static_value1 = 0x6f1db06d3f143058ULL;
        static const uint64_t static_value2 = 0x321215213d1c3befULL;
    };

    template <class ContainerAllocator>
    struct DataType<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>> {
        static const char* value() {
            return "dynamixel_controllers/SetCompliancePunchRequest";
        }

        static const char* value(const ::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>&) { return value(); }
    };

    template <class ContainerAllocator>
    struct Definition<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>> {
        static const char* value() {
            return "\n"
                   "\n"
                   "uint8 punch\n";
        }

        static const char* value(const ::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>&) { return value(); }
    };

} // namespace message_traits
} // namespace ros

namespace ros {
namespace serialization {

    template <class ContainerAllocator>
    struct Serializer<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>> {
        template <typename Stream, typename T>
        inline static void allInOne(Stream& stream, T m) {
            stream.next(m.punch);
        }

        ROS_DECLARE_ALLINONE_SERIALIZER
    }; // struct SetCompliancePunchRequest_

} // namespace serialization
} // namespace ros

namespace ros {
namespace message_operations {

    template <class ContainerAllocator>
    struct Printer<::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>> {
        template <typename Stream>
        static void stream(Stream& s, const std::string& indent, const ::dynamixel_controllers::SetCompliancePunchRequest_<ContainerAllocator>& v) {
            s << indent << "punch: ";
            Printer<uint8_t>::stream(s, indent + "  ", v.punch);
        }
    };

} // namespace message_operations
} // namespace ros

#endif // DYNAMIXEL_CONTROLLERS_MESSAGE_SETCOMPLIANCEPUNCHREQUEST_H
