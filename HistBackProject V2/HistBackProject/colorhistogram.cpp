#include "colorhistogram.h"

ColorHistogram::ColorHistogram()
{
    histSize[0]=256; histSize[1]=256; histSize[2]=256;  //256 values in each dimension
    hranges[0]=0.0; hranges[1]=255.0;                   //max & min of each item
    ranges[0]=hranges; ranges[1]=hranges; ranges[2]=hranges;
    channels[0]=0; channels[1]=1; channels[2]=2;        //3 channels

}

void ColorHistogram::getHistogram(const cv::Mat &image)
{
    cv::calcHist(&image,    //input image
                 1,         //number of imput images
                 channels,  //channels
                 cv::Mat(), //mask
                 hist,      //output histogram
                 3,         //3-dimension histogram
                 histSize,  //value of each item
                 ranges);   //ranges of each dimension
}

void ColorHistogram::getHueHistogram(const cv::Mat &image,
                                     int minSaturation)
{
    // 转换到HSV空间
    cv::Mat hsv;
    cv::cvtColor(image,hsv,CV_BGR2HSV);

    // 创建掩码矩阵，标出低饱和度像素（S通道像素值<minSaturation）
    cv::Mat mask;
    if(minSaturation>0)
    {
        std::vector<cv::Mat> v;
        cv::split(image,v);
        // 对饱和度（S）通道阈值化
        cv::threshold(v[1],mask,minSaturation,
                255,cv::THRESH_BINARY);
    }

    // 参数
    // 这里不能使用构造函数中复制的成员变量，因为我们不再计算三通道直方图，而是单通道！
    float hranges_[2];
    // 这里范围不再是0-255；因为从cvtColor得到的HSV图像，Hue分量取值范围是0-180
    hranges_[0]=0.0; hranges_[1]=180.0;
    const float *ranges_[1];
    ranges_[0]=hranges_;
    int channels_[1];
    channels_[0]=0;  //仅使用色调（Hue）分量
    int histSize_[1];
    histSize_[0]=181;

    //1D色调直方图
    cv::calcHist(&hsv,
                 1,
                 channels_,
                 mask,  // 掩码矩阵。不计入低饱和度像素
                 hist,
                 1,
                 histSize_,
                 ranges_);
}
