#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;

//this is a sample for foreground detection functions
int main(int argc, const char** argv)
{
    VideoCapture inputVideo;
  
  const string source = "/Users/duclonghungnguyen/Desktop/tavi_seq_test_2.mov";
  
    inputVideo.open(source);

    if( !inputVideo.isOpened() )
    {
        printf("can not open camera or video file\n");
        return -1;
    }
    
    //namedWindow("image", CV_WINDOW_NORMAL);
                                     
    Mat img;
  
  int i = 0;

    for(;;)
    {
        inputVideo >> img;
        
        if( img.empty() )
            break;
        
        //cvtColor(_img, img, COLOR_BGR2GRAY);
      rectangle(img,Rect(157,12,142,83),Scalar( 0, 0, 0 ),-1,8);
      rectangle(img,Rect(923,6,190,35),Scalar( 0, 0, 0 ),-1,8);
      
        //imshow("image", img);
      
      // Store path to directory
			char filename[100];
			strcpy(filename, "tavi_seq");
			// Convert integer to char
			char frameNo[10];
			sprintf(frameNo, "%05i", i);
			// Save file
			strcat(filename, frameNo);
			strcat(filename, ".png");
			imwrite(filename, img);
      
      printf("%d...",i);
      i++;

        //char k = (char)waitKey(30);
        //if( k == 27 ) break;
    }
  printf("All done\n");
    return 0;
}
