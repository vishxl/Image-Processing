#include<opencv2/opencv.hpp>
#include<iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;

int histSize = 3;    // bin size
float range[] = { 0, 255 };
const float *ranges[] = { range };

Mat computeHistogram(Mat input_image) {

	Mat histogram;
	int channels[] = { 0 };
	int histSize[] = { 256 };
	float range[] = { 0, 256 };
	const float* ranges[] = { range };

	calcHist(&input_image, 1, channels, Mat(), histogram, 1, histSize, ranges, true, false);

	return histogram;

} 
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

	Mat histogram = computeHistogram(img);

	cout << "Histogram...\n";
	for (int i = 0; i < histogram.rows; ++i)
		cout << i << " : " << histogram.at<int>(i, 0) << "\n";

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

