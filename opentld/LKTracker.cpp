/*
 *  Modified on: July 27, 2012
 *      By: DucLongHung NGUYEN
 */
#include "LKTracker.h"
using namespace cv;

LKTracker::LKTracker(){
  term_criteria = TermCriteria( TermCriteria::COUNT+TermCriteria::EPS, 20, 0.03);
  window_size = Size(7,7);
  level = 3;
  lambda = 0.5;
}


bool LKTracker::trackf2f(const Mat& img1, const Mat& img2,vector<Point2f> &points1, vector<cv::Point2f> &points2){
  //TODO!:implement c function cvCalcOpticalFlowPyrLK() or Faster tracking function
  ////////////////////////////
  //Forward-Backward tracking
  ////////////////////////////
  // Forward
  calcOpticalFlowPyrLK( img1,img2, points1, points2, status,similarity, window_size, level, term_criteria, lambda, 0);
  // Joint features tracking
  float avgLost=0;
  avgLost+=InterpolateTracking(points1, points2, status, 2.5, 5);
  // Backward
  calcOpticalFlowPyrLK( img2,img1, points2, pointsFB, FB_status,FB_error, window_size, level, term_criteria, lambda, 0);
  //Compute the real FB-error
  for( size_t i= 0; i<points1.size(); ++i ){
    FB_error[i] = norm(pointsFB[i]-points1[i]);
  }
  //Filter out points with FB_error[i] > median(FB_error) && points with sim_error[i] > median(sim_error)
  normCrossCorrelation(img1,img2,points1,points2);
  return filterPts(points1,points2);
}

void LKTracker::normCrossCorrelation(const Mat& img1,const Mat& img2, vector<Point2f>& points1, vector<Point2f>& points2) {
  Mat rec0(10,10,CV_8U);
  Mat rec1(10,10,CV_8U);
  Mat res(1,1,CV_32F);

  for (size_t i = 0; i < points1.size(); i++) {
    if (status[i] == 1) {
      getRectSubPix( img1, Size(10,10), points1[i],rec0 );
      getRectSubPix( img2, Size(10,10), points2[i],rec1);
      matchTemplate( rec0,rec1, res, CV_TM_CCOEFF_NORMED);
      similarity[i] = ((float *)(res.data))[0];

    } else {
      similarity[i] = 0.0;
    }
  }
  rec0.release();
  rec1.release();
  res.release();
}


bool LKTracker::filterPts(vector<Point2f>& points1,vector<Point2f>& points2){
  //Get Error Medians
  simmed = median(similarity);
  fbmed = median(FB_error);
  size_t i, k;
  for( i=k = 0; i<points2.size(); ++i ){
    if( !status[i])
      continue;
    if(similarity[i]> simmed && FB_error[i] <= fbmed){
      points1[k] = points1[i];
      points2[k] = points2[i];
      FB_error[k] = FB_error[i];
      k++;
    }
  }
  points1.resize(k);
  points2.resize(k);
  //FB_error.resize(k);
  if (k>0)
    return true;
  else
    return false;
}

/**
 * Get standard deviation squared distance
 **/
float LKTracker::GetStdDevSqDist(vector<Point2f> opsf, vector<Point2f> psf, float avg, vector<uchar> status, float *sqdists)
{
  int n=0;
  float stdev=0;
  float dx,dy,d;
  for(size_t i=0; i<opsf.size(); i++)
  {
    if (status.size() && !status[i])
      continue;
    n++;
    if (!sqdists)
    {
      dx=psf[i].x-opsf[i].x;
      dy=psf[i].y-opsf[i].y;
      d = sqrt(dx*dx + dy*dy);
    }
    else
      d = sqdists[i];
    stdev += (d-avg)*(d-avg);
  }
  return sqrt ((float)( stdev / (n ? n : 1) ));
}

/**
 * Get Average displacement distance
 **/
float LKTracker::GetAvgSqDist(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> status, float *sqdists)
{
  int n=0;
  float avgsqdist=0;
  float dx,dy,d;
  for(size_t i=0; i<opsf.size(); i++)
  {
    if (status.size() && !status[i])
      continue;
    n++;
    dx=psf[i].x-opsf[i].x;
    dy=psf[i].y-opsf[i].y;
    d = sqrt(dx*dx + dy*dy);
    avgsqdist+=d;
    if (sqdists)
      sqdists[i]=d;
  }
  return avgsqdist / (n ? n : 1);
}

/**
 * Get Average displacement
 **/
Point2f LKTracker::GetAvgDisp(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> status)
{
  int n=0;
  Point2f avgdisp=Point2f(0,0);
  for(size_t i=0; i<opsf.size(); i++)
  {
    if (status.size() && !status[i])
      continue;
    n++;
    avgdisp.x += (psf[i].x-opsf[i].x);
    avgdisp.y += (psf[i].y-opsf[i].y);
  }
  avgdisp.x /= (n ? n : 1);
  avgdisp.y /= (n ? n : 1);
  return avgdisp;
}

/**
 * Estimate local/adaptive average displacements for lost points
 **/
