//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
/////////////////  Basic Functions  //////////////////////
//
//int main() {
//
//	int th1 = 25, th2 = 75; // Threshold values for Canny edge detection
//
//	string path = "Resources/test.png";
//	string path2 = "Resources/lambo.png";
//	Mat img = imread(path);
//	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
//
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);
//	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
//	
//
//
//
//	namedWindow("Trackbars", (640, 200));
//		createTrackbar("Thershold 1", "Trackbars", &th1, 255);
//		createTrackbar("Thershold 2", "Trackbars", &th2, 255);
//
//
//	//Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//	//dilate(imgCanny, imgDil, kernel);
//	//erode(imgDil, imgErode, kernel);
//
//	//imshow("Image", img);
//	//imshow("Image Gray", imgGray);
//	//imshow("Image Blur", imgBlur);
//	//imshow("Image Canny", imgCanny);
//	//imshow("Image Dilation", imgDil);
//	//imshow("Image Erode", imgErode);
//	//waitKey(0);
//
//
//
//	while (true) {
//
//		Canny(imgBlur, imgCanny, th1, th2);
//
//		imshow("Image", img);
//		imshow("Image Canny", imgCanny);
//		waitKey(1);
//	}
//	return 0;
//}
//
//
