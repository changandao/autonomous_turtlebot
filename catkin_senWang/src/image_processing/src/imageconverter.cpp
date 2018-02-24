#include "imageconverter.h"

ImageConverter::ImageConverter()
    : it_(nh_)
{

    // Subscrive to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/camera/rgb/image_rect_color", 1,
                               &ImageConverter::imageCb, this);
    ball_pub_ = nh_.advertise<geometry_msgs::Point>("/image_processing/ball",1);
    namedWindow(OPENCV_WINDOW);
    startWindowThread();
}


ImageConverter::~ImageConverter()
{
    destroyWindow(OPENCV_WINDOW);
}


char ImageConverter::decideLR(int position)
{
    char side;
    if(position<320) side = 'l';
    else side ='r';
    return side;
}

void ImageConverter::setcolor(char color)
{
    set_color = color;
}


void ImageConverter::get_task(int flag)
{
    image_task_flag = flag;
}


char ImageConverter::return_team_color()
{
    char team_color = image_field;
    return team_color;
}


bool ImageConverter::team_color_done()
{
    return team_color_detected;
}


bool ImageConverter::return_detected_signal(){
    return puck_color_detected;
}


void ImageConverter::imageCb(const sensor_msgs::ImageConstPtr& msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }
    mIn = cv_ptr->image;
    //ROS_INFO("image in");

    Mat cv_img;
    Mat im_gray;

    cvtColor(mIn, cv_img, CV_BGR2HSV);
    preprossImage(cv_img,cv_img);
    cvtColor(cv_img, im_gray,CV_BGR2GRAY);

    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2,2));
    morphologyEx(cv_img, cv_img, MORPH_OPEN, element);
    morphologyEx(cv_img, cv_img, MORPH_CLOSE, element);
    morphologyEx(im_gray, im_gray, MORPH_OPEN, element);
    morphologyEx(im_gray, im_gray, MORPH_CLOSE, element);

    //    Orange  0-22
    //    Yellow 22- 38
    //    Green 38-75
    //    Blue 75-130
    //    Violet 130-160
    //    Red 160-179

    Mat drawing = Mat::zeros(im_gray.size(), CV_8UC1 );

    int iLowH;
    int iHighH;
    int iLowS =30;
    int iLowV = 20;
    Mat out_img= cv_img;

    if(set_color = 'y'){
        iLowH = 22;
        iHighH = 38;
    }
    else if(set_color = 'b'){
        iLowH = 75;
        iHighH = 130;
    }
    //to do: wait for signal
    recognize(cv_img, out_img, im_gray, drawing, iLowH, iHighH, iLowS, iLowV, image_task_flag);

    //yellow:60, green:120, blue:240, red:0
    imshow("origin", mIn);
    Mat image;
    cvtColor(out_img, image, CV_HSV2BGR);
    imshow(OPENCV_WINDOW, image);

    namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
    imshow( "Contours", drawing );

    namedWindow( "grays", CV_WINDOW_AUTOSIZE );
    imshow( "grays", im_gray );



    waitKey(30);

}


void ImageConverter::preprossImage(Mat imgin, Mat imageout)
{
    Mat tempImg[3];
    split(imgin, tempImg);
    equalizeHist(tempImg[2], tempImg[2]);
    cv::merge(tempImg, 3, imageout);
    //imageout = ;
}

