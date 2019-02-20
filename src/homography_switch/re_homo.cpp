
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

    Mat im_dst = imread("../pictures/100.jpg");

    
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

    int out_image_width=(data.points[1].x-data.points[0].x) < (data.points[2].x-data.points[3].x) ?
            (data.points[2].x-data.points[3].x):(data.points[1].x-data.points[0].x);
    int out_image_height=(data.points[3].y-data.points[0].y) < (data.points[2].y-data.points[1].y) ?
                         (data.points[2].y-data.points[1].y):(data.points[3].y-data.points[0].y);

    cout<<"out image width: "<<out_image_width<<endl;
    cout<<"out image height: "<<out_image_height<<endl;
    Mat aa(out_image_width,out_image_height,CV_8UC3);
//    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    Size size = aa.size();

    // Create a vector of points.
    vector<Point2f> pts_src;
    pts_src.push_back(Point2f(0,0));
    pts_src.push_back(Point2f(size.width - 1, 0));
    pts_src.push_back(Point2f(size.width - 1, size.height -1));
    pts_src.push_back(Point2f(0, size.height - 1 ));

    Mat Homography = findHomography(data.points,pts_src);
//      Mat Homography = findHomography(data.points,pts_src);

    //用H对原图做变换
    warpPerspective(im_dst,aa,Homography,aa.size());

    imshow("change Image", aa);
    waitKey(0);
    imwrite("../pictures/102.jpg",aa);

    return 0;
}
