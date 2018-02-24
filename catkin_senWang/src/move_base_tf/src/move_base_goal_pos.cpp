#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <math.h>

using namespace std;

struct Point3d{
    double x ;
    double y ;
    double z ;
};

Point3d P_3d;



void goalcallback(const geometry_msgs::Point::ConstPtr& P){
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
    //ROS_INFO("FUCK U");
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
    ros::init(argc, argv, "move_base_listener1");
    ros::NodeHandle node;
//    ros::Publisher turtle_vel =
//            node.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 10);
    ros::Subscriber points_sub = node.subscribe("/my_move_base/my_point3D", 10, &goalcallback);
    ros::Publisher goal_pose_pub =node.advertise<geometry_msgs::Point>("/my_move_base/goal_pos", 10);


    tf::TransformListener listener;
    tf::TransformBroadcaster br;
    tf::Transform transform_brd;

    ros::Rate rate(10.0);
    listener.waitForTransform("camera_depth_optical_frame", "odom", ros::Time(0), ros::Duration(3.0));


    while (node.ok()){

        tf::StampedTransform transform;
        try{
            listener.lookupTransform("camera_depth_optical_frame", "odom", ros::Time(0), transform);

        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        geometry_msgs::Twist vel_msg;
        double x = transform.getOrigin().x();
        double y = transform.getOrigin().y();
        double z = transform.getOrigin().z();


//        vel_msg.angular.z = double(0.1 * atan2(y, x));
//        vel_msg.linear.x = double(0.1 * sqrt(pow(x, 2) + pow(y, 2)));
//        turtle_vel.publish(vel_msg);
        //ROS_INFO_STREAM("something new: " << P_3d.x << " " << P_3d.y);

        geometry_msgs::Point goal_point;
        goal_point.x = x + P_3d.z;
        goal_point.y = y - P_3d.x;
        goal_point.z = z - P_3d.y;

        ROS_INFO_STREAM(x << " " << y);
        transform_brd.setOrigin( tf::Vector3(goal_point.x, goal_point.y
                                         , goal_point.z) );
        transform_brd.setRotation( tf::Quaternion(0, 0, 0, 1) );
        br.sendTransform(tf::StampedTransform(transform_brd, ros::Time::now(), "odom", "goal_pos"));
        //goal_pose_pub.publish(goal_point);

        ros::spinOnce();
        rate.sleep();

    }

    return 0;
};