void LKTracker::GetRunningAvgDisp(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> status,
                                  int intwin, bool intwin_checkall, Point2f* avgDisps, float fixOutliers)
{
  int np=opsf.size();
  float dx,dy,d;
  memset(avgDisps, 0, np*sizeof(Point2f));

  for (int i=0; i<np; i++)
  {
    if (status[i] && fixOutliers==0)
      continue;
    std::priority_queue<ScoredIndex, std::vector<ScoredIndex>, ScoredIndexPriority> neighs;
    bool need_neighs=true;
    if (status[i])
      neighs.push(ScoredIndex(0,i));
    for (int k=1; k<np/2 && need_neighs; k++)
    {
      for (int kk=0; kk<2; kk++){
        int j=i+(kk ? 1:-1)*k;
        if (j < 0) j = (j+np)%np;
        if (j < 0) j = 0;
        if (j > np-1) j %= np;
        if (!status[j])
          continue;
        dx=opsf[j].x-opsf[i].x;
        dy=opsf[j].y-opsf[i].y;
        d = dx*dx + dy*dy;
        if(neighs.size() == (size_t)intwin && (neighs.top().score>d))
          neighs.pop();
        if(neighs.size() < (size_t)intwin)
          neighs.push(ScoredIndex(d,j));
        if( intwin_checkall && k>=intwin && neighs.size() >= (size_t)intwin)
        {
          need_neighs=false;
          break;
        }
      }
    }
    avgDisps[i]=Point2f(0,0);
    int numNeighs=neighs.size();
    std::vector<ScoredIndex> ns;
    while(neighs.size())
    {
      ScoredIndex si = neighs.top();
      ns.push_back(si);
      neighs.pop();
      int j = si.index;
      dx=psf[j].x-opsf[j].x;
      dy=psf[j].y-opsf[j].y;
      avgDisps[i].x += dx;
      avgDisps[i].y += dy;
    }
    if (numNeighs)
    {
      avgDisps[i].x /= numNeighs;
      avgDisps[i].y /= numNeighs;
    }
  }
}

/**
 * fix outliers using standard deviation of shift
 * interpolate lost points using mean-shift of those not lost
 * return: number of interpolations
 **/
int LKTracker::InterpolateTracking(vector<Point2f> opsf, vector<Point2f> psf, vector<uchar> &status, float fixOutliers, int intwin)
{
  int i,numLost=0,np=opsf.size();
  if (status.size())
    for (i=0; i<np; i++)
    {
      if(!status[i])
        numLost++;
    }

  if (!numLost && !fixOutliers)
    return 0;

  if (fixOutliers)
  {
    // Calculate outliers using displacement distance
    float *sqdists = (float *)malloc(np * sizeof(float)); //displacement distances
    float avgsqdist = GetAvgSqDist(opsf,psf,status,sqdists);
    float stdev3 = fixOutliers * GetStdDevSqDist(opsf,psf,avgsqdist,status,sqdists);
    for(int i=0; i<np; i++)
    {
      if (!status[i])
        continue;
      if (fabs(sqdists[i] - avgsqdist) > stdev3)
        status[i]=0;
    }
    free (sqdists); sqdists=NULL;
  }

  numLost=0;
  if (intwin)
  {
    Point2f *avgdisps = (Point2f *)malloc(np * sizeof(Point2f));
    GetRunningAvgDisp(opsf,psf,status,intwin,true,avgdisps,fixOutliers);
    for(i=0; i<np; i++)
    {
      if (!status[i])
      {
        psf[i].x = opsf[i].x + avgdisps[i].x;
        psf[i].y = opsf[i].y + avgdisps[i].y;
        status[i]=1;
        numLost++;
      }
    }
    free(avgdisps); avgdisps=NULL;
  }
  else
  {
    // Fill-in missing values using average displacement in x/y directions
    Point2f avgdisp = GetAvgDisp(opsf,psf,status);
    for(i=0; i<np; i++)
    {
      if (!status[i])
      {
        psf[i].x = opsf[i].x + avgdisp.x;
        psf[i].y = opsf[i].y + avgdisp.y;
        status[i]=1;
        numLost++;
      }
    }
  }
  return numLost;
}

/*
 * old OpenCV style
void LKTracker::init(Mat img0, vector<Point2f> &points){
  //Preallocate
  //pyr1 = cvCreateImage(Size(img1.width+8,img1.height/3),IPL_DEPTH_32F,1);
  //pyr2 = cvCreateImage(Size(img1.width+8,img1.height/3),IPL_DEPTH_32F,1);
  //const int NUM_PTS = points.size();
  //status = new char[NUM_PTS];
  //track_error = new float[NUM_PTS];
  //FB_error = new float[NUM_PTS];
}


void LKTracker::trackf2f(..){
  cvCalcOpticalFlowPyrLK( &img1, &img2, pyr1, pyr1, points1, points2, points1.size(), window_size, level, status, track_error, term_criteria, CV_LKFLOW_INITIAL_GUESSES);
  cvCalcOpticalFlowPyrLK( &img2, &img1, pyr2, pyr1, points2, pointsFB, points2.size(),window_size, level, 0, 0, term_criteria, CV_LKFLOW_INITIAL_GUESSES | CV_LKFLOW_PYR_A_READY | CV_LKFLOW_PYR_B_READY );
}
*/

