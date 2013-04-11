#pragma once
#ifndef TLD_UTILS_H
#define TLD_UTILS_H

#include <opencv2/opencv.hpp>
#include <stdio.h>

static const double PI = 3.14159265358979323846;

inline static double square(int a)
{
    return a * a;
}

void drawBox(cv::Mat& image, CvRect box, cv::Scalar color = cvScalarAll(255), int thick=1);

void drawPoints(cv::Mat& image, std::vector<cv::Point2f> points,cv::Scalar color=cv::Scalar::all(255));

cv::Mat createMask(const cv::Mat& image, CvRect box);

float median(std::vector<float> v);

std::vector<int> index_shuffle(int begin,int end);

void tldEqualizeHist(const cv::Mat &src, cv::Mat& dst);

float Magnitude(cv::Point2f first, cv::Point2f last);

int DistancePointLine( cv::Point2f Point, cv::Point2f LineStart, cv::Point2f LineEnd, float &Distance );

#endif
