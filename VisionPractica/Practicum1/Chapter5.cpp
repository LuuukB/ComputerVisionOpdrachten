#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Warp Images  //////////////////////

void main() {

	string path = "Resources/lambo.png";
	//string path = "Resources/paper.jpg";
	Mat img = imread(path);
	Mat matrix, imgWarp;
	float w = 700, h = 500;
	Point2f sourcePoints[4] = { {185,103},{492,278},{87,158},{403,364} };//lambo

	//Point2f sourcePoints[4] = { {380,442},{893,522},{90,1125},{920,1270} };
	Point2f destenation[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(sourcePoints, destenation);
	warpPerspective(img, imgWarp, matrix, Point(w, h));
	
	//for (int i = 0; i < 4; i++)
	//{
	//	circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	//}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);

}

