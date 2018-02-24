#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtle_vis/myClass/TurtleClass.h>
#include "collision_prevention.h"


/** The robot_driver node drives the robot to the target location requested by the navigation node.
This process is realized by combining TurtleClass, the server responsible for calculating the linear and
angular speed to the target, with collision_prevention, the class that uses lidar scan messages to
avoid obstacles along the way and plan the path. */

int main(int argc, char	**argv)	{
    ros::init(argc, argv, "robot_driver");

    ros::NodeHandle nh;

    //TurtleClass: server responsible for navigation, i.e. it calculates velocity for the requested location.
    turtleSpace::TurtleClass turtleF;

    /** Collision_Prevention: responsible for obstacle avoidance, i.e. for a given input velocity, col_prev
    evaluates turtle's surroundings and makes the decision whether the turtle should execute the input
    speed command or dodge a detected obstacle. */
    collision_prevention col_prevention;

    // Instantialize a publisher for publishing velocity messages
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);

    // Instantialize a laser scan subscriber for col_prevention to detect obstacles
    ros::Subscriber laser_sub = nh.subscribe("/lidarscan",
                                             1,
                                             &collision_prevention::scanCallback,
                                             &col_prevention);

    // Advertise a service for GOTO-target-location requests
    ros::ServiceServer service = nh.advertiseService("TurtlePose",
                                                       &turtleSpace::TurtleClass::getDPose,
                                                       &turtleF);

    // Subscribe to /odom in order to calculate velocity
    ros::Subscriber sub = nh.subscribe("/odom",100,
                                          &turtleSpace::TurtleClass::getTiagoPose,
                                          &turtleF);

    ros::Rate rate(60);

    ROS_INFO("ROBOT_DRIVER_STARTED");

    Vector3d turtleTIAGOPose;
    Vector3d turtleTIAGOPose_local;
    turtleTIAGOPose<<1,0,0;
    turtleTIAGOPose_local=turtleTIAGOPose;
    turtleF.turtlePose_g=turtleTIAGOPose;


    ros::Time ti, tf;
    ti=ros::Time::now();

    // Proportional Gain
    Matrix3d Kp;

    // Set gains
    double p_g=0.2;

    // LOAD p_gain FROM THE ROS PARAMETER SERVER
    ros::param::get("/turtle_gains/p_gain",p_g);
    ROS_INFO_STREAM("p_g= "<<p_g);


    // Proportional Gain
    Kp<<p_g,0  ,0,
            0  ,p_g,0,
            0  ,0  ,p_g;
    ROS_INFO_STREAM("Kp= \n"<<Kp);

    Vector3d turtlePose,turtlePose_old,turtleVel;
    Vector3d error;
    double dt;

    // INITIALIZE THE TURTLE POSE
    turtlePose<<1,0,0;
    turtlePose_old=turtlePose;
    turtleVel<<0,0,0;

    // DESIRED POSE
    Vector3d turtlePose_desired_local;

    // INITIALIZE THE DESIRED POSE VARIABLE OF THE CLASS TURTLE
    turtleF.turtlePose_desired_g=turtlePose;
    turtlePose_desired_local=turtlePose;


    // CREATE A DESIREDPOSE MSG VARIABLE
    //turtle_vis::DesiredPose msg;
    //std::cout<<"x= "<<msg.x<<"\t y= "<<msg.y<<"\t z= "<<msg.theta<<std::endl;

    geometry_msgs::Twist msg2;

    Matrix2d K;
    K<<0.3,0,
       0, 0.3;

    Matrix2d T_g;
    //T_g<<0.1,0.1,
    //      0.1,0.1;

    float d = 0.2;
    Vector2d turtleTIAGOPose_2d,turtleTIAGOPose_2d_Now;
    Vector2d turtleTIAGOPose_desired_local_2d;
    //turtleTIAGOPose_2d << 1,1;
    //turtleTIAGOPose_desired_local_2d << 1,1;

    Vector2d error_2d;
    Vector2d turtleVel_2d;

    while (ros::ok()) {
        //turtleVel_2d<<0,0;
        tf=ros::Time::now();

        dt=tf.toSec()-ti.toSec();


        // Get Local  Suscribe
        turtleTIAGOPose_local=turtleF.getLocalPose();

        // TEST
        //std::cout<<"X: \t"<<turtleTIAGOPose_local[0]<<"Y: \t"<<turtleTIAGOPose_local[1]<<"Z: \t"<<turtleTIAGOPose_local[2]<<std::endl;
        turtleTIAGOPose_2d<<turtleTIAGOPose_local[0],turtleTIAGOPose_local[1];


        // Get Desired Pose from the class variable
        //turtlePose_desired_local=turtleF.CALL_THE_METHOD_TO_OBTAIN_THE_DESIRED_POSE();
        turtlePose_desired_local=turtleF.getLocalDesiredPose();

        turtleTIAGOPose_desired_local_2d<< turtlePose_desired_local[0], turtlePose_desired_local[1];


        // CONTROL
        // COMPUTE THE ERROR BETWEEN CURRENT POSE AND DESIRED
        //error=turtlePose_desired_local-turtlePose;
        //error=turtlePose-turtlePose_desired_local;
        error_2d=turtleTIAGOPose_desired_local_2d-turtleTIAGOPose_2d;


        // COMPUTE THE INCREMENTS
        //turtleVel=-Kp*error;
        turtleVel_2d=K*error_2d;

        T_g<< 1*cos(turtleTIAGOPose_local[2]),1*sin(turtleTIAGOPose_local[2]),
                -sin(turtleTIAGOPose_local[2])/d, cos(turtleTIAGOPose_local[2])/d;


        turtleTIAGOPose_2d_Now=T_g*turtleVel_2d;

        // COMPUTE THE NEW TURTLE POSE (USE SIMPLE INTEGRATION)
        turtlePose= turtlePose + turtleVel*dt;

        float lin_x= turtleTIAGOPose_2d_Now(0);
        float ang_z = turtleTIAGOPose_2d_Now(1);
        //pub.publish(msg);
        //std::cout<<"xx = "<< turtlePose[0] << "\t yy= " << turtlePose[1] << "\t zz= " << turtlePose[2] << std::endl;

        // SET THE HISTORY
        turtlePose_old=turtlePose;
        ti=tf;

        /** Pass the go-to-target velocity to col_prevention and let it either returns the velocity (if no critical collision danger),
        or returns a velocity that allows the turtle to maneuver around the obstacle. */
        vel_pub.publish(col_prevention.getVelMsg(lin_x, ang_z));

        // Get incoming messages
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
