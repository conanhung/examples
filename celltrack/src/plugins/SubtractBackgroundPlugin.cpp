#include "SubtractBackgroundPlugin.h"
#include "Util.h"

SubtractBackgroundPlugin::SubtractBackgroundPlugin( wxWindow* parent_, MyFrame *win_ ): PluginBase(GetStaticName(), parent_, win_, true, true), avgImg(NULL), temp(NULL), temp32(NULL), gaussModel(NULL) {
	sidebar =  new SubtractBackgroundSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void SubtractBackgroundPlugin::ReleaseTemps()
{
	if (avgImg)
		cvReleaseImage(&avgImg);
	if (temp)
		cvReleaseImage(&temp);
	if (temp32)
		cvReleaseImage(&temp32);
	if (gaussModel)
		cvReleaseBGStatModel(&gaussModel);
}
int SubtractBackgroundPlugin::GetScope() {	return 1; }
bool SubtractBackgroundPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void SubtractBackgroundPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	cm->ReloadCurrentFrame(false);
	InitModels(true);
	ProcessImage(&cm->img, cm->GetPos());
	cm->Redraw(false);
}
void SubtractBackgroundPlugin::ProcessImage( ImagePlus *img, int pos ){
	IplImage *orig = img->orig;
	InitModels();
	if (sidebar->method->GetSelection() == 0)
		cvAbsDiff(orig, avgImg, orig);
	else {
		if (gaussModel)
			cvReleaseBGStatModel(&gaussModel);
		if (!gaussModel) {
			CvGaussBGStatModelParams* params = new CvGaussBGStatModelParams;	
			params->win_size = sidebar->win_size->GetValue();
			params->n_gauss = sidebar->n_gauss->GetValue();
			params->bg_threshold = sidebar->bg_threshold->GetValue();
			params->std_threshold = sidebar->std_threshold->GetValue();
			params->minArea = sidebar->minArea->GetValue();
			params->weight_init = sidebar->weight_init->GetValue();
			params->variance_init = sidebar->variance_init->GetValue(); 
			gaussModel = cvCreateGaussianBGModel( cm->book[0]->orig, params );
			delete params;
		}
		int start;
		bool forward = true;
		if (sidebar->numFrames->GetValue() == 0)
			start = -1;
		else
			start = pos - sidebar->numFrames->GetValue()+1;
		if (start < 0 && pos < cm->GetFrameCount() / 2.0){
			forward = false;
			start = pos + (sidebar->numFrames->GetValue() ? sidebar->numFrames->GetValue() -1 : cm->GetFrameCount()-1);
			if (start > cm->GetFrameCount()-1)
				start = cm->GetFrameCount()-1;
		}
		else if (start < 0)
			start = 0;

		for( int i = start; forward ? i<=pos : i>=pos; i+=forward?+1:-1 )
			cvUpdateBGStatModel( cm->book[i]->orig, gaussModel );
		//cvCvtColor(gaussModel->foreground, img->orig, CV_GRAY2BGR);
		cvZero(temp);
		cvCopy(img->orig, temp, gaussModel->foreground);
		cvCopy(temp, img->orig);
	}
}
void SubtractBackgroundPlugin::InitModels(bool reinit)
{
	if (sidebar->method->GetSelection() == 0) {
		if (!avgImg){
			IplImage *temp32 = cvCreateImage( cvImageSize(cm->book[0]->orig), IPL_DEPTH_32F, 3); 
			avgImg = cvCreateImage( cvImageSize(cm->book[0]->orig), IPL_DEPTH_8U, 3 );
			cvConvertScale(cm->book[0]->orig, temp32);
			for (int i=1; i<cm->GetFrameCount(); i++)
				cvAcc(cm->book[i]->orig, temp32);
			cvConvertScale(temp32, temp32, 1.0/cm->GetFrameCount());
			cvConvertScale(temp32, avgImg);
		}
	}
	else {
		if (!temp)
			temp = cvCreateImage( cvImageSize(cm->book[0]->orig), IPL_DEPTH_8U, 3 );
	}
}
