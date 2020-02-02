// Generated by gencpp from file taticoma_msgs/LegPositionState.msg
// DO NOT EDIT!


#ifndef TATICOMA_MSGS_MESSAGE_LEGPOSITIONSTATE_H
#define TATICOMA_MSGS_MESSAGE_LEGPOSITIONSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace taticoma_msgs
{
template <class ContainerAllocator>
struct LegPositionState_
{
  typedef LegPositionState_<ContainerAllocator> Type;

  LegPositionState_()
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  LegPositionState_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::taticoma_msgs::LegPositionState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::taticoma_msgs::LegPositionState_<ContainerAllocator> const> ConstPtr;

}; // struct LegPositionState_

typedef ::taticoma_msgs::LegPositionState_<std::allocator<void> > LegPositionState;

typedef boost::shared_ptr< ::taticoma_msgs::LegPositionState > LegPositionStatePtr;
typedef boost::shared_ptr< ::taticoma_msgs::LegPositionState const> LegPositionStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::taticoma_msgs::LegPositionState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace taticoma_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'taticoma_msgs': ['/home/ubuntu/TATICOMA/ROS/src/taticoma_msgs/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::taticoma_msgs::LegPositionState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::taticoma_msgs::LegPositionState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::taticoma_msgs::LegPositionState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const ::taticoma_msgs::LegPositionState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<class ContainerAllocator>
struct DataType< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "taticoma_msgs/LegPositionState";
  }

  static const char* value(const ::taticoma_msgs::LegPositionState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::taticoma_msgs::LegPositionState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LegPositionState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::taticoma_msgs::LegPositionState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::taticoma_msgs::LegPositionState_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TATICOMA_MSGS_MESSAGE_LEGPOSITIONSTATE_H
