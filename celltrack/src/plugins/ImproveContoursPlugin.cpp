#include "ImproveContoursPlugin.h"
#include "Util.h"

ImproveContoursPlugin::ImproveContoursPlugin( wxWindow* parent_, MyFrame *win_ ): PluginBase(GetStaticName(), parent_, win_, true, true), gray(NULL) {
	sidebar =  new ImproveContoursSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
int ImproveContoursPlugin::GetScope() {	return sidebar->scope->GetSelection() ? 1 : 0; }
bool ImproveContoursPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void ImproveContoursPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img);
	cm->Redraw(false);
}
void ImproveContoursPlugin::ProcessImage( ImagePlus *img ){
	CvSeq *seq;
	CvPoint* ps;
	float alpha=sidebar->alpha->GetValue();
	float beta= sidebar->beta->GetValue();
	float gamma=sidebar->gamma->GetValue();
	CvSize win=cvSize(2*sidebar->width->GetValue()-1, 2*sidebar->height->GetValue()-1);
	int scheme = sidebar->gradient->GetValue();

	if (!gray)
		gray = cvCreateImage( cvSize(img->orig->width, img->orig->height), IPL_DEPTH_8U, 1 );
	cvCvtColor(img->orig, gray, CV_BGR2GRAY);
	for (int i=(int)img->contourArray.size()-1; i>=0; i--) {
		seq = img->contourArray[i];
		int np = seq->total;
		ps = (CvPoint*)malloc( np*sizeof(CvPoint) );
		cvCvtSeqToArray(seq, ps);
		CvTermCriteria term=cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, sidebar->max_iter->GetValue(), sidebar->epsilon->GetValue()*np);
		cvSnakeImage( gray, ps, np,
			&alpha, &beta, &gamma,
			CV_VALUE, win, term, scheme
			);
		img->ReplaceContour(i, ps, np);
		free(ps); ps=NULL;
	}
}
