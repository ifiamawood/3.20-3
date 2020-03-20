// 3.20-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv.hpp>
#include<iostream>

using namespace cv;


int main()
{
	cv::Mat a = imread("D:\\coin.png", 0);
	cv::Mat b;
	cv::Mat c, d, s, result;
	int z;
	cv::threshold(a, b, 0, 255, THRESH_OTSU);
	for (int i = 1; i < z, i++) {
		Rect d;
		d.x = s.at<int>(i, 0);
		d.y = s.at<int>(i, 1);
		d.width = s.at<int>(i, 2);
		d.height = s.at<int>(i, 3);
		rectangle(result, d, CV_RGB(255, 255, 255), 1, 8, 0);
	}
	imshow("binary", );
	imshow("result", result);
	imshow("frame", a);
	moveWindow("frame", 0, 20);
	moveWindow("binary", a.cols, 20);
	moveWindow("result", a.cols * 2, 20);
    return 0;
}

