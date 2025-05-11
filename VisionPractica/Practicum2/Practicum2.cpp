#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


int main()
{
	std::string path = "Resources/bars.bmp";
	cv::Mat img = cv::imread(path);
	cv::Mat imgOpening, imgBlur, imgInv;

	cv::bitwise_not(img, imgInv);

	cv::GaussianBlur(imgInv, imgBlur, cv::Size(7, 7), 5, 0);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(4, 4));
	cv::morphologyEx(img, imgOpening, cv::MORPH_OPEN, kernel);
	cv::imshow("Image", img);
	cv::imshow("Image Opening", imgOpening);

	std::string path2 = "Resources/ballstripes.bmp";
	cv::Mat img2 = cv::imread(path2);
	cv::Mat imgInv2, imgOpening2, finalImage;

	cv::bitwise_not(img2, imgInv2);

	cv::morphologyEx(imgInv2, imgOpening2, cv::MORPH_OPEN, kernel);

	cv::bitwise_not(imgOpening2, finalImage);
	cv::imshow("Start image", img2);
	cv::imshow("Final image", finalImage);
	cv::waitKey(0);



}
