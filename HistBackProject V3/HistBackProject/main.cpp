#include <QCoreApplication>
#include "colorhistogram.h"
#include "contentfinder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 可定制参数
    double th=0.05f;     // 二值化阈值
    int minSaturation=100; // 饱和度阈值
    cv::Mat element1 = cv::Mat(9,9,CV_8U,cv::Scalar(1));
    cv::Mat element2 = cv::Mat(9,9,CV_8U,cv::Scalar(1));

    // 实例化两个类
    ColorHistogram hc;
    ContentFinder finder;

    // 计算样本图像直方图
    cv::Mat image_sample=cv::imread("sample.jpg");
    hc.getHueHistogram(image_sample, minSaturation);

    // 测试图像
    cv::Mat image_test = cv::imread("test.jpg");
    cv::namedWindow("image");
    cv::imshow("image",image_test);

    // 识别当前图像低饱和度像素
    cv::vector <cv::Mat> v;
    cv::Mat image_hsv;
    cv::cvtColor(image_test,image_hsv,CV_BGR2HSV);
    cv::split(image_hsv,v);  //v[1]是饱和度分量
    cv::threshold(v[1],v[1],minSaturation,255,cv::THRESH_BINARY);

    // 寻找目标
    finder.setHistogram(hc.hist);
    finder.setThreshold(th);
    finder.findHue(image_hsv);

    //去除低饱和度像素
    cv::bitwise_and(finder.result,v[1],finder.result);

    // 形态学运算
    cv::dilate(finder.result,finder.result,element1);
    cv::erode(finder.result,finder.result,element2);

    // 提取连通区域轮廓
    cv::Mat image_detect = finder.result.clone();
    std::vector< std::vector<cv::Point> > contours;
    cv::findContours(image_detect,contours,
                     CV_RETR_EXTERNAL,
                     CV_CHAIN_APPROX_NONE);

    // 提取包围盒
    std::vector<cv::Rect> boundRect =
            std::vector<cv::Rect>(contours.size());
    for(int i=0; i<(int)contours.size(); i++)
    {
        boundRect[i]=cv::boundingRect(cv::Mat(contours[i]));
    }
    // 选出最大的一个包围盒
    cv::Rect rect;
    if(contours.size()!=0)
    {
        for(int i=0,pos_max=0; i<(int)contours.size(); i++)
        {
            if(boundRect[pos_max].area() <= boundRect[i].area())
            {
                pos_max=i;
                rect=boundRect[pos_max];
            }
        }
    }

    cv::rectangle(image_test,rect,cv::Scalar(0,255,0),2); //绿色矩形框

    // 显示结果
    cv::namedWindow("result");
    cv::imshow("result", finder.result);
    cv::namedWindow("detection");
    cv::imshow("detection",image_test);

    return a.exec();
}

