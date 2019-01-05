//
// Created by zbz on 1/5/19.
//
#include <opencv2/opencv.hpp>
#include <iostream>
#include <zbar.h>

using namespace cv;
using namespace std;
using namespace zbar;

int main(int argc,char* argv[])
{
    char fileNameString[100];
    char windowNameString[50];
    char resultFileNameSring[100];
    Mat srcImage,grayImage,blurImage,thresholdImage,gradientXImage,gradientYImage,gradientImage,morphImage;
//    for (int fileCount = 1;fileCount < 7;fileCount++)
//    {
//        sprintf(fileNameString,"../pictures/barcode_0%d.jpg",fileCount);
//        sprintf(windowNameString,"result 0%d",fileCount);
//        sprintf(resultFileNameSring,"../pictures/barcodeResult_0%d.jpg",fileCount);
//        //读取图像
////        cout<<"image name:"<<fileNameString<<endl;
//        srcImage = imread(fileNameString);
//        if(srcImage.empty())
//        {
//            cout<<"image file read error"<<endl;
//
//            return -1;
//        }
//        //图像转换为灰度图像
//        if(srcImage.channels() == 3)
//        {
//            cvtColor(srcImage,grayImage,CV_RGB2GRAY);
//        }
//        else
//        {
//            grayImage = srcImage.clone();
//        }
//        //建立图像的梯度幅值
//        Scharr(grayImage,gradientXImage,CV_32F,1,0);
//        Scharr(grayImage,gradientYImage,CV_32F,0,1);
//        //因为我们需要的条形码在需要X方向水平,所以更多的关注X方向的梯度幅值,而省略掉Y方向的梯度幅值
//        subtract(gradientXImage,gradientYImage,gradientImage);
//        //归一化为八位图像
//        convertScaleAbs(gradientImage,gradientImage);
//        //看看得到的梯度图像是什么样子
//        //imshow(windowNameString,gradientImage);
//        //对图片进行相应的模糊化,使一些噪点消除
//        blur(gradientImage,blurImage,Size(9,9));
//        //模糊化以后进行阈值化,得到到对应的黑白二值化图像,二值化的阈值可以根据实际情况调整
//        threshold(blurImage,thresholdImage,210,255,THRESH_BINARY);
//        //看看二值化图像
//        //imshow(windowNameString,thresholdImage);
//        //二值化以后的图像,条形码之间的黑白没有连接起来,就要进行形态学运算,消除缝隙,相当于小型的黑洞,选择闭运算
//        //因为是长条之间的缝隙,所以需要选择宽度大于长度
//        Mat kernel = getStructuringElement(MORPH_RECT,Size(21,7));
//        morphologyEx(thresholdImage,morphImage,MORPH_CLOSE,kernel);
//        //看看形态学操作以后的图像
////        imshow(windowNameString,morphImage);
////        waitKey(500);
//        //现在要让条形码区域连接在一起,所以选择膨胀腐蚀,而且为了保持图形大小基本不变,应该使用相同次数的膨胀腐蚀
//        //先腐蚀,让其他区域的亮的地方变少最好是消除,然后膨胀回来,消除干扰,迭代次数根据实际情况选择
//        erode(morphImage, morphImage, getStructuringElement(MORPH_RECT, Size(3,3)),Point(-1,-1),4);
//        dilate(morphImage, morphImage, getStructuringElement(MORPH_RECT, Size(3,3)),Point(-1,-1),4);
//        //看看形态学操作以后的图像
////        imshow(windowNameString,morphImage);
////        waitKey(500);
//        vector<vector<Point2i>>contours;
//        vector<float>contourArea;
//        //接下来对目标轮廓进行查找,目标是为了计算图像面积
//        findContours(morphImage,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
//        //计算轮廓的面积并且存放
//        for(int i = 0; i < contours.size();i++)
//        {
//            contourArea.push_back(cv::contourArea(contours[i]));
//        }
//        //找出面积最大的轮廓
//        double maxValue;Point maxLoc;
//        minMaxLoc(contourArea, NULL,&maxValue,NULL,&maxLoc);
//        //计算面积最大的轮廓的最小的外包矩形
//        RotatedRect minRect = minAreaRect(contours[maxLoc.x]);
//        //为了防止找错,要检查这个矩形的偏斜角度不能超标
//        //如果超标,那就是没找到
//        if(minRect.angle<2.0)
//        {
//            //找到了矩形的角度,但是这是一个旋转矩形,所以还要重新获得一个外包最小矩形
//            Rect myRect = boundingRect(contours[maxLoc.x]);
//            //把这个矩形在源图像中画出来
//            rectangle(srcImage,myRect,Scalar(0,255,255),3,LINE_AA);
//            //看看显示效果,找的对不对
////            imshow(windowNameString,srcImage);
////            waitKey(1000);
//            //将扫描的图像裁剪下来,并保存为相应的结果,保留一些X方向的边界,所以对rect进行一定的扩张
////             myRect.x= myRect.x - (myRect.width/20);
//             myRect.width = myRect.width;
//            Mat resultImage = Mat(srcImage,myRect);
//            if(!imwrite(resultFileNameSring,resultImage))
//            {
//                cout<<"file save error!"<<endl;
//                return -2;
//            }
//        }
//    }
    //检测到了之后进行条形码识别
//    FileStorage file("../pictures/result.xml",FileStorage::WRITE);
    Mat imageGray,imageGuussian;
    Mat imageSobelX,imageSobelY,imageSobelOut;

    for (int fileCount = 1;fileCount < 13;fileCount++)
    {
        sprintf(resultFileNameSring,"../pictures/barcode/barcode_%d.jpg",fileCount);
        sprintf(windowNameString,"result 0%d",fileCount);
        Mat result = imread(resultFileNameSring);
        if(!result.empty())
        {
            //现在开始识别
            cvtColor(result,grayImage,CV_RGB2GRAY);

            int width = grayImage.cols;   // extract dimensions
            int height = grayImage.rows;
            Image image(width,height,"Y800",grayImage.data,width*height);
            // Create a zbar reader
            ImageScanner scanner;
            // Configure the reader
            scanner.set_config(ZBAR_NONE,ZBAR_CFG_ENABLE,1);

//            imshow(windowNameString,grayImage);
//            waitKey(0);
            int n = scanner.scan(image);
            if(image.symbol_begin()==image.symbol_end()) {
                cout <<"pic name:\t"<<resultFileNameSring<<endl<< "查询条码失败，请检查图片！"
                                                                  << endl<<"=================="<<endl;
            }

                for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end();++symbol)
            {
                cout <<"pic name:\t"<<resultFileNameSring<<endl<<"code type:\t"<<symbol->get_type_name()<<endl<<\
                    "decode string:\t"<<symbol->get_data()<<endl<<"=================="<<endl;
                image.set_data(NULL,0);
                //xml文件写入

            }
        }
    }
    waitKey(0);
    return 1;
}
