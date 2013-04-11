#include "tld_utils.h"
using namespace cv;
using namespace std;

void drawBox(Mat& image, CvRect box, Scalar color, int thick){
  rectangle( image, cvPoint(box.x, box.y), cvPoint(box.x+box.width,box.y+box.height),color, thick);
}

void drawPoints(Mat& image, vector<Point2f> points,Scalar color){
  for( vector<Point2f>::const_iterator i = points.begin(), ie = points.end(); i != ie; ++i )
      {
      Point center( cvRound(i->x ), cvRound(i->y));
      circle(image,*i,2,color,1);
      }
}

Mat createMask(const Mat& image, CvRect box){
  Mat mask = Mat::zeros(image.rows,image.cols,CV_8U);
  drawBox(mask,box,Scalar::all(255),CV_FILLED);
  return mask;
}

float median(vector<float> v)
{
    int n = floor((double)v.size() / 2);
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}

vector<int> index_shuffle(int begin,int end){
  vector<int> indexes(end-begin);
  for (int i=begin;i<end;i++){
    indexes[i]=i;
  }
  random_shuffle(indexes.begin(),indexes.end());
  return indexes;
}

void tldEqualizeHist(const Mat &src, Mat& dst){
  cvtColor(src, dst, CV_RGB2GRAY);
  //equalizeHist(dst,dst);
}

/**
 * Calculate the distance between two points
 **/
float Magnitude(Point2f first, Point2f last)
{
    return (float)sqrt( square(first.x-last.x) + square(first.y-last.y) );
}

/**
 * Calculate the distance between the point and line
 **/
int DistancePointLine( Point2f Point, Point2f LineStart, Point2f LineEnd, float &Distance )
{
    float LineMag;
    float U;
    Point2f Intersection;

    LineMag = Magnitude( LineEnd, LineStart );

    U = ( ( ( Point.x - LineStart.x ) * ( LineEnd.x - LineStart.x ) ) +
        ( ( Point.y - LineStart.y ) * ( LineEnd.y - LineStart.y ) ) ) /
        ( LineMag * LineMag );

    if( U < 0.0f || U > 1.0f )
        return 0;   // closest point does not fall within the line segment

    Intersection.x = LineStart.x + U * ( LineEnd.x - LineStart.x );
    Intersection.y = LineStart.y + U * ( LineEnd.y - LineStart.y );

    Distance = Magnitude( Point, Intersection );
    printf("Distance: %f\n",Distance);

    return 1;
}
