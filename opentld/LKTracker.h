/*
 *  Modified on: July 27, 2012
 *      By: DucLongHung NGUYEN
 */
#include "tld_utils.h"
#include <opencv2/opencv.hpp>
#include <queue>
#include <vector>

using namespace cv;
using namespace std;

class LKTracker{
private:
  std::vector<cv::Point2f> pointsFB;
  cv::Size window_size;
  int level;
  std::vector<uchar> status;
  std::vector<uchar> FB_status;
  std::vector<float> similarity;
  std::vector<float> FB_error;
  float simmed;
  float fbmed;
  cv::TermCriteria term_criteria;
  float lambda;
  void normCrossCorrelation(const cv::Mat& img1,const cv::Mat& img2, std::vector<cv::Point2f>& points1, std::vector<cv::Point2f>& points2);
  bool filterPts(std::vector<cv::Point2f>& points1,std::vector<cv::Point2f>& points2);
public:
  LKTracker();
  bool trackf2f(const cv::Mat& img1, const cv::Mat& img2,
                std::vector<cv::Point2f> &points1, std::vector<cv::Point2f> &points2);
  float getFB(){return fbmed;}
  float GetStdDevSqDist(vector<Point2f> opsf, vector<Point2f> psf, float avg, vector<uchar> status, float *sqdists);
  float GetAvgSqDist(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> status, float *sqdists);
  Point2f GetAvgDisp(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> status);
  void GetRunningAvgDisp(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> status,
                         int intwin, bool intwin_checkall, Point2f* avgDisps, float fixOutliers);
  int InterpolateTracking(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> &status, float fixOutliers, int intwin);
};

class ScoredIndex
{
public:
    float score;
    int index;
    ScoredIndex(float score_, int index_): score(score_), index(index_) {}
};

class ScoredIndexPriority
{
public:
    int operator()( const ScoredIndex& a, const ScoredIndex& b)
    {
        return a.score < b.score;
    }
};
