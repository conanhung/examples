#include "mycapture.h"


MyCapture_Files::MyCapture_Files(const wxArrayString& files_)
: MyCapture()
{
	files = files_;
	if(!(frame = cvLoadImage(files[0].c_str()))){
		wxLogError("Failed to read image file [ %s ]. Corrupt file or unsupported codec.", files[0]);
		return;
	}

	width = frame->width;
	height = frame->height;
	size = cvSize(width, height);
	frameCount = (int) files.GetCount();
	fps = 0;
	frame_flip = cvCreateImage(size,8,3);
}
MyCapture_Movie::MyCapture_Movie(const char* avi)
: MyCapture(), capture(NULL)
{
	frame_flip = NULL;
	if(!( capture = cvCaptureFromAVI(avi) )) {
		wxLogError("Failed to read movie file [ %s ]. Corrupt file or unsupported codec.", avi);
		return;
	}
	size = cvSize(cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
		cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
	width = size.width;
	height = size.height;
	frameCount = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
	frame_flip = cvCreateImage(size,8,3);
}
MyCapture::~MyCapture()
{
	if ( frame_flip )
		cvReleaseImage( &frame_flip );
}
MyCapture_Files::~MyCapture_Files(void)
{
	if (frame)
		cvReleaseImage(&frame);
}
MyCapture_Movie::~MyCapture_Movie()
{
	if ( capture )
		cvReleaseCapture( &capture );
}
void MyCapture::setPos(int pos_)
{
	if ( pos_ < 0 || pos_ >= frameCount )
		throw "invalid frame position";
	pos=pos_;
}
void MyCapture_Movie::setPos(int pos_)
{
	MyCapture::setPos(pos_);
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
}
// The frame is already queried in the derived classes. Here, we just set the
// image parameters from frame obtained upon the first queryFrame call.
IplImage* MyCapture::queryFrame(int pos_){
	if (!step) {
		unsigned char *raw;
		cvGetRawData(frame, &raw, &step);
	}
	return frame;
}
IplImage* MyCapture_Files::queryFrame(int pos_)
{
	if ( pos_ >= 0 )
		setPos(pos_);
	if ( pos >= frameCount )
		throw "no more frames left to query. position passed end of movie.";
	if (frame)
		cvReleaseImage(&frame);
	if (!(frame = cvLoadImage(files[pos].c_str()))) {
		wxLogError("Failed to read image file [ %s ]. Corrupt file or unsupported codec. Frame %d is replaced with a blank image.", files[0], pos);
		if (size.width)
			frame = cvCreateImage(size,8,3);
	}
	return MyCapture::queryFrame();
}
IplImage* MyCapture_Movie::queryFrame(int pos_){
	if ( pos_ >= 0 )
		setPos(pos_);
	if ( pos >= frameCount )
		throw "no more frames left to query. position passed end of movie.";
	frame = cvQueryFrame(capture);
	if ( frame->origin ){
		cvConvertImage( frame, frame_flip, CV_CVTIMG_FLIP | CV_CVTIMG_SWAP_RB );
		frame = frame_flip;
	}
	return MyCapture::queryFrame();
}
