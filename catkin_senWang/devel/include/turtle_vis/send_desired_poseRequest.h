// Generated by gencpp from file turtle_vis/send_desired_poseRequest.msg
// DO NOT EDIT!


#ifndef TURTLE_VIS_MESSAGE_SEND_DESIRED_POSEREQUEST_H
#define TURTLE_VIS_MESSAGE_SEND_DESIRED_POSEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace turtle_vis
{
template <class ContainerAllocator>
struct send_desired_poseRequest_
{
  typedef send_desired_poseRequest_<ContainerAllocator> Type;

  send_desired_poseRequest_()
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  send_desired_poseRequest_(const ContainerAllocator& _alloc)
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




  typedef boost::shared_ptr< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> const> ConstPtr;

}; // struct send_desired_poseRequest_

typedef ::turtle_vis::send_desired_poseRequest_<std::allocator<void> > send_desired_poseRequest;

typedef boost::shared_ptr< ::turtle_vis::send_desired_poseRequest > send_desired_poseRequestPtr;
typedef boost::shared_ptr< ::turtle_vis::send_desired_poseRequest const> send_desired_poseRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace turtle_vis

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'turtle_vis': ['/nas/ei/home/ga62reh/workspace/gruppe2/catkin_senWang/src/turtle_vis/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const ::turtle_vis::send_desired_poseRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtle_vis/send_desired_poseRequest";
  }

  static const char* value(const ::turtle_vis::send_desired_poseRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::turtle_vis::send_desired_poseRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct send_desired_poseRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtle_vis::send_desired_poseRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtle_vis::send_desired_poseRequest_<ContainerAllocator>& v)
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

#endif // TURTLE_VIS_MESSAGE_SEND_DESIRED_POSEREQUEST_H
