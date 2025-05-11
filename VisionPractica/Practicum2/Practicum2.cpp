#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


//int main()
//{
//	std::string path = "Resources/bars.bmp";
//	cv::Mat img = cv::imread(path);
//	cv::Mat imgOpening, imgBlur, imgInv;
//
//	cv::bitwise_not(img, imgInv);
//
//	cv::GaussianBlur(imgInv, imgBlur, cv::Size(7, 7), 5, 0);
//
//	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10));
//	cv::morphologyEx(img, imgOpening, cv::MORPH_OPEN, kernel);
//	cv::imshow("Image", img);
//	cv::imshow("Image Opening", imgOpening);
//	cv::waitKey(0);
//
//
//}
