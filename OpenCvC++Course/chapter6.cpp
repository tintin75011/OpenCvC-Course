#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Color detection  //////////////////////

int main() {

    int hmin = 0, smin = 110, vmin = 153;
    int hmax = 19, smax = 240, vmax = 255;
    string path = "Resources/shapes.png";
    Mat img = imread(path);
    Mat imgHSV,mask;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    namedWindow("trackbar", (640, 200));
    createTrackbar("hue min", "trackbar", &hmin, 255);
    createTrackbar("hue max", "trackbar", &hmax, 255);
    createTrackbar("Sat min", "trackbar", &smin, 255);
    createTrackbar("Sat max", "trackbar", &smax, 255);
    createTrackbar("Val min", "trackbar", &vmin, 255);
    createTrackbar("val max", "trackbar", &vmax, 255);

    while (true) {

        
        Scalar lower(hmin, smin, vmin), upper(hmax, smax, vmax);;


        inRange(imgHSV, lower, upper, mask);


        imshow("Image", img);
        imshow("HSV", imgHSV);
        imshow("Mask", mask);
        waitKey(1);

    }

    return 0;
}