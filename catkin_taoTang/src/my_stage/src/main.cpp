#include <ros/ros.h>
#include "landmarks.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "landmarks");

    Landmarks landmarks;

    ros::spin();

    return 0;
}
