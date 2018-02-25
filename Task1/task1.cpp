#include<opencv2/opencv.hpp>
#include<iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;


int main() {
	cv::Mat img = cv::imread("rmlo2011_0.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//cout << "img = " << endl << " " << img << endl << endl;

	int rows = img.rows;
	int cols = img.cols;

	cv::Size s = img.size();
	rows = s.height;
	cols = s.width;

	cout << rows << " " << cols << endl;

	cout << rows << " " << cols << endl;
	cout << s << endl;

	cv::imshow("Before", img);

	for (int j = 0; j<img.rows; j++)
	{
		for (int i = 0; i<img.cols; i++)
		{
			if (i == j)
				img.at<uchar>(j, i) = 255; //white
		}
	}
	//After changing
	cv::imshow("After", img);

	waitKey(0);
	return 0;
}

