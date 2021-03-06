// Generated by gencpp from file lidar_processing/featureArrayH.msg
// DO NOT EDIT!


#ifndef LIDAR_PROCESSING_MESSAGE_FEATUREARRAYH_H
#define LIDAR_PROCESSING_MESSAGE_FEATUREARRAYH_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <lidar_processing/feature.h>

namespace lidar_processing
{
template <class ContainerAllocator>
struct featureArrayH_
{
  typedef featureArrayH_<ContainerAllocator> Type;

  featureArrayH_()
    : header()
    , features()  {
    }
  featureArrayH_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , features(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::lidar_processing::feature_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::lidar_processing::feature_<ContainerAllocator> >::other >  _features_type;
  _features_type features;




  typedef boost::shared_ptr< ::lidar_processing::featureArrayH_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lidar_processing::featureArrayH_<ContainerAllocator> const> ConstPtr;

}; // struct featureArrayH_

typedef ::lidar_processing::featureArrayH_<std::allocator<void> > featureArrayH;

typedef boost::shared_ptr< ::lidar_processing::featureArrayH > featureArrayHPtr;
typedef boost::shared_ptr< ::lidar_processing::featureArrayH const> featureArrayHConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lidar_processing::featureArrayH_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lidar_processing::featureArrayH_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace lidar_processing

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'lidar_processing': ['/nas/ei/home/ga62saf/gruppe2/catkin_shangyin/src/lidar_processing/msg'], 'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg', '/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::lidar_processing::featureArrayH_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lidar_processing::featureArrayH_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lidar_processing::featureArrayH_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lidar_processing::featureArrayH_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lidar_processing::featureArrayH_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lidar_processing::featureArrayH_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lidar_processing::featureArrayH_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aa8d97923860a4e2da8c4709e9639b62";
  }

  static const char* value(const ::lidar_processing::featureArrayH_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaa8d97923860a4e2ULL;
  static const uint64_t static_value2 = 0xda8c4709e9639b62ULL;
};

template<class ContainerAllocator>
struct DataType< ::lidar_processing::featureArrayH_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lidar_processing/featureArrayH";
  }

  static const char* value(const ::lidar_processing::featureArrayH_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lidar_processing::featureArrayH_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
feature[] features\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: lidar_processing/feature\n\
float64 r\n\
float64 phi\n\
float64 specifier\n\
int32 knownCorr\n\
";
  }

  static const char* value(const ::lidar_processing::featureArrayH_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lidar_processing::featureArrayH_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.features);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct featureArrayH_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lidar_processing::featureArrayH_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lidar_processing::featureArrayH_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "features[]" << std::endl;
    for (size_t i = 0; i < v.features.size(); ++i)
    {
      s << indent << "  features[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::lidar_processing::feature_<ContainerAllocator> >::stream(s, indent + "    ", v.features[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // LIDAR_PROCESSING_MESSAGE_FEATUREARRAYH_H
