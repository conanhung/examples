#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>

#include "tld_utils.h"
#include "TLD.h"

using namespace cv;
using namespace std;

/*
./run_tld -p ../parameters.yml -b ../datasets/11_tavi/init.txt -s ../datasets/11_tavi/tavi.mov -tl
*/

//Global variables
Rect box;
Rect roi;
bool drawing_box = false;
bool gotBB = false;
bool gotROI = false;
bool tl = false;
bool rep = false;
bool fromfile=false;
bool fromfolder=false;
string video;
string folder;

void readBB(char* file){
  FILE *fp = fopen(file,"r");
  int rx,ry,rw,rh;
  int x1,y1,x2,y2;
  // roi
  {
    if( fscanf(fp, "roi:%d,%d,%d,%d\n", &rx, &ry, &rw, &rh) == 4 ){
      roi = Rect(rx,ry,rw,rh);
      gotROI = true;
    }
  }
  // box
  {
    if( fscanf(fp, "bbox:%d,%d,%d,%d\n", &x1, &y1, &x2, &y2) == 4 ){
      box = Rect(x1-rx,y1-ry,x2-x1,y2-y1);
      gotBB = true;
    }
  }
}

//bounding box mouse callback
void mouseHandler(int event, int x, int y, int /*flags*/, void */*param*/){
  switch( event ){
    case CV_EVENT_MOUSEMOVE:
      if (drawing_box){
        box.width = x-box.x;
        box.height = y-box.y;
      }
      break;
    case CV_EVENT_LBUTTONDOWN:
      drawing_box = true;
      box = Rect( x, y, 0, 0 );
      break;
    case CV_EVENT_LBUTTONUP:
      drawing_box = false;
      if( box.width < 0 ){
        box.x += box.width;
        box.width *= -1;
      }
      if( box.height < 0 ){
        box.y += box.height;
        box.height *= -1;
      }
      gotBB = true;
      break;
  }
}

void print_help(char** argv){
  printf("use:\n     %s -p /path/parameters.yml\n",argv[0]);
  printf("-s    source video\n-b        bounding box file\n-tl  track and learn\n-r     repeat\n");
}

void read_options(int argc, char** argv,VideoCapture& capture,FileStorage &fs){
  for (int i=0;i<argc;i++){
    if (strcmp(argv[i],"-b")==0){
      if (argc>i){
        readBB(argv[i+1]);
        gotBB = true;
      }
      else
        print_help(argv);
    }
    if (strcmp(argv[i],"-s")==0){
      if (argc>i){
        video = string(argv[i+1]);
        capture.open(video);
        fromfile = true;
      }
      else
        print_help(argv);
    }
    if (strcmp(argv[i],"-f")==0){
      if (argc>i){
        folder = string(argv[i+1]);
        fromfolder = true;
      }
      else
        print_help(argv);
    }
    if (strcmp(argv[i],"-p")==0){
      if (argc>i){
        fs.open(argv[i+1], FileStorage::READ);
      }
      else
        print_help(argv);
    }
    if (strcmp(argv[i],"-tl")==0){
      tl = true;
    }
    if (strcmp(argv[i],"-r")==0){
      rep = true;
    }
  }
}

bool fexists(const char *filename)
{
  ifstream ifile(filename);
  return ifile;
}

bool loadImage(Mat &image, int number, const string &folder)
{
  // Store path to directory
  char filename[100];
  strcpy(filename, folder.c_str());
  // Convert integer to char
  char frameNo[10];
  sprintf(frameNo, "%03i", number);
  // Combine to generate path
  strcat(filename, frameNo);
  strcat(filename, ".png");
  if(!fexists(filename))
    return false;
  // Use path to load image
  image = imread(filename);
  return true;
}

void updatePlan(Line &plan, BoundingBox obox, BoundingBox nbox)
{
  Point2f shift;
  shift.x = (nbox.x+nbox.width/2)-(obox.x+obox.width/2);
  shift.y = (nbox.y+nbox.height/2)-(obox.y+obox.height/2);
  // update vplan
  plan.start.x = plan.start.x+shift.x;
  plan.start.y = plan.start.y+shift.y;
  plan.end.x = plan.end.x+shift.x;
  plan.end.y = plan.end.y+shift.y;
}

/**
  * @function Morphology_Operations
  */
void morphology( const Mat &src, Mat &dst,int operation = MORPH_CLOSE, int morph_elem = MORPH_ELLIPSE, int morph_size = 6 )
{
  Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
  // Apply the specified morphology operation
  morphologyEx( src, dst, operation, element );
}

/**
  * @main
  */
