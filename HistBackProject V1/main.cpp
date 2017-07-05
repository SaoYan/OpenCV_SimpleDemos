/************************************
Yiqi Yan(SaoYan)
2017/3/18
*************************************/

#include "colorhistogram.h"
#include "contentfinder.h"

int main()
{
    // parameters
    double th=0.05f; // threshold

    // instantiation
    ColorHistogram hc;
    ContentFinder finder;

    // calculate histogram of the sample image
    cv::Mat image_sample=cv::imread("images/sample.jpg");
    hc.getHistogram(image_sample);

    //detect
    cv::Mat image_test = cv::imread("images/test.jpg");
    finder.setHistogram(hc.hist);
    finder.setThreshold(th);
    finder.find(image_test);

    // show result
    cv::namedWindow("result");
    cv::imshow("result", finder.result);

    cv::waitKey();
    return 0;
}