void ImageConverter::recognize(Mat img_in, Mat out_img, Mat im_gray, Mat drawing, int iLowH, int iHighH, int iLowS, int iLowV, int flag)
{

    int h = img_in.rows;
    int w = img_in.cols;

    int c = 0;
    for (int y=int(0); y<int(h); y++)
    {
        uchar* q = img_in.ptr(y);
        for (int x=0; x<w; x++)
        {

            int data_h = *(q + x*3);
            int data_s = *(q + x*3 +1);
            int data_v = *(q + x*3 +2);
            if(data_h>iLowH&&data_h < iHighH&&data_s > iLowS&&data_v>iLowV){
                out_img.at<uchar>(y,x*3)=0;
                //out_img.at<uchar>(y,x*3+1)=0;
                //out_img.at<uchar>(y,x*3+2)=0;
                im_gray.at<uchar>(y,x) = 255;
                c++;
            }
            else{
                im_gray.at<uchar>(y,x) = 0;
            }
        }
    }
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours(im_gray, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, Point(0, 0) );
    //int shapenums = contours.size();
    //printf("let's see how many contours: %d",shapenums);
    vector<Rect> boundRect;

    //printf("let's see how many contours: %d",size);
    int imax = 0;

    double ratio[2] = {0.0, 1.0};
    geometry_msgs::Point ball_pos;
    if (flag == 1){
        ratio[0] = 2.0;
        ratio[1] = 5.0;
        boundRect = findmax(contours, &imax, ratio);

        int obj_size = boundRect[imax].width * boundRect[imax].height;
        //std::cout << " the size of the ball: " << obj_size << std::endl;
        if(obj_size > 5000)
        {
            ball_center_pos = boundRect[imax].x + boundRect[imax].width/2;
            ball_pos.x = ball_center_pos;
            ball_pos.y = boundRect[imax].y + boundRect[imax].height/2;
            //ball_center_pos.y = boundRect[imax].y + boundRect[imax].height/2;
            if (ball_pos_cache_idx < ball_pos_cache_idx_max){
                // cache ball_pos
                ball_pos_cache[ball_pos_cache_idx] = ball_center_pos;
                ball_pos_cache_idx++;
            }else{
                // cache finished, calculate most left pos
                ball_pos_cache_left = ball_pos_cache[0];
                //int ball_pos_cache_ileft = 0;
                for(int i = 1; i< ball_pos_cache_idx_max; i++){
                    if(ball_pos_cache[i]<ball_pos_cache_left)
                        ball_pos_cache_left = ball_pos_cache[i];
                        //ball_pos_cache_ileft = i;
                }
                ball_pos_cache_idx = 0;
                ball_pos.x = ball_pos_cache_left;
                //std::cout << "the most left ball x: " << ball_pos_cache_left << std::endl;
            }
            puck_color_detected = true;
            ball_pub_.publish(ball_pos);
        }
        else{
            puck_color_detected = false;
            image_lookup = true;
            //std::cout << "finding the ball"<< std::endl;
        }
    }
    else if (flag == 0){
        ratio[0] = 0.3;
        ratio[1] = 0.6;
        boundRect = findmax(contours, &imax, ratio);
        ball_center_pos = boundRect[imax].x + boundRect[imax].width/2;
        ball_pos.x = ball_center_pos;
        ball_pos.y = boundRect[imax].y + boundRect[imax].height/2;
        if (boundRect[imax].width * boundRect[imax].height > 230*80){
            //size = true;
            image_field = 'y';
            team_color_detected = true;
            //printf("\n, we are in the yellow site, \n ");
        }
        else{
            image_field = 'b';
            team_color_detected = true;
            //printf("we are in the blue site ");
        }
        //while(){printf("\n, you know nothing John, \n" );}
    }
    rectangle(drawing, boundRect[imax], Scalar(255,0,255),1);
}


vector<Rect> ImageConverter::findmax(vector<vector<Point> > contours, int *imax, double ratio[2])
{
    vector<vector<Point> > contours_poly(contours.size());
    vector<Rect> boundRect(contours.size());

    float areamax = 0;
    for ( int i=0; i<contours.size(); i++){

        approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
        boundRect[i] = boundingRect(Mat(contours_poly[i]));
        float width =  boundRect[i].width;
        float height = boundRect[i].height;
        float area = width*height;
        float r = height / width;
        if (r>ratio[0] && r<ratio[1])
        {
            if (areamax < area){
                areamax = area;
                *imax = i;
            }
        }
    }
    return boundRect;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_processing");
//    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

//     int iLowH = 35;
//     int iHighH = 140;

//     int iLowS = 90;
//     int iHighS = 255;

//     int iLowV = 90;
//     int iHighV = 255;

//     //Create trackbars in "Control" window
//     cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
//     cvCreateTrackbar("HighH", "Control", &iHighH, 179);

//     cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
//     cvCreateTrackbar("HighS", "Control", &iHighS, 255);

//     cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
//     cvCreateTrackbar("HighV", "Control", &iHighV, 255);
    ImageConverter imageconv;
    ros::spin();

    return 0;
}
