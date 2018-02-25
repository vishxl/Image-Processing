#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {

	cv::Mat img = cv::imread("rmlo2011_0.jpg", 0);
	for (int i = 0; i<img.rows; i++)
		for (int j = 0; i<img.cols; j++)
			std::cout << img.at<uchar>(i, j) << std::endl;
	waitKey(0);
	return 0;

}