#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
void getHc(const cv::Mat image, int channelNum, cv::Mat & Hist);
void dispHist(cv::Mat hist, int histSize, cv::Mat & histDisp);

int main()
{
    cv::Mat image = cv::imread("test.jpg");
    cv::namedWindow("Original");
    cv::imshow("Original",image);

    cv::Mat hist, histDisp;
    // channel B
    getHc(image, 0, hist);
    if(!hist.empty())
    {
        dispHist(hist,256, histDisp);
    }
    cv::namedWindow("Hist of Channel B");
    cv::imshow("Hist of Channel B", histDisp);
    cv::imwrite("B.jpg", histDisp);

    // channel G
    getHc(image, 1, hist);
    if(!hist.empty())
    {
        dispHist(hist,256, histDisp);
    }
    cv::namedWindow("Hist of Channel G");
    cv::imshow("Hist of Channel G", histDisp);
    cv::imwrite("G.jpg", histDisp);

    // channel R
    getHc(image, 2, hist);
    if(!hist.empty())
    {
        dispHist(hist,256, histDisp);
    }
    cv::namedWindow("Hist of Channel R");
    cv::imshow("Hist of Channel R", histDisp);
    cv::imwrite("R.jpg", histDisp);

    cv::waitKey(0);
    return 0;
}

void getHc(const cv::Mat image, int channelNum, cv::Mat & Hist)
{
    int histSize[1] = {256};          //numbers of items in each dimension
    float hranges[2] = {0.0 , 255.0}; //max & min of each item
    const float* ranges[1] = {hranges};
    int channels[1] = {channelNum};   //1 channel
    cv::calcHist(&image,1,channels,cv::Mat(),
                 Hist,1,histSize,ranges);
}

void dispHist(cv::Mat hist, int histSize, cv::Mat & histDisp)
{
    double maxVal,minVal;
    cv::minMaxIdx(hist,&minVal,&maxVal,
                  NULL,NULL);
    histDisp = cv::Mat(histSize,histSize,
                               CV_8UC1,cv::Scalar(255));
    //设置最高点为nbis的90%
    int hpt = static_cast<int>(0.9*histSize);

    //绘制：每个条目绘制一条竖直的直线
    for(int h=0; h<histSize; h++)
    {
        float binVal = hist.at<float>(h);
        int intensity = static_cast<int>(binVal*hpt/maxVal);
        cv::line(histDisp,
                 cv::Point(h,histSize),
                 cv::Point(h,histSize-intensity),
                 cv::Scalar::all(0));
    }
}