int main(int argc, char * argv[]){
  VideoCapture capture;
  FileStorage fs;
  // Read options
  //read_options(argc,argv,capture,fs);
  
  // HACK read option

  fs.open("parameters.yml", FileStorage::READ);
  capture.open("data//men_jac.mov");

  roi = Rect(237,218,120,120);
  box = Rect(287-237,260-218,35,24);
  gotBB = true;
  fromfile = true;
  tl=true;

  printf("Initial ROI = x:%d y:%d w:%d h:%d\n",roi.x,roi.y,roi.width,roi.height);
  // Init camera
  if(!fromfolder)
    if (!capture.isOpened())
    {
      cout << "capture device failed to open!" << endl;
      return 1;
    }
  //Register mouse callback to draw the bounding box
  cvNamedWindow("Frames",CV_WINDOW_AUTOSIZE);
  cvSetMouseCallback( "Frames", mouseHandler, NULL );
  //Windows to show the learned templates
  cvNamedWindow("detections",CV_WINDOW_NORMAL);
  //TLD framework
  TLD tld;
  //Read parameters file
  tld.read(fs.getFirstTopLevelNode(),Size(box.width,box.height));
  Mat orig;
  Mat frame;
  Mat last_gray;
  Mat first;
  if (fromfolder){
    loadImage(orig,0,folder);
    cvtColor(orig, last_gray, CV_RGB2GRAY);
    orig(roi).copyTo(first);
  }
  else if (fromfile){
    capture >> orig;
    cvtColor(orig, last_gray, CV_RGB2GRAY);
    orig(roi).copyTo(first);
  }else{
    capture.set(CV_CAP_PROP_FRAME_WIDTH,340);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,240);
  }

  first.copyTo(frame);
  cvtColor(frame, last_gray, CV_RGB2GRAY);

  ///Initialization
GETBOUNDINGBOX:
  while(!gotBB)
  {
    first.copyTo(frame);
    cvtColor(frame, last_gray, CV_RGB2GRAY);
    drawBox(frame,box);
    imshow("Frames", frame);
    if (cvWaitKey(30) == 'q')
      return 0;
  }
  if (min(box.width,box.height)<(int)fs.getFirstTopLevelNode()["min_win"]){
    cout << "Bounding box too small, try again." << endl;
    gotBB = false;
    goto GETBOUNDINGBOX;
  }
  //Remove callback
  cvSetMouseCallback( "Frames", NULL, NULL );
  //Save roi and bbox to init.txt
  FILE  *init_file = fopen("init.txt","w");
  fprintf(init_file,"roi:%d,%d,%d,%d\n",roi.x,roi.y,roi.width,roi.height);
  fprintf(init_file,"bbox:%d,%d,%d,%d\n",box.x+roi.x,box.y+roi.y,box.width+box.x+roi.x,box.y+roi.y+box.height);
  fclose(init_file);
  printf("Initial Bounding Box = x:%d y:%d h:%d w:%d\n",box.x,box.y,box.width,box.height);
  //Output file
  FILE  *bb_file = fopen("bounding_boxes.txt","w");

  /// TLD initialization
  tld.init(last_gray,box,bb_file);

  /// Run-time
  Mat current_gray;
  BoundingBox obox = box;
  BoundingBox pbox;
  vector<Point2f> pts1;
  vector<Point2f> pts2;
  bool status=true;
  int frames = 1;
  int detections = 1;
REPEAT:
  int imgnum = 1;
  while(true){
    if(fromfolder){
      if(!loadImage(orig,imgnum,folder))
        break;
    }
    else{
      if(!capture.read(orig))
        break;
    }
    // get frame
    frame = orig(roi);
    cvtColor(frame, current_gray, CV_RGB2GRAY);
    /// Process Frame
    // begin measure processing time
    double t = (double)getTickCount();
    // process frame
    tld.processFrame(last_gray,current_gray,pts1,pts2,pbox,status,tl,bb_file);
    obox = pbox;
    // end measure processing time
    t=(double)getTickCount()-t;
    printf("Processing time = %gms\n", t*1000/getTickFrequency());
    /// Draw Points
    if (status){
      //drawPoints(frame,pts1);
      //drawPoints(frame,pts2,Scalar(0,255,0));
      drawBox(orig,cvRect(pbox.x+roi.x,pbox.y+roi.y,pbox.width,pbox.height),Scalar(0,0,255));
      detections++;
    }
    /// Draw ROI
    drawBox(orig,roi,Scalar(255,0,0));
    /// Display
    imshow("Frames", orig);
    /// Swap points and images
    swap(last_gray,current_gray);
    pts1.clear();
    pts2.clear();
    frames++;
    imgnum++;
    printf("Detection rate: %d/%d\n",detections,frames);
    if (cvWaitKey(30) == 'q')
      break;
  }
  if (rep){
    rep = false;
    tl = true;
    //fclose(bb_file);
    //bb_file = fopen("final_detector.txt","w");
    //capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
    if(!fromfolder){
      capture.release();
      capture.open(video);
    }
    goto REPEAT;
  }
  fclose(bb_file);
  cvWaitKey(0);
  return 0;
}


