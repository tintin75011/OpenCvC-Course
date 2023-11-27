#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  wraps images  //////////////////////
void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Mat matrix, imgWrap;
	float w = 250;
	float h = 350;


	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };


	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWrap, matrix, Point(w, h));

	imshow("img", img);
	imshow("img_wraps", imgWrap);
	waitKey(0);

}

