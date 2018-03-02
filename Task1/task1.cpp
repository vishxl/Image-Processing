
#include<opencv2/opencv.hpp>
#include<iostream>
#include<fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;


/*
Mat computeHistogram(Mat input_image) {
	Mat histogram = Mat::zeros(256, 1, CV_32S);
	for (int i = 0; i < input_image.rows; ++i) {
		for (int j = 0; j < input_image.cols; ++j) {
			int binIdx = (int)input_image.at<uchar>(i, j);
			histogram.at<int>(binIdx, 0) += 1;
		}
	}
	return histogram;
}

*/


/*
Mat computeHistogram(Mat input_image) {

	Mat histogram;
	int channels[] = { 0 };
	int histSize[] = { 3 };

	/*float lowRange[] = { 0, 100 };
	float midRange[] = { 101, 200 };
	float highRange[] = { 201, 256 };
	const float* ranges[] = { lowRange, midRange, highRange }; */

/*	float range[] = { 0,256 };
	const float* ranges[] = {range };
	calcHist(&input_image, 1, channels, Mat(), histogram, 1, histSize, ranges, true, false);

	

	return histogram;

}
*/


int main() {

	Mat img;
	int pixelSum = 0;
	char imgName[100];
	//int A[256];
	float prob[15], sumProb = 0;
	//int intensity[4];

	int histogram[15];
	for (int i = 0; i < 3; i++)
	{
		histogram[i] = 0;
	}
	int low = 0, mid = 0, high = 0;
	//int val = 0, i, j, th, Max = 0;
	ofstream outputFile;
	outputFile.open("PDF.txt");

	cout << "Enter image name:";
	cin >> imgName;
	outputFile << imgName << endl << "--------------------------------------- "<< endl;
	img = imread(imgName, CV_LOAD_IMAGE_GRAYSCALE);

	int rows = img.rows;
	int cols = img.cols;

	cv::Size s = img.size();
	rows = s.height;
	cols = s.width;

//	cout << rows << " " << cols << endl;
	cout << rows << " " << cols << endl;
	cout << s << endl;
	outputFile << s << endl;
	//switch (n)
	//{
	//case 1: // code to be executed if n = 1;
	
	for (int r = 0; r < img.rows; r++)
	{
		for (int c = 0; c < img.cols; c++)
		{
			int hist = img.at<uchar>(r, c);
			if (hist >= 0 && hist <= 100) {
				histogram[0] += 1;
			}
			else if (hist >= 101 && hist <= 200)
			{
				histogram[1] += 1;
			}
			else {
				histogram[2] += 1;
			
			}

			
			
		}
		
	}



	for (int c = 0; c < 3; c++)
	{
		
		cout <<"Bin ["<<c+1<<"] :"<< histogram[c] << endl;
		outputFile << "Bin [" << c + 1 << "] :" << histogram[c] << endl;
		pixelSum += histogram[c];

	}
	
	cout << "Sum = " << pixelSum << endl;
	outputFile << "Sum = " << pixelSum << endl;

	for (int c = 0; c < 3; c++)
	{
		prob[c] = ((float)histogram[c]/ (float)pixelSum);
		sumProb += prob[c];
		cout << "Bin " << c + 1 << " Probability :" << prob[c] << endl;
		outputFile << "Bin " << c + 1 << " Probability :" << prob[c] << endl;


	}
	cout << sumProb;
	outputFile << "Probability Sum = " << sumProb<<endl;
	outputFile.close();
	int hist_h = 700;
	int hist_w = 700;

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
	int max = histogram[0];
	for (int i = 1; i < 3; i++) {
		if (max < histogram[i]) {
			max = histogram[i];
		}
	}
	for (int i = 0; i < 3; i++) {
		histogram[i] = ((double)histogram[i] / max)*histImage.rows;
	}

	int bin_w = cvRound((double)hist_w / 3);
	for (int i = 0; i < 3; i++)
	{
		line(histImage, Point(bin_w*(i), hist_h),
			Point(bin_w*(i), hist_h - histogram[i]),
			Scalar(0, 0, 0), 20, 8, 0);
	
	}

/*
	break;
	case 2: // code to be executed if n = 2;
		


		for (int r = 0; r < original.rows; r++)
		{
			for (int c = 0; c < original.cols; c++)
			{
				int pixel = original.at<uchar>(r, c);
				if (pixel >= 0 && pixel <= 25) {
					histogram[0] = histogram[0] + 1;
				}
				else if (pixel >= 26 && pixel <= 50)
				{
					histogram[1] = histogram[1] + 1;
				}
				else if (pixel >= 51 && pixel <= 75)
				{
					histogram[2] = histogram[2] + 1;
				}
				else if (pixel >= 76 && pixel <= 100)
				{
					histogram[3] = histogram[3] + 1;
				}
				else if (pixel >= 101 && pixel <= 125)
				{
					histogram[4] = histogram[4] + 1;
				}
				else if (pixel >= 126 && pixel <= 150)
				{
					histogram[5] = histogram[5] + 1;
				}
				else if (pixel >= 151 && pixel <= 175)
				{
					histogram[6] = histogram[6] + 1;
				}
				else if (pixel >= 176 && pixel <= 200)
				{
					histogram[7] = histogram[7] + 1;
				}
				else if (pixel >= 201 && pixel <= 225)
				{
					histogram[8] = histogram[8] + 1;
				}
				else if (pixel >= 226 && pixel <= 250)
				{
					histogram[9] = histogram[9] + 1;
				}
				else if (pixel >= 251 && pixel <= 255)
				{
					histogram[10] = histogram[10] + 1;
				}
				outputFile << pixel << " ";
			}
			outputFile << "\n\n\n";
		}
		outputFile.close();
		int hist_h = 512;
		int hist_w = 400;
		Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));
		int max = histogram[0];
		for (int i = 1; i < 11; i++) {
			if (max < histogram[i]) {
				max = histogram[i];
			}
		}
		for (int i = 0; i < 11; i++) {
			histogram[i] = ((double)histogram[i] / max)*histImage.rows;
		}

		int bin_w = cvRound((double)hist_w / 11);
		for (int i = 0; i < 11; i++)
		{
			line(histImage, Point(bin_w*(i), hist_h),
				Point(bin_w*(i), hist_h - histogram[i]),
				Scalar(0, 0, 0), 5, 8, 0);
		}

		namedWindow("Intensity Histogram", CV_WINDOW_AUTOSIZE);
		imshow("Intensity Histogram", histImage);



		break;
	default: // code to be executed if n doesn't match any cases
	}

	*/

	//copyMakeBorder(histImage, histImage, 20, 20, 20, 20, BORDER_CONSTANT);
	cv::putText(histImage,
		"Mammogram intensity histogram",
		cv::Point(20,20),
		cv::FONT_HERSHEY_COMPLEX_SMALL, 
		1, // Scale
		cv::Scalar(0, 0, 0),
		1, // Thickness
		CV_AA); // Anti-alias

	namedWindow("Intensity Histogram", CV_WINDOW_AUTOSIZE);
	imshow("Intensity Histogram", histImage);

	
	//cv::imshow("Original", img);


	waitKey(0);
	return 0;
}














	//cv::Mat img = cv::imread("rmlo2011_0.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	//cout << "img = " << endl << " " << img << endl << endl;

	
	//Mat histogram = computeHistogram(img);
