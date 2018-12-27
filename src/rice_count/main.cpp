//
// Created by zbz on 12/27/18.
//
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );
//
///* @function main */
//int main( int argc, char** argv )
//{
//    /// Load source image and convert it to gray
//    src = imread( argv[1], 1 );
//
//    /// Convert image to gray and blur it
//    cvtColor( src, src_gray, COLOR_BGR2GRAY );
//    blur( src_gray, src_gray, Size(3,3) );
//
//    /// Create Window
//    char* source_window = "Source";
//    namedWindow( source_window, WINDOW_AUTOSIZE );
//    imshow( source_window, src );
//
//    createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
//    thresh_callback( 0, 0 );
//
//    waitKey(0);
//    return(0);
//}


Rect selection;
Mat img,img0;
Point prePt(-1,-1);
void onMouse(int event,int x,int y,int flags,void* param){
    if (event==CV_EVENT_LBUTTONDOWN){
        prePt = Point(x, y);
    }
    else if (event == CV_EVENT_MOUSEMOVE && (flags && CV_EVENT_FLAG_LBUTTON)){
        img = img0.clone();
        rectangle(img, Rect(prePt.x, prePt.y, abs(x - prePt.x), abs(y - prePt.y)), Scalar(0,0,255),3);
        selection = Rect(prePt.x, prePt.y, abs(x - prePt.x), abs(y - prePt.y));

    }
    else if (event == CV_EVENT_LBUTTONUP || !(flags & CV_EVENT_FLAG_LBUTTON)){

        prePt=Point(-1, -1);
    }
    imshow("raw", img);
}


int main(){
    img = imread("../rice.jpeg",1);
    img0 = img.clone();
    namedWindow("raw",1);
    imshow("raw", img);
//    waitKey(0);
    setMouseCallback("raw", onMouse);
    Mat result; // 4种可能结果
    Mat bgModel, fgModel; // 背景/前景
    for (;;){
        int c = waitKey(10);
        if ((char)c == 'p'){
            grabCut(img0, result, selection, bgModel, fgModel,6, GC_INIT_WITH_RECT);
            compare(result,GC_PR_FGD,result,CMP_EQ);//得到前景mask
            Mat foreground(img.size(),CV_8UC3,Scalar::all(255));
            img0.copyTo(foreground,result);
            imshow("result",result);
            imshow("img0",img0);
            imshow("grabcut",foreground);

            Mat raw_img =foreground;
            imshow("raw",raw_img);

            Mat blur_img;
            GaussianBlur(raw_img,blur_img,Size(3,3),0,0);
//    imshow("blur",blur_img);
            Mat kernel_1 = getStructuringElement(MORPH_RECT,Size(1,1),Point(-1,-1));
            Mat kernel_2 = getStructuringElement(MORPH_RECT,Size(2,2),Point(-1,-1));
            Mat kernel_3 = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));

//    morphologyEx(blur_img,blur_img,MORPH_GRADIENT,kernel_1,Point(-1,-1),2);
            Mat bin_img,gray_img;
            int th=100;
            cvtColor(blur_img,gray_img,COLOR_BGR2GRAY);
            threshold(gray_img,bin_img,th,255,THRESH_BINARY|THRESH_TRIANGLE);
//    imshow("binary",bin_img);

            int blockSize = 45;
            int constValue = 2;
            Mat local;
            adaptiveThreshold(gray_img,local,255,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,blockSize,constValue);

            Mat morph_img;

            morphologyEx(local,morph_img,MORPH_DILATE,kernel_2,Point(-1,-1),1);
            morphologyEx(morph_img,morph_img,MORPH_ERODE,kernel_2,Point(-1,-1),3);
            imshow("morphology",morph_img);
        }
        if (char(c) == 'q') return 0;


    }
    return 0;
}
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    Mat raw_img = imread("/shared/tmp/rice.jpeg");
    imshow("raw",raw_img);

    Mat blur_img;
    GaussianBlur(raw_img,blur_img,Size(15,15),0,0);
//    imshow("blur",blur_img);
    Mat kernel_1 = getStructuringElement(MORPH_RECT,Size(1,1),Point(-1,-1));
    Mat kernel_2 = getStructuringElement(MORPH_RECT,Size(2,2),Point(-1,-1));
    Mat kernel_3 = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));

//    morphologyEx(blur_img,blur_img,MORPH_GRADIENT,kernel_1,Point(-1,-1),2);
    Mat bin_img,gray_img;
    int th=100;
    cvtColor(blur_img,gray_img,COLOR_BGR2GRAY);
    threshold(gray_img,bin_img,th,255,THRESH_BINARY|THRESH_TRIANGLE);
//    imshow("binary",bin_img);

    int blockSize = 45;
    int constValue = 2;
    Mat local;
    adaptiveThreshold(gray_img,local,255,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,blockSize,constValue);
//    cv::adaptiveThreshold(image, local, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY_INV, blockSize, constValue);
//    imshow("local binary",local);

    Mat morph_img;

    morphologyEx(local,morph_img,MORPH_DILATE,kernel_2,Point(-1,-1),6);
    morphologyEx(morph_img,morph_img,MORPH_ERODE,kernel_2,Point(-1,-1),6);
    imshow("morphology",morph_img);


//    src = imread("/shared/tmp/rice.jpeg");
//    /// Convert image to gray and blur it
////    cvtColor( src, src_gray, COLOR_BGR2GRAY );
//        src_gray = morph_img;
//    blur( src_gray, src_gray, Size(3,3) );
//
//    /// Create Window
//    char* source_window = "Source";
//    namedWindow( source_window, WINDOW_AUTOSIZE );
//    imshow( source_window, src );
//
//    createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
//    thresh_callback( 0, 0 );
//
//    waitKey(0);
//    return(0);

    waitKey(0);
    return 0;
}
*/
/* @function thresh_callback */
void thresh_callback(int, void* )
{
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    /// Detect edges using canny
    Canny( src_gray, canny_output, thresh, thresh*2, 3 );
    /// Find contours
    findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

    /// Draw contours
    Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }

    /// Show in a window
    namedWindow( "Contours", WINDOW_AUTOSIZE );
    imshow( "Contours", drawing );
}
