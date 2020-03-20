// 3.20-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;


int main()
{
	cv::Mat srcMat = imread("D:\\2.jpg",0);
	cv::Mat binar;
	cv::Mat label, stats, centr, open;
	threshold(srcMat, binar,100, 255,THRESH_BINARY_INV);
	cv::Mat kernal = getStructuringElement(MORPH_ELLIPSE, Size(9, 9));
	morphologyEx(binar, open, MORPH_OPEN, kernal);
	int nComps = connectedComponentsWithStats(open,label, stats, centr,8,CV_32S);
	for (int i = 0; i <nComps; i++) {
		Rect b;
		b.x = stats.at<int>(i, 0);
		b.y = stats.at<int>(i, 1);
		b.width = stats.at<int>(i, 2);
		b.height = stats.at<int>(i, 3);
		rectangle(open, b, CV_RGB(255, 255, 255), 1, 8, 0);
	}
	cout << "num =" << nComps - 1 << endl;
	imshow("结果", open);
	waitKey(0);
    return 0;
}

