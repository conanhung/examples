#include "FindFeaturesPlugin.h"
#include "Util.h"

FindFeaturesPlugin::FindFeaturesPlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true),
gray(NULL), eig(NULL), cnt_mask(NULL), tempimg(NULL)
{
	sidebar =  new FindFeaturesSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void FindFeaturesPlugin::ReleaseTemps()
{
	if (gray) cvReleaseImage(&gray);
	if (eig) cvReleaseImage(&eig);
	if (cnt_mask) cvReleaseImage(&cnt_mask);
	if (tempimg) cvReleaseImage(&tempimg);
}
int FindFeaturesPlugin::GetScope() {	return sidebar->scope->GetSelection() ? 1 : 0; }
bool FindFeaturesPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void FindFeaturesPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	if (!sidebar->clean->GetValue())
		cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img);
	cm->Redraw(false);
}
void FindFeaturesPlugin::FetchParams()
{
	quality = MAX(0.0001,sidebar->quality->GetValue());
	minDist = MAX(0.0001,sidebar->minDist->GetValue());
	harrisK = sidebar->harrisK->GetValue();
	blockSize= 2*sidebar->blockSize->GetValue()+1;
	maxCount = sidebar->maxCount->GetValue();
	method = sidebar->method->GetSelection();
	clean = sidebar->clean->GetValue();
}
#include <vector>
void FindFeaturesPlugin::ProcessImage( ImagePlus *img ){
	FetchParams();
	IplImage *orig = img->orig;
	if (!gray){
		gray = cvCreateImage( cvGetSize(orig), IPL_DEPTH_8U, 1 );
		cnt_mask = cvCreateImage(cvGetSize(orig), IPL_DEPTH_8U, 1);
		eig = cvCreateImage( cvGetSize(orig), IPL_DEPTH_32F, 1 );
		tempimg = cvCreateImage(cvGetSize(orig), IPL_DEPTH_32F, 1);
	}
	cvCvtColor(orig, gray, CV_BGR2GRAY);
	CvPoint2D32f* feats = (CvPoint2D32f*)malloc(maxCount*sizeof(CvPoint2D32f));
	for(int c=0; c<(int)img->contourArray.size(); c++){
		int count = maxCount;
		CvSeq *seq = img->contourArray[c];
		cvZero(cnt_mask);
		CvSeq *h_next = seq->h_next; seq->h_next = NULL;
		cvDrawContours(cnt_mask, seq, CV_RGB(255,255,255), CV_RGB(0,0,0), 1, CV_FILLED, CV_AA, cvPoint(0,0));
		seq->h_next = h_next;
		cvGoodFeaturesToTrack( gray, eig, tempimg, feats, &count, quality, minDist, cnt_mask, blockSize, method, harrisK );
		img->AddFeats(c, feats, count, clean);
	}
	free(feats);

}
