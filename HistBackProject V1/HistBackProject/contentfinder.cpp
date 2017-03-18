/************************************
Yiqi Yan(SaoYan)
2017/3/18
*************************************/

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
