#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


///////////////  Resize and Crop //////////////////////

//void main() {
//
//	std::string path = "Resources/test.png";
//	cv::Mat img = cv::imread(path);
//	cv::Mat imgResize, imgCrop;
//
//	//cout << img.size() << endl;
//	resize(img, imgResize, cv::Size(), 1.5, 1.5);
//
//	cv::Rect roi(0, 150, 200, 200);
//	imgCrop = img(roi);
//
//	imshow("Image", img);
//	imshow("Image Resize", imgResize);
//	imshow("Image Crop", imgCrop);
//	cv::waitKey(0);
//}


