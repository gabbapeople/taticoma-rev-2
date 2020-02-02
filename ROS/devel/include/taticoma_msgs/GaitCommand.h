// Generated by gencpp from file taticoma_msgs/GaitCommand.msg
// DO NOT EDIT!


#ifndef TATICOMA_MSGS_MESSAGE_GAITCOMMAND_H
#define TATICOMA_MSGS_MESSAGE_GAITCOMMAND_H


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
struct GaitCommand_
{
  typedef GaitCommand_<ContainerAllocator> Type;

  GaitCommand_()
    : cmd(0)
    , fi(0.0)
    , velocity(0.0)
    , alpha(0.0)
    , scale(0.0)  {
    }
  GaitCommand_(const ContainerAllocator& _alloc)
    : cmd(0)
    , fi(0.0)
    , velocity(0.0)
    , alpha(0.0)
    , scale(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _cmd_type;
  _cmd_type cmd;

   typedef double _fi_type;
  _fi_type fi;

   typedef double _velocity_type;
  _velocity_type velocity;

   typedef double _alpha_type;
  _alpha_type alpha;

   typedef double _scale_type;
  _scale_type scale;



  enum {
    RUNRIPPLE = 1,
    RUNTRIPOD = 2,
    STOP = 3,
    PAUSE = 4,
    SLEEP = 5,
  };


  typedef boost::shared_ptr< ::taticoma_msgs::GaitCommand_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::taticoma_msgs::GaitCommand_<ContainerAllocator> const> ConstPtr;

}; // struct GaitCommand_

typedef ::taticoma_msgs::GaitCommand_<std::allocator<void> > GaitCommand;

typedef boost::shared_ptr< ::taticoma_msgs::GaitCommand > GaitCommandPtr;
typedef boost::shared_ptr< ::taticoma_msgs::GaitCommand const> GaitCommandConstPtr;

// constants requiring out of line definition

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::taticoma_msgs::GaitCommand_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::taticoma_msgs::GaitCommand_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::taticoma_msgs::GaitCommand_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::taticoma_msgs::GaitCommand_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "999052af9472adb07699063f39a5a04e";
  }

  static const char* value(const ::taticoma_msgs::GaitCommand_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x999052af9472adb0ULL;
  static const uint64_t static_value2 = 0x7699063f39a5a04eULL;
};

template<class ContainerAllocator>
struct DataType< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "taticoma_msgs/GaitCommand";
  }

  static const char* value(const ::taticoma_msgs::GaitCommand_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 cmd\n"
"float64 fi\n"
"float64 velocity\n"
"float64 alpha\n"
"float64 scale\n"
"\n"
"int32 RUNRIPPLE=1\n"
"int32 RUNTRIPOD=2\n"
"int32 STOP=3\n"
"int32 PAUSE=4\n"
"int32 SLEEP=5\n"
;
  }

  static const char* value(const ::taticoma_msgs::GaitCommand_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cmd);
      stream.next(m.fi);
      stream.next(m.velocity);
      stream.next(m.alpha);
      stream.next(m.scale);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GaitCommand_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::taticoma_msgs::GaitCommand_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::taticoma_msgs::GaitCommand_<ContainerAllocator>& v)
  {
    s << indent << "cmd: ";
    Printer<int32_t>::stream(s, indent + "  ", v.cmd);
    s << indent << "fi: ";
    Printer<double>::stream(s, indent + "  ", v.fi);
    s << indent << "velocity: ";
    Printer<double>::stream(s, indent + "  ", v.velocity);
    s << indent << "alpha: ";
    Printer<double>::stream(s, indent + "  ", v.alpha);
    s << indent << "scale: ";
    Printer<double>::stream(s, indent + "  ", v.scale);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TATICOMA_MSGS_MESSAGE_GAITCOMMAND_H
