#include "FindContoursPlugin.h"
#include "Util.h"

FindContoursPlugin::FindContoursPlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true),
gray(NULL), edge(NULL)
{
	sidebar =  new FindContoursSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void FindContoursPlugin::ReleaseTemps()
{
	if (gray) cvReleaseImage(&gray);
	if (edge) cvReleaseImage(&edge);
}
int FindContoursPlugin::GetScope() {	return sidebar->scope->GetSelection() ? 1 : 0; }
bool FindContoursPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void FindContoursPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	if (!sidebar->clean->GetValue())
		cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img);
	cm->Redraw(false);
}
#include <vector>
void FindContoursPlugin::ProcessImage( ImagePlus *img ){
	ProcessImage_static(img, gray, edge, sidebar->thresh1->GetValue(), sidebar->thresh2->GetValue(), wxStringToLong(sidebar->aperture->GetStringSelection()), sidebar->dilate->GetValue(), sidebar->erode->GetValue(), sidebar->clean->GetValue(), sidebar->intra->GetSelection(), sidebar->approx->GetValue() );
}

void FindContoursPlugin::ProcessImage_static( ImagePlus *img, IplImage* &gray, IplImage* &edge, double thresh1, double thresh2, int aperture, int dilate, int erode, bool clean, bool all, bool approx ){
	IplImage *orig = img->orig;
	if (!gray)
		gray = cvCreateImage( cvSize(orig->width, orig->height), IPL_DEPTH_8U, 1 );
	if (!edge)
		edge = cvCreateImage( cvSize(orig->width, orig->height), IPL_DEPTH_8U, 1 );
	cvCvtColor(orig, gray, CV_BGR2GRAY);
	cvCanny( gray, edge, thresh1, thresh2, aperture );
	cvDilate( edge, edge, NULL, dilate );
	cvErode( edge, edge, NULL, erode );
	CvSeq *seq;
	cvFindContours( edge, img->CreateContoursStorageOnDemand(clean), &seq, sizeof(CvContour),
		all ? CV_RETR_LIST : CV_RETR_EXTERNAL,  approx ? CV_CHAIN_APPROX_SIMPLE : CV_CHAIN_APPROX_NONE , cvPoint(0,0) );
	img->AddContours(seq);
}