#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

// Global variables 
int slider1;
int slider2;
int slider3;
int iii;
// Callback function for trackbar event 
void on_trackbar1(int pos, void *)
{
	slider1 = pos;
}
void on_trackbar2(int pos, void *)
{
	slider2 = pos;
}
void on_trackbar3(int pos, void *)
{
	slider3 = pos;
}

int main()
{
	Mat image;
	image.create(256, 256, CV_8UC3);
	cvtColor(image, image, CV_BGR2HSV);
	const int size = 256;
	namedWindow("window");
	createTrackbar("Slider", "window", &slider1, 255, on_trackbar1);
	namedWindow("window2");
	createTrackbar("Slider", "window2", &slider2, 255, on_trackbar2);
	namedWindow("window3");
	createTrackbar("Slider", "window3", &slider3, 255, on_trackbar3);
	while (true) {
		for (int rows = 0; rows < size; rows++)
		{
			for (int column = 0; column < size; column++)
			{
				image.at<Vec3b>(rows, column)[0] = rows;
				image.at<Vec3b>(rows, column)[1] = column;
				image.at<Vec3b>(rows, column)[0] = slider1;
			}
			imshow("window", image);
		}
		for (int rows = 0; rows < size; rows++)
		{
			for (int column = 0; column < size; column++)
			{
				image.at<Vec3b>(rows, column)[0] = column;
				image.at<Vec3b>(rows, column)[1] = slider2;
				image.at<Vec3b>(rows, column)[0] = rows;
			}
			imshow("window2", image);
		}
		for (int rows = 0; rows < size; rows++)
		{
			for (int column = 0; column < size; column++)
			{
				image.at<Vec3b>(rows, column)[0] = slider3;
				image.at<Vec3b>(rows, column)[1] = rows;
				image.at<Vec3b>(rows, column)[0] = column;
			}
			imshow("window3", image);
		}
		if (waitKey(30) == 'q') break;
	}

	cout << "Hello HSV project!" << endl;
	return 0;
}