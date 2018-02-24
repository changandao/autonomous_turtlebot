/*********************************************************************
* Compiler:         gcc 4.6.3
*
* Company:          Institute for Cognitive Systems
*                   Technical University of Munich
*
* Author:           Emmanuel Dean (dean@tum.de)
*                   Karinne Ramirez (karinne.ramirez@tum.de)
*
* Compatibility:    Ubuntu 12.04 64bit (ros hydro)
*
* Software Version: V0.1
*
* Created:          01.06.2015
*
* Comment:          turtle connection and visualization (Sensor and Signals)
*
********************************************************************/


/*********************************************************************
* STD INCLUDES
********************************************************************/
#include <iostream>
#include <fstream>
#include <pthread.h>


/*********************************************************************
* ROS INCLUDES
********************************************************************/
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
//#include <tf_conversions/tf_eigen.h>

/*********************************************************************
* EIGEN INCLUDES
********************************************************************/
#include <Eigen/Eigen>
#include <Eigen/StdVector>
#include <Eigen/Geometry>
#include <Eigen/Core>

/*********************************************************************
 * SEVICES AND MESSAGES
 * ******************************************************************/
//SET HEADERS FOR THE SERVICE AND THE MESSAGES OF THE TURTLE_VIS PACKAGE
#include <turtle_vis/myClass/TurtleClass.h>
#include <turtle_vis/DesiredPose.h>
#include <turtle_vis/send_desired_pose.h>
#include <geometry_msgs/PointStamped.h>
using namespace Eigen;


geometry_msgs::PointStamped pp;

void backll(const geometry_msgs::PointStampedConstPtr& p){


    pp.point.x = p->point.x;
    pp.point.z = p->point.z;
    pp.point.y = p->point.y;


}
int main(int argc, char** argv)
{

    ros::init(argc, argv, "turtle_visualization",ros::init_options::AnonymousName);

    ROS_INFO_STREAM("**Client turtle desired position");

    ros::NodeHandle n;
    ros::Rate r(60);

    //INITIALIZE THE CLIENT
    ros::ServiceClient client=n.serviceClient<turtle_vis::send_desired_pose/*//#>>>>TODO: DEFINE THE SERVICE TYPE*/>("TurtlePose");

    ros::Subscriber sub = n.subscribe("/my_move_base/my_point3D", 100, /*&geometry_msgs::PointStamped,*/&backll );

    ////#>>>>TODO: DEFINE A MSG VARIABLE FOR THE SERVICE MESSAGE
    turtle_vis::send_desired_pose srv;

    // turtle_vis::send_desired_pose msg;                // Publisher-> Subscribe msg    Client->Service Srv


    while(ros::ok())
    {
    if((pp.point.x != 0)|(pp.point.y != 0))
        std::vector<double> vals;

        ROS_INFO_STREAM("Give me the desired position of the turtle: x,y,theta");
        //std::cin>>myString;
        std::cout << pp.point.x<<std::endl;
        srv.request.z = -pp.point.x;
        srv.request.y = pp.point.y;
        srv.request.x = 0; // theta



        if(client.call(srv))  //#>>>>TODO:CALL THE CLIENT WITH msg
        {
            //#>>>>TODO:PLOT THE MESSAGE
            //ROS_INFO_STREAM("ROS has been Sent!!!!");
            //std::cout<<"x= "<<srv.request.a<<"\t y= "<< srv.request.b << "\t theta= "<<srv.request.c << std::endl;

        }
        else
        {
            ROS_ERROR_STREAM("Failed to call the service 'TurtlePose'");
            return 1;
        }
     ros::spinOnce();
    }


    ros::spinOnce();
    return 0;
}
