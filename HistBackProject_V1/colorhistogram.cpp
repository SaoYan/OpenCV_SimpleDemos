/************************************
Yiqi Yan(SaoYan)
2017/3/18
*************************************/

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
