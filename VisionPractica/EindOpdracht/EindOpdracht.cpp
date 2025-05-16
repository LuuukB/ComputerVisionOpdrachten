#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Project 3 - License Plate Detector //////////////////////

void getContours(Mat imgDil, Mat img);

void main() {

	Mat img;
	VideoCapture cap(0);

	CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

	if (plateCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> plates;

	while (true) {

		cap.read(img);
		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			Mat imgCrop = img(plates[i]);
			Mat imgGray, imgBlur, imgCanny, imgDil;
			//imshow(to_string(i), imgCrop);
			//imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
			cvtColor(imgCrop, imgGray, COLOR_BGR2GRAY);

			// Inverse threshold (zwarte letters op witte achtergrond)
			Mat imgThresh;
			threshold(imgGray, imgThresh, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);

			// Erode om aan elkaar plakkende letters te scheiden
			Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
			erode(imgThresh, imgThresh, kernel);

			// Geef deze door aan contourfunctie
			getContours(imgThresh, imgCrop);

			// Debug visueel
			imshow("Threshold", imgThresh);


			imshow("kenteken", imgCrop);
			imshow("grey", imgGray);
		}

		imshow("Image", img);
		waitKey(1);
	}
}

void getContours(Mat imgDil, Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	vector<Rect> charRects;

	findContours(imgDil, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	
	for (int i = 0; i < contours.size(); i++) {
		std::cout << "Contour " << i << ": " << contours[i].size() << std::endl;
		Rect boundingRect = cv::boundingRect(contours[i]);
		/*rectangle(img, boundingRect.tl(), boundingRect.br(), Scalar(255, 0, 255), 3);*/

		float aspectRatio = (float)boundingRect.width / boundingRect.height;
		int area = boundingRect.width * boundingRect.height;

		if (aspectRatio > 0.2 && aspectRatio < 1.0 && area > 100) {
			charRects.push_back(boundingRect);
		}
		
	}
	// Sorteer karakters van links naar rechts
	sort(charRects.begin(), charRects.end(), [](const Rect& a, const Rect& b) {
		return a.x < b.x;
		});

	// Karakters opslaan
	for (int j = 0; j < charRects.size(); j++) {
		for (int j = 0; j < charRects.size(); j++) {
			Rect r = charRects[j];

			// Veiligheidscheck: blijf binnen het plaatje
			r &= Rect(0, 0, img.cols, img.rows);

			Mat character = img(r); // Crop uit het kentekenbeeld

			string filename = "Resources/Plates/char_" + to_string(j + 1) + ".png";
			imwrite(filename, character);
		}

	}
}