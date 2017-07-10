# OpenCV_ToyExamples
Here are some simple demos to help you explore OpenCV. I hope you will have fun!

There are some tutorials for OpenCV beginners. To see the tutorials, go to [here](http://mp.weixin.qq.com/mp/homepage?__biz=MzIxOTQ3MTI5NQ==&hid=9&sn=bc002ded707c2c4610a44d446b1b95a4#wechat_redirect).<br />

To follow my Public Account and see other tutorials, you can search Account name 'SaoYan' in Wechat.

## Install OpenCV (with opencv_contrib)
```
git clone https://github.com/opencv/opencv
git clone https://github.com/opencv/opencv_contrib
cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local/opencv -D OPENCV_EXTRA_MODULES_PATH=/home/USERNAME/opencv_contrib/modules/ ..
sudo make -j8
sudo make install
```
**ATTENTION**: remember to replace 'USERNAME' with you own user name.  
After installation, you need to do one more thing.
```
cd /usr/local/opencv/lib/pkgconfig
sudo cp opencv.pc /usr/lib/pkgconfig
cd /usr/lib/pkgconfig
sudo mv opencv.pc opencv-3.pc
```

## How to run the codes
```
git clone https://github.com/SaoYan/OpenCV_SimpleDemos
cd path/to/the/codes
make  
./opencv_exp
```
For example
```
cd /OpenCV_ToyExamples/FeatureDetect  
make  
./opencv_exp
```
**ATTENTION**
Some of the demos may need extra parameters from the command line. Refer to the following descriptions for details.

## SURF & SIFT Feature Detect
**FeatureDetect**  
SURF feature & SIFT feature detector is included in opencv_contrib modules. Therefore, you may find the implementation quite different from other Opencv project.
1. Remember to use the namespace cv::xfeatures2d rather than cv. Many other modules in opencv_contrib also have their own namespaces. Pay attention to this in other demos.
2. In this implementation, we first define two structure, rather than use the Opencv class & function directly. The reason is that the corresponding classes are defined as abstract classes, thus cannot be used directly.

detection result (figure #1: SURF, figure #2: SIFT):  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FeatureDetect/SURF.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FeatureDetect/SIFT.jpg" />

## Histogram Calculation
**HistCal**  
This demo calculate & display the histogram of the input image.  
figure #1: input image, figure #2-4: histogram of channel R, G, B, respectively.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/test.jpg" />  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/R.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/G.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/B.jpg" />

## Histogram Back-projection
**HistBackProject V1**  
This demo is a simple use of histogram backprojection to detect an monochromatic (or nealy monochromatic) object.
The corresponding tutorial can be found [here](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483949&idx=1&sn=636cd5077c1749a5dfdaa3e6de14af74&scene=19#wechat_redirect).<br />
I provide one test image with the sample patch extracted from it. Be free to use you own test images! You may be wondering how to use you camera to run histogram back-projection online. We'll see how to do this in the following demos (refer to V4).  
You may find out that the outcome is very upsetting. We'll see the reason and try to modify it in [next tutorial](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483953&idx=1&sn=d733791678baaaa5dc910d41990db27c&scene=19#wechat_redirect).<br />(The corresponding demo will be 'V2')  
**HistBackProject V2**  
In this demo, HSV color space is used to improve the performance in V1.  
The corresponding tutorial can be found [here](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483953&idx=1&sn=d733791678baaaa5dc910d41990db27c&scene=19#wechat_redirect).<br />
The result is shown below.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistBackProject%20V2/images/result.jpg" width="315" height="235" />

**HistBackProject V3**  
This demo has the following modifications based on HistBackProject V2.
1. Morphology operation is used to enhance the target object in the binary image.
2. Extra contours and calculate bounding box.  

The result is shown below.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistBackProject%20V3/images/result_binary.jpg" width="380" height="300" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistBackProject%20V3/images/result.jpg" width="380" height="300" />

**HistBackProject V4**  
This demo run Histogram Back-projection online, i.e. capture video frames via the camera on you computer and detect the target.  
Follow the steps:
1. Use your mouse to select the target region.
2. When you are done with step 1, press 'Y' and watch the object detection result.
3. Press 'Q' at any time to quit.

Histogram Back-projection is not that powerful, so it is recommended to select a monochrome target region.  
The PDF file is a summary I wrote. You can refer to it for more details.

## Pedestrian Detection
**HogPedestrianDetection**  
This is a fairly simple demo. The result is shown below.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HogPedestrianDetection/images/result1.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HogPedestrianDetection/images/result2.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HogPedestrianDetection/images/result3.jpg" />

## Object Tracking
There are 5 tracking algorithms in OpenCV Tracking API. You can select one via command line parameters.  
**Running this demo needs extra parameters from the command line:**  
```
./opencv_exp trackerName {-vid | -img} { <video filename> | <dir name>
```
For example  
**to use video file:**
```
./opencv_exp KCF -vid test.mp4
```
**to use image sequence:**
```
./opencv_exp KCF -img test
```
