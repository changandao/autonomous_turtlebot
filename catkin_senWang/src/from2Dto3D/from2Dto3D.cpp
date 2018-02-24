#include <ros/ros.h>
#include <ros/console.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/Char.h>
#include <string.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <tf/transform_listener.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

#include <geometry_msgs/PoseArray.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<math.h>

// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <perception_msgs/Rect.h>



using namespace std;
using namespace cv;


class From2Dto3D
{

private:
    //! The node handle
    ros::NodeHandle nh_;
    //! Node handle in the private namespace
    ros::NodeHandle priv_nh_;

    //! Define publishers and subscribers
    ros::Subscriber sub_name;
    ros::Subscriber sub;
    ros::Subscriber sub_line;
    ros::Publisher pub_name;
    ros::Publisher pubAB;

    //! Define the pointcloud structure and the bounding box local copy
    //pcl::PointCloud<pcl::PointXYZ> pcl_pc_xyz;
    sensor_msgs::PointCloud2 sensor_msgs_pcl2;
    int boundingbox_x;
    int boundingbox_y;
    //! A tf transform listener if needed
    tf::TransformListener listener_;
    //pcl::PointXYZ point_xyz;
    geometry_msgs::Point p;
    perception_msgs::Rect bb;

    //------------------ Callbacks -------------------

    //! Process clusters
    void processCloud(const sensor_msgs::PointCloud2ConstPtr& pc);
    //! Process bounding boxes
    void processRect(const perception_msgs::RectConstPtr & r);
    void processpoints(const geometry_msgs::PoseArrayConstPtr& posearray);

public:
    //! Subscribes to and advertises topics
    From2Dto3D(ros::NodeHandle nh) : nh_(nh), priv_nh_("~")
    {

        // subscribers to the bounding boxes and the point cloud
        // format:
        sub_name = nh_.subscribe<sensor_msgs::PointCloud2>("/camera/depth_registered/points", 10, &From2Dto3D::processCloud, this);
        sub = nh_.subscribe<perception_msgs::Rect>("/image_processing/ball", 10, &From2Dto3D::processRect, this);
        //sub_line = nh_.subscribe<geometry_msgs::PoseArray>("/line/points", 10, &From2Dto3D::processpoints, this);
        // Publishers
        // format:
        pub_name = nh_.advertise<geometry_msgs::Point>("/my_move_base/my_point3D", 10);
        //pubAB = nh_.advertise<geometry_msgs::Point>("/AandB",10);
        ROS_INFO("from2Dto3D initialized ...");

    }

    ~From2Dto3D() {}
};


void From2Dto3D::processCloud(const sensor_msgs::PointCloud2ConstPtr& pc)
{
    sensor_msgs_pcl2 = *pc;
    ROS_INFO("The point clouds mesgs are accepted.");

}

