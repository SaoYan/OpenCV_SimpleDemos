#include "colorhistogram.h"
#include "contentfinder.h"

int main()
{
    // 可定制参数
    double th=0.05f;     // 二值化阈值
    int minSaturation=100; // 饱和度阈值

    // 实例化两个类
    ColorHistogram hc;
    ContentFinder finder;

    // 计算样本图像直方图
    cv::Mat image_sample=cv::imread("images/sample.jpg");
    hc.getHueHistogram(image_sample, minSaturation);

    // 测试图像
    cv::Mat image_test = cv::imread("images/test.jpg");
    cv::namedWindow("image");
    cv::imshow("image",image_test);

    // 识别当前图像低饱和度像素
    std::vector <cv::Mat> v;
    cv::cvtColor(image_test,image_test,cv::COLOR_BGR2HSV);
    cv::split(image_test,v);  //v[1]是饱和度分量
    cv::threshold(v[1],v[1],minSaturation,255,cv::THRESH_BINARY);

    // 寻找目标
    finder.setHistogram(hc.hist);
    finder.setThreshold(th);
    finder.findHue(image_test);

    //去除低饱和度像素
    cv::bitwise_and(finder.result,v[1],finder.result);

    // 显示结果
    cv::namedWindow("result");
    cv::imshow("result", finder.result);

    cv::waitKey(0);
    return 0;
}
