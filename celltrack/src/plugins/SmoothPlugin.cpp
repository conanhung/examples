#include "SmoothPlugin.h"
#include "Util.h"

SmoothPlugin::SmoothPlugin( wxWindow* parent_, MyFrame *win_ ): PluginBase(GetStaticName(), parent_, win_, true, true), temp(NULL) {
	sidebar =  new SmoothSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void SmoothPlugin::ReleaseTemps()
{
	if (temp) cvReleaseImage(&temp);
}
int SmoothPlugin::GetScope() {	return sidebar->scope->GetSelection() ? 1 : 0; }
bool SmoothPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void SmoothPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	cm->ReloadCurrentFrame(false);
	ProcessImage(&cm->img);
	cm->Redraw(false);
}
#define SMOOTH_CORRECT_WINDOW(x)	(x==0 ? 0 : 2*x-1)
void SmoothPlugin::ProcessImage( ImagePlus *img ){
	IplImage *orig = img->orig;
	if (!temp){
		temp = cvCreateImage( cvSize(orig->width, orig->height), IPL_DEPTH_8U, 3 );
	}
	const static int METHOD_MAP[] = {CV_BLUR, CV_GAUSSIAN, CV_MEDIAN, CV_BILATERAL};
	int method = METHOD_MAP[sidebar->method->GetSelection()];

	if (method == CV_BLUR)
		cvSmooth(orig, orig, method, SMOOTH_CORRECT_WINDOW(sidebar->blur1->GetValue()), SMOOTH_CORRECT_WINDOW(sidebar->blur2->GetValue()));
	else if (method == CV_GAUSSIAN)
		cvSmooth(orig, orig, method, SMOOTH_CORRECT_WINDOW(sidebar->gauss1->GetValue()), SMOOTH_CORRECT_WINDOW(sidebar->gauss2->GetValue()), sidebar->gauss3->GetValue(), sidebar->gauss4->GetValue());
	else if (method == CV_MEDIAN || method == CV_BILATERAL){
		cvCopyImage(orig, temp);
		if (method == CV_MEDIAN)
			cvSmooth(temp, orig, method, SMOOTH_CORRECT_WINDOW(sidebar->median1->GetValue()));
		else
			cvSmooth(temp, orig, method, sidebar->bilateral1->GetValue(), sidebar->bilateral2->GetValue());
	}
}
