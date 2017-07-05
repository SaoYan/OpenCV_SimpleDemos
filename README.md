# OpenCV_ToyExamples
Here are some simple demos to help you explore OpenCV. I hope you will have fun!

There are some tutorials for OpenCV beginners. TO see the tutorials, go to [here](http://mp.weixin.qq.com/mp/homepage?__biz=MzIxOTQ3MTI5NQ==&hid=9&sn=bc002ded707c2c4610a44d446b1b95a4#wechat_redirect).<br />

To follow my Public Account and see other tutorials, you can search Account name 'SaoYan' in Wechat.

## How to run the codes
```
git clone https://github.com/SaoYan/OpenCV_ToyExamples
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

## Histogram Calculation


## Histogram Back-projection
**HistBackProject V1**  
This demo is a simple use of histogram backprojection to detect an monochromatic (or nealy monochromatic) object.
The corresponding tutorial can be found [here](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483949&idx=1&sn=636cd5077c1749a5dfdaa3e6de14af74&scene=19#wechat_redirect).<br />
I provide one test image with the sample patch extracted from it. Be free to use you own test images! You may be wondering how to use you camera to run histogram back-projection online. We'll see how to do this in the following demos (refer to V4).  
You may find out that the outcome is very upsetting. We'll see the reason and try to modify it in [next tutorial](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483953&idx=1&sn=d733791678baaaa5dc910d41990db27c&scene=19#wechat_redirect).<br />(The corresponding demo will be 'V2')  
**HistBackProject V2**  
In this demo, HSV color space is used to improve the performance in V1.  
The corresponding tutorial can be found [here](https://mp.weixin.qq.com/s?__biz=MzIxOTQ3MTI5NQ==&mid=2247483953&idx=1&sn=d733791678baaaa5dc910d41990db27c&scene=19#wechat_redirect).<br />
**HistBackProject V3**  
This demo has the following modifications based on HistBackProject V2.
1. Morphology operation is used to enhance the target object in the binary image.
2. Extra contours and calculate bounding box.