/*
	cout << "Histogram...\n";
	for (int i = 0; i < histogram.rows; ++i) {
		cout << i << " : " << histogram.at<int>(i, 0) << "\n";
		intensity[i] = histogram.at<int>(i, 0);
		
	}
/*

	for (i = 0; i < 3; i++) {
		if (intensity[i] > Max){
			Max = intensity[i];
		}

	}
		

	

	namedWindow("Histogram", WINDOW_NORMAL);

		Mat hist(400, 300, CV_8UC3, Scalar(255, 255, 255));

		int key = Max / 400;
		for (i = 0; i <= 400; i++)
		{
			for (j = 0; j<300; j++)
				if (i>400 - intensity[(int)j/100] / key)
				{
					hist.at<Vec3b>(i, j )[0] = 0;
					hist.at<Vec3b>(i, j)[1] = 0;
					hist.at<Vec3b>(i, j)[2] = 255;
				}
		}


		imshow("Histogram", hist);

		*/





	/*

	for(i = 0 ; i<img.row; i++){
		for(j = 0 ; j< img.cols;j++){
		   Mat histo =  histogram.at<int>(i, 0);

		   if(histo > 0 && histo < 100)
				first += first;













	*/


	

	/*
	int arr[49], key1 = 0;

	for (int i = 3; i<img.rows - 3; i++)
	{
		for (int j = 3; j<img.cols - 3; j++)
		{
			key1 = 0;
			for (int k = -3; k <= 3; k++)
			{
				for (int l = -3; l <= 3; l++)
				{
					arr[key1++] = img.at<uchar>(i + k, j + l);
				}

			}
			sort(arr, arr + 49);
			img.at<uchar>(i, j) = arr[24];

		}
	}
	
	*/
/*
	//namedWindow("After Median", WINDOW_AUTOSIZE);
	//imshow("After Median", img);
	//cv::Size z = img.size();
	rows = s.height;
	cols = s.width;
	cout << z << endl;
	imwrite("normalized.jpg", img); */




