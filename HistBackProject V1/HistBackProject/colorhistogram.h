/************************************
Yiqi Yan(SaoYan)
2017/3/18
*************************************/

#ifndef COLORHISTOGRAM_H
#define COLORHISTOGRAM_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class ColorHistogram
{
public:
    ColorHistogram();
    void getHistogram(const cv::Mat &image);

public:
    cv::MatND hist;    //histogram

private:
    int histSize[3];
    float hranges[2];
    const float* ranges[3];
    int channels[3];
};

#endif // COLORHISTOGRAM_H