void From2Dto3D::processRect(const perception_msgs::RectConstPtr& r)
{
    //    //boundingbox_x=r->x+r->width/2;
    //    //boundingbox_y=r->y+ r->height/2;
    //    if(this->pcl_pc_xyz.empty())
    //        return;
    //    else
    //        ;
    //    // process bounding box and send 3D position to the topic
    //    // tip: take a look at the pcl::PointXYZRGB structure
    //    bb.header = r->header;
    //    bb.x = r->x;
    //    bb.y = r->y;
    //    bb.height = r->height;
    //    bb.width = r->width;
    //    int col = int(bb.x + 0.5*bb.width);
    //    int row = int(bb.y + bb.height);
    //    // get x,y,z coordinate of Point center

    //    //this->point_xyz = this->pcl_pc_xyz.operator ()(col, row);
    //    //publish
    //    //cout << pcl_pc_xyz.height << " " << pcl_pc_xyz.width << endl;
    //    this->p.x = this->pcl_pc_xyz.operator ()(col, row).x;

    //    this->p.y = this->pcl_pc_xyz.operator ()(col, row).y;

    //    this->p.z = this->pcl_pc_xyz.operator ()(col, row).z;

    //    this->pub_name.publish(this->p);
    //    //ROS_WARN("aaaaaaaaaaaaaa");


    // get width and height of 2D point cloud data
//    int width = sensor_msgs_pcl2.width;
//    int height = sensor_msgs_pcl2.height;

    // Convert from u (column / width), v (row/height) to position in array
    // where X,Y,Z data starts
    int arrayPosition = (r->y + r->height) * sensor_msgs_pcl2.row_step + (r->x + r->width/2) *sensor_msgs_pcl2.point_step;

    // compute position in array where x,y,z data start
    int arrayPosX = arrayPosition + sensor_msgs_pcl2.fields[0].offset; // X has an offset of 0
    int arrayPosY = arrayPosition + sensor_msgs_pcl2.fields[1].offset; // Y has an offset of 4
    int arrayPosZ = arrayPosition + sensor_msgs_pcl2.fields[2].offset; // Z has an offset of 8
    ROS_INFO("fucked");
    float X = 0.0;
    float Y = 0.0;
    float Z = 0.0;

    memcpy(&X, &sensor_msgs_pcl2.data[arrayPosX], sizeof(float));
    memcpy(&Y, &sensor_msgs_pcl2.data[arrayPosY], sizeof(float));
    memcpy(&Z, &sensor_msgs_pcl2.data[arrayPosZ], sizeof(float));

    p.x = X;
    p.y = Y;
    p.z = Z;

    pub_name.publish(p);
    ROS_INFO("The image cords have been processed");

}

void From2Dto3D::processpoints(const geometry_msgs::PoseArrayConstPtr& posearray){


    vector<geometry_msgs::Point> mid;

    for (int i = 0; i<3;i++){


        // Convert from u (column / width), v (row/height) to position in array
        // where X,Y,Z data starts
        int arrayPosition = (posearray->poses[i].position.y) * sensor_msgs_pcl2.row_step + (posearray->poses[i].position.x) *sensor_msgs_pcl2.point_step;

        // compute position in array where x,y,z data start
        int arrayPosX = arrayPosition + sensor_msgs_pcl2.fields[0].offset; // X has an offset of 0
        int arrayPosY = arrayPosition + sensor_msgs_pcl2.fields[1].offset; // Y has an offset of 4
        int arrayPosZ = arrayPosition + sensor_msgs_pcl2.fields[2].offset; // Z has an offset of 8

        float X = 0.0;
        float Y = 0.0;
        float Z = 0.0;

        memcpy(&X, &sensor_msgs_pcl2.data[arrayPosX], sizeof(float));
        memcpy(&Y, &sensor_msgs_pcl2.data[arrayPosY], sizeof(float));
        memcpy(&Z, &sensor_msgs_pcl2.data[arrayPosZ], sizeof(float));

        mid[i].x = X;
        mid[i].y = Y;
        mid[i].z = Z;

        // pub_name.publish(p);


    }
    double A = sqrt(pow(mid[0].x - mid[2].x,2)+pow(mid[0].x - mid[2].x,2));
    double Perimeter = 0.5*(A + mid[0].z + mid[2].z);
    //double S = sqrt(Perimeter*(Perimeter-mid[0].z)*(Perimeter-mid[2].z)*(Perimeter-A));
    double L = sqrt(pow(mid[0].x,2)+pow(mid[0].y,2)+pow(mid[0].z,2));
    double R = sqrt(pow(mid[2].x,2)+pow(mid[2].y,2)+pow(mid[2].z,2));
    double S = sqrt(Perimeter*(Perimeter-L)*(Perimeter-R)*(Perimeter-A));


    double part_B = 2*S/A;
    geometry_msgs::Point PP;
    PP.x = A;
    PP.y = part_B;
    pubAB.publish(PP);


}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "from2Dto3D");
    ros::NodeHandle nh;

    From2Dto3D node(nh);
    ros::spin();
    return 0;
}


