#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <geometry_msgs/Point.h>
#include <stdio.h>
using namespace std;
using namespace cv;
static const std::string OPENCV_WINDOW = "Image window";
//RNG rng(12345);

class ImageConverter{
private:
    cv::Mat mIn;
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber image_sub_;
    ros::Publisher ball_pub_;
    int ball_pos_cache_idx = 0;
    const static int ball_pos_cache_idx_max = 20;
    const static int ball_pos_cache_threshold = 10;
    int ball_pos_cache[ball_pos_cache_idx_max] = {0};
    int ball_pos_cache_left = 0;
    int ball_center_pos = 0;
    int image_obj_pos = 0;


    int image_task_flag = 0;

    char image_field = 'u' ;
    char set_color = 'y';

    bool team_color_detected = false;
    double puck_color_detected = 0.0;

    bool puck_catched = false;
    bool catching_puck = false;

    bool image_lookup = false;

    //image_transport::Publisher image_pub_;
public:
    ImageConverter();
    ~ImageConverter();
    void setcolor(char color);
    void get_task(int flag);
    int return_detected_signal();
    char return_team_color();
    char decideLR(int position);
    bool team_color_done();
    void get_puck_catch_signal(bool get_puck_flag);
    bool return_catching_puck_signal();

    void preprossImage(Mat imgin, Mat imageout);
    void recognize(Mat img_in, Mat out_img, Mat im_gray, Mat drawing, int iLowH, int iHighH, int iLowS, int iLowV, int flag);
    vector<Rect> findmax(vector<vector<Point> > contours, int *imax, double ratio[2]);
    void imageCb(const sensor_msgs::ImageConstPtr& msg);


    //  void showImage(string title, const cv::Mat &mat);

};

#endif
