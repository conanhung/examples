#include "ImproveContoursPlugin.h"
#include "Util.h"

ImproveContoursPlugin::ImproveContoursPlugin( wxWindow* parent_, CaptureManager *cm_ ): PluginBase(GetStaticName(), parent_, cm_, true, true) {
	sidebar =  new ImproveContoursSidebar(parent_, this);
	sidebarw = sidebar;
	gray = NULL;
	edge = NULL;
	DoPreview();
}
ImproveContoursPlugin::~ImproveContoursPlugin()
{
	if (gray)
		cvReleaseImage(&gray);
	if (edge)
		cvReleaseImage(&edge);
}
int ImproveContoursPlugin::GetScope()
{
	return sidebar->scope->GetSelection() ? 1 : 0;
}
bool ImproveContoursPlugin::IsPreviewOn(){
	return sidebar->IsPreviewOn();
}
void ImproveContoursPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	if (!sidebar->GetClean())
		cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img);
	cm->Redraw(false);
}
void ImproveContoursPlugin::ProcessImage( ImagePlus *img ){
	IplImage *orig = img->orig;
	if ( gray && !cvSizeEquals(gray,orig) ) {
		cvReleaseImage( &gray );
		cvReleaseImage( &edge );
	}
	if (!gray){
		gray = cvCreateImage( cvSize(orig->width, orig->height), 8, 1 );
		edge = cvCreateImage( cvSize(orig->width, orig->height), 8, 1 );
	}
	cvCvtColor(orig, gray, CV_BGR2GRAY);
	cvCanny( gray, edge, sidebar->GetThresh1(), sidebar->GetThresh2(), sidebar->GetAperture() );
	cvDilate( edge, edge, NULL, sidebar->GetDilations() );
	CvSeq *seq;
	cvImproveContours( edge, img->CreateContoursStorageOnDemand(sidebar->GetClean()), &seq, sizeof(CvContour),
		CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0) );
	img->AddContours(seq);
}
