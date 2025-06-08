#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
///////////////  Resize and Crop //////////////////////

//void main() {
//
//	// Blank Image 
//	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
//	rectangle(img, Point(100, 100), Point(300, 300), Scalar(0, 0, 0), 10);
//
//	circle(img, Point(150, 160), 20, Scalar(0, 69, 255), 10);
//	circle(img, Point(250, 160), 20, Scalar(0, 69, 255), 10);
//
//	line(img, Point(150, 200), Point(250, 200), Scalar(0, 69, 255), 2);
//
//	putText(img, "BLok Head", Point(110, 70), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
//
//	imshow("Image", img);
//	waitKey(0);
//}


	