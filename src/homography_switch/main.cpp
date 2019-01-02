
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

struct userdata{
    Mat im;
    vector<Point2f> points;
};


void mouseHandler(int event, int x, int y, int flags, void* data_ptr)
{
    if  ( event == EVENT_LBUTTONDOWN )
    {
        userdata *data = ((userdata *) data_ptr);
        circle(data->im, Point(x,y),3,Scalar(0,255,255), 5, CV_AA);
        imshow("Image", data->im);
        if (data->points.size() < 4)
        {
            data->points.push_back(Point2f(x,y));
        }
    }
    
}



int main( int argc, char** argv)
{

    // Read in the image.
    //Mat im_src = imread("first-image.jpg");
    Mat im_src = imread("../pictures/1.jpg");
    Size size = im_src.size();
   
    // Create a vector of points.
    vector<Point2f> pts_src;
    pts_src.push_back(Point2f(0,0));
    pts_src.push_back(Point2f(size.width - 1, 0));
    pts_src.push_back(Point2f(size.width - 1, size.height -1));
    pts_src.push_back(Point2f(0, size.height - 1 ));
    
    

    // Destination image
    //Mat im_dst = imread("times-square.jpg");
    Mat im_dst = imread("../pictures/12.jpg");

    
    // Set data for mouse handler
    Mat im_temp = im_dst.clone();
    userdata data;
    data.im = im_temp;


    //show the image
    imshow("Image", im_temp);
    
    cout << "Click on four corners of a billboard and then press ENTER" << endl;
    //set the callback function for any mouse event
    setMouseCallback("Image", mouseHandler, &data);
    std::cout<<"selected a range"<<endl;
    waitKey(0);
    

    Mat Homography = findHomography(pts_src,data.points);

    //用H对原图做变换
    warpPerspective(im_src,im_temp,Homography,im_temp.size());

    //提取鼠标点击的四个角点
    Point pts_dst[4];
    for (int i = 0; i < 4; ++i)
    {
        pts_dst[i] = data.points[i];
    }

    // 把目标对应区域像素值设置为0
    fillConvexPoly(im_dst,pts_dst,4,Scalar(0),CV_AA);

    // 把原图叠加到目标图上
    im_dst = im_dst+im_temp;

    // Display image.
    imshow("Image", im_dst);
    waitKey(0);

    return 0;
}
