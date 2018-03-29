# OpenCV_ToyExamples
Here are some simple demos to help you explore OpenCV. I hope you will have fun!

There are some tutorials for OpenCV beginners. To see the tutorials, go to [here](http://mp.weixin.qq.com/mp/homepage?__biz=MzIxOTQ3MTI5NQ==&hid=11&sn=a972be0cf5056ec2e44bc773bb58032c#wechat_redirect).<br />

To follow my Public Account and see other tutorials, you can search Account name 'SaoYan' in Wechat.

## Install OpenCV (with opencv_contrib, python3 and GPU support)
1. Install prerequisites
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential cmake git pkg-config
sudo apt-get install libjpeg8-dev libjasper-dev libpng12-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
sudo apt-get install libgtk2.0-dev
sudo apt-get install libatlas-base-dev gfortran
```
2. Pull down opencv and opencv_contrib from Github
```
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_EXTRA_MODULES_PATH=PATH \
      -D BUILD_opencv_python3=Yes
      -D WITH_CUDA=ON \
      -D WITH_CUBLAS=1 \
      -D WITH_TBB=ON \
      -D ENABLE_FAST_MATH=1 \
      -D CUDA_FAST_MATH=1 \
      -D WITH_OPENGL=ON ..
make -j32
sudo make install
```
**ATTENTION**: remember to replace 'PATH' with the correct path of ***opencv_contrib/modules***.  
3. add pkgconfig
```
sudo ldconfig
```
4. add OpenCV to python path  
In order to use the python API, you have to add the parent directory of "cv2.so" to python path.
```
sudo vi ~/.bashrc
```
Add the following contents:
> export PYTHONPATH=/usr/local/opencv/lib/python2.7/dist-packages:$PYTHONPATH

Then update the environment variables:
```
source ~/.bashrc
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

## Calculate image convolution using DFT
[DFT](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/DFT)   
Convolution can be efficiently calculated in frequency domain. In fact, all OpenCV Image Filter API perform their calculations this way.  
In this demo I implement this myself. The result may not be exactly the same as what you get when you use Image Filter API directly, because OpenCV has some extra operations.  
You need some basic knowledge of DSP in order to understand the code.  
The result is shown below:  
figure #1: original image; figure #2: convolution result  
<img src="https://github.com/SaoYan/OpenCV_SimpleDemos/blob/master/DFT/test.jpg" width="300" height="300" />
<img src="https://github.com/SaoYan/OpenCV_SimpleDemos/blob/master/DFT/result.jpg" width="300" height="300" />

## SURF & SIFT Feature Detect
[FeatureDetect](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/FeatureDetect)  
SURF feature & SIFT feature detector is included in opencv_contrib modules. Therefore, you may find the implementation quite different from other Opencv project.
1. Remember to use the namespace cv::xfeatures2d rather than cv. Many other modules in opencv_contrib also have their own namespaces. Pay attention to this in other demos.
2. In this implementation, we first define two structure, rather than use the Opencv class & function directly. The reason is that the corresponding classes are defined as abstract classes, thus cannot be used directly.

detection result (figure #1: SURF, figure #2: SIFT):  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FeatureDetect/SURF.jpg" width="320" height="240" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FeatureDetect/SIFT.jpg" width="320" height="240" />

## Flood Fill algorithm
[FloodFill](https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FloodFill)  
Remember the Fill tool in Windows Paint Application? It can paint a connected region in the image with one color. This looks like:  
 <img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FloodFill/test.jpg" width="288" height="162" />
 <img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FloodFill/FloodFill.jpg" width="288" height="162" />

Figure #2 is created based on Flood Fill algorithm. The API in OpenCV also returns a mask which indicates the painted region.  
 <img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/FloodFill/FloodFillMask.jpg" width="288" height="162" />  

Please refer to the code and OpenCV documents for more details.

## Histogram Calculation
[HistCal](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/HistCal)   
This demo calculate & display the histogram of the input image.  
figure #1: input image, figure #2-4: histogram of channel R, G, B, respectively.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/test.jpg" />  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/R.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/G.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HistCal/B.jpg" />

## Histogram Back-projection
[HistBackProject V1](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/HistBackProject%20V1)   
This demo is a simple use of histogram backprojection to detect an monochromatic (or nealy monochromatic) object.
The corresponding tutorial can be found [here](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483949&idx=1&sn=636cd5077c1749a5dfdaa3e6de14af74&scene=19#wechat_redirect).<br />
I provide one test image with the sample patch extracted from it. Be free to use you own test images! You may be wondering how to use you camera to run histogram back-projection online. We'll see how to do this in the following demos (refer to V4).  
You may find out that the outcome is very upsetting. We'll see the reason and try to modify it in [next tutorial](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483953&idx=1&sn=d733791678baaaa5dc910d41990db27c&scene=19#wechat_redirect).<br />(The corresponding demo will be 'V2')  

[HistBackProject V2](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/HistBackProject%20V2)  
In this demo, HSV color space is used to improve the performance in V1.  
The corresponding tutorial can be found [here](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483953&idx=1&sn=d733791678baaaa5dc910d41990db27c&scene=19#wechat_redirect).<br />
The result is shown below.  
<img src="https://github.com/SaoYan/OpenCV_SimpleDemos/blob/master/HistBackProject_V2/images/result.jpg" width="315" height="235" />

[HistBackProject V3](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/HistBackProject%20V3)  
This demo has the following modifications based on HistBackProject V2.
1. Morphology operation is used to enhance the target object in the binary image.
2. Extra contours and calculate bounding box.  

The result is shown below.  
<img src="https://github.com/SaoYan/OpenCV_SimpleDemos/blob/master/HistBackProject_V3/images/result_binary.jpg" width="380" height="300" />
<img src="https://github.com/SaoYan/OpenCV_SimpleDemos/blob/master/HistBackProject_V3/images/result.jpg" width="380" height="300" />

[HistBackProject V4](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/HistBackProject%20V4)    
This demo run Histogram Back-projection online, i.e. capture video frames via the camera on you computer and detect the target.  
Follow the steps:
1. Use your mouse to select the target region.
2. When you are done with step 1, press 'Y' and watch the object detection result.
3. Press 'Q' at any time to quit.

Histogram Back-projection is not that powerful, so it is recommended to select a monochrome target region.  
The PDF file is a summary I wrote. You can refer to it for more details.

## Pedestrian Detection
[HogPedestrianDetection](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/HogPedestrianDetection)
This is a fairly simple demo. The result is shown below.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HogPedestrianDetection/images/result1.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HogPedestrianDetection/images/result2.jpg" />
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/HogPedestrianDetection/images/result3.jpg" />

## LSD Line Segment Detector
[LSD](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/LSD)   
LSD is an algorithm proposed in this [IEEE paper](http://ieeexplore.ieee.org/document/4731268/).  
This algorithm is powerful, but sometimes too 'powerful' to eliminate tiny line elements in an image.  This problem is shown below.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/LSD/result.jpg" />  

In this demo, I filter the detection result by eliminating lines whose length are less than the threshold. When setting threshold to be 30, the result looks much better.  
<img src="https://github.com/SaoYan/OpenCV_ToyExamples/blob/master/LSD/result_filtered.jpg" />

## Object Tracking
[Tracking](https://github.com/SaoYan/OpenCV_SimpleDemos/tree/master/Tracking)  
There are 5 tracking algorithms in OpenCV Tracking API. You can select one via command line parameters.  
**Running this demo needs extra parameters from the command line:**  
```
./opencv_exp trackerName {-vid | -img} { <video filename> | <dir name>
```
The parameter 'trackerName' can be one of the following:
<ul>
<li> Boosting</li>
<li> KCF</li>
<li> MedianFlow</li>
<li> MIL</li>
<li> TLD</li>
</ul>

For example  
**to use KCF tracker & video file:**
```
./opencv_exp KCF -vid test.mp4
```
**to use KCF tracker & image sequence:**
```
./opencv_exp KCF -img test
```
