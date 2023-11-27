#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Basic Functions  //////////////////////
void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgBlur, imgGray, imgContour, imgCanny, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	Canny(img, imgCanny, 25, 75);
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);


	imshow("input", img);
	imshow("blur", imgBlur);
	imshow("Gray", imgGray);
	imshow("Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
}
