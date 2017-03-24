#include "contentfinder.h"

ContentFinder::ContentFinder()
{
    hranges[0]=0.0; hranges[1]=255.0;
    ranges[0]=hranges; ranges[1]=hranges; ranges[2]=hranges;
    channels[0]=0; channels[1]=1; channels[2]=2;
    threshold=-1.0f;
}

void ContentFinder::setThreshold(double t)
{
    threshold=t;
}

void ContentFinder::setHistogram(const cv::MatND &hist)
{
    histogram=hist;
    cv::normalize(histogram,histogram,1.0);
}

void ContentFinder::find(const cv::Mat &image)
{
    cv::calcBackProject(&image,
                        1,
                        channels,
                        histogram,
                        result,
                        ranges,
                        255.0);

    if((threshold>0)&&(threshold<1))
    {
        cv::threshold(result,result,
                      255*threshold,255,
                      cv::THRESH_BINARY);
    }
}

void ContentFinder::findHue(const cv::Mat &image)
{

    // 准备参数
    // 这里不能使用构造函数中复制的成员变量，因为我们不再计算三通道直方图，而是dim指定了通道数单通道！
    float hranges_[2];
    // 这里范围不再是0-255；因为从cvtColor得到的HSV图像，Hue分量取值范围是0-180
    hranges_[0]=0.0; hranges_[1]=180.0;
    const float *ranges_[1];
    ranges_[0]=hranges_;
    int channels_[1];
    channels_[0]=0;  //仅使用色调（Hue）分量

    cv::calcBackProject(&image,
                        1,
                        channels_,
                        histogram,
                        result,
                        ranges_,
                        255.0);

    if((threshold>0)&&(threshold<1))
    {
        cv::threshold(result,result,
                      255*threshold,255,
                      cv::THRESH_BINARY);
    }
}