//----------------------------------------------------------------------------------------
//      if(gotLine){
//          Mat diff_gray;
//          Mat img1,img2;
//          first.copyTo(img1);
//          frame.copyTo(img2);
//          cvtColor(img1, img1, CV_RGB2GRAY);
//          GaussianBlur(img1,img1,Size(9,9),1.5);
//          cvtColor(img2, img2, CV_RGB2GRAY);
//          GaussianBlur(img2,img2,Size(9,9),1.5);
//          diff_gray=img1-img2;
//          threshold(diff_gray,diff_gray,7,255,THRESH_BINARY);
//          morphology(diff_gray,diff_gray,MORPH_OPEN,MORPH_ELLIPSE,2);
//          //    char frameNo[10];
//          //    sprintf(frameNo, "%03i", frames);
//          //    strcat(frameNo, ".png");
//          //    imwrite( frameNo, diff_gray );
//          //    imshow("diff",diff_gray);

//          /// Find the contours
//          vector<vector<Point> > contours;
//          vector<Vec4i> hierarchy;
//          findContours( diff_gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

//          /// Get the moments
//          vector<Moments> mu(contours.size() );
//          for( size_t i = 0; i < contours.size(); i++ )
//            { mu[i] = moments( contours[i], false ); }

//          ///  Get the mass centers:
//          vector<Point2f> mc( contours.size() );
//          for( size_t i = 0; i < contours.size(); i++ )
//            { mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }
//          for( size_t i = 0; i< contours.size(); i++ )
//            {
//              printf(" * Contour[%d] - Area (M_00) = %.2f - Area OpenCV: %.2f - Length: %.2f \n", i, mu[i].m00, contourArea(contours[i]), arcLength( contours[i], true ) );
//              Scalar color = Scalar( 255,0,0 );
//              /// @ Area filter
//              if(contourArea(contours[i])>10 && contourArea(contours[i])<500)
//                {
//                  /// @ Distance to guide line filter
//                  float minDist;
//                  if(DistancePointLine(mc[i],gline.LineStart,gline.LineEnd,minDist)){
//                      if(minDist<10.0){
//                          /// @ Found better bbox
//                          //                      pbox.x = mc[i].x-box.width/2;
//                          //                      pbox.y = mc[i].y-box.height/2;
//                          //                      pbox.width = box.width;
//                          //                      pbox.height = box.height;
//                          drawContours( frame, contours, i, color, 2, 8, hierarchy, 0, Point() );
//                          circle( frame, mc[i], 1, color, -1, 8, 0 );
//                          fprintf(blob_file,"%d,%f,%f\n",frames,mc[i].x,mc[i].y);
//                        }
//                    }
//                }
//            }
//        }


//----------------------------------------------------------------------------------------------
//  //Kalman filter
//  KalmanFilter KF(6, 4, 0);
//  Mat state(6, 1, CV_32F);
//  Mat_<float> measurement(4,1); measurement.setTo(Scalar(0));
//  KF.transitionMatrix = *(Mat_<float>(6, 6) <<  1, 0, 0, 0, 1, 0,
//                                                0, 1, 0, 0, 0, 1,
//                                                0, 0, 1, 0, 1, 0,
//                                                0, 0, 0, 1, 0, 1,
//                                                0, 0, 0, 0, 1, 0,
//                                                0, 0, 0, 0, 0, 1);
//  setIdentity(KF.measurementMatrix);
//  float a = 1e-2;
//  KF.processNoiseCov = *((Mat_<float>(6, 6) <<  1/4*a,  0,      0,      0,      1/2*a,  0,
//                                                 0,     1/4*a,  0,      0,      0,      1/2*a,
//                                                 0,     0,      1/4*a,  0,      1/2*a,  0,
//                                                 0,     0,      0,      1/4*a,  0,      1/2*a,
//                                                1/2*a,  0,      1/2*a,  0,      1*a,    0,
//                                                 0,     1/2*a,  0,      1/2*a,  0,      1*a));
//  setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));
//  setIdentity(KF.errorCovPost, Scalar::all(1));
//  //Kalman initialization
//  KF.statePre.at<float>(0) = box.x;
//  KF.statePre.at<float>(1) = box.y;
//  KF.statePre.at<float>(2) = box.x+box.width;
//  KF.statePre.at<float>(3) = box.y+box.height;
//  KF.statePre.at<float>(4) = 0;
//  KF.statePre.at<float>(5) = 0;
//    //Kalman step 1: predict
//    KF.predict();
//    //Kalman step 2: update (if measurement exists)
//    if (status){
//      measurement(0) = pbox.x;
//      measurement(1) = pbox.y;
//      measurement(2) = pbox.x+pbox.width;
//      measurement(3) = pbox.y+pbox.height;
//      state = KF.correct(measurement);
//    }
//    CvRect estBox = cvRect( state.at<float>(0),state.at<float>(1),
//                            state.at<float>(2)-state.at<float>(0),state.at<float>(3)-state.at<float>(1) );
//    //Draw Kalman box
//    drawBox(frame,estBox,Scalar(0,0,255));
