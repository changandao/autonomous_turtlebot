#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

struct Point3d{
    double x ;
    double y ;
    double z ;
};

Point3d P_3d;

void myposcallback(const geometry_msgs::Point::ConstPtr& P){
    //Point3d P_3d;
    double x;
    double y;
    double z;
    x = double(P->x);
    y = double(P->y);
    z = double(P->z);
    P_3d.x = x;
    P_3d.y = y;
    P_3d.z = z;

    if(!(isnan(x)||isnan(y)||isnan(z)))
    {

        P_3d.x = x;
        P_3d.y = y;
        P_3d.z = z;
    }else{
        P_3d.x = 0;
        P_3d.y = 0;
        P_3d.z = 0;
    }
}


int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;
  ros::Subscriber goal_pos_sub = node.subscribe("/my_move_base/goal_pos", 10, &myposcallback);
  //ros::Subscriber my_pos_sub = node.subscribe("/my_move_base/my_pos", 10, &myposcallback);

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(10.0);
  while (node.ok()){
    transform.setOrigin( tf::Vector3(P_3d.x, P_3d.y, P_3d.z) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "odom", "goal_pos"));
    rate.sleep();
  }
  return 0;
};
