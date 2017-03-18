/************************************
Yiqi Yan(SaoYan)
2017/3/18
*************************************/

#include <QCoreApplication>
#include "colorhistogram.h"
#include "contentfinder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // parameters
    double th=0.05f; // threshold

    // instantiation
    ColorHistogram hc;
    ContentFinder finder;

    // calculate histogram of the sample image
    cv::Mat image_sample=cv::imread("sample.jpg");
    hc.getHistogram(image_sample);

    //detect
    cv::Mat image_test = cv::imread("test.jpg");
    finder.setHistogram(hc.hist);
    finder.setThreshold(th);
    finder.find(image_test);

    // show result
    cv::namedWindow("result");
    cv::imshow("result", finder.result);

    return a.exec();
}
