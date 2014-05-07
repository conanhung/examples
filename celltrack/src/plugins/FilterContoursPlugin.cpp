#include "FilterContoursPlugin.h"
#include "Util.h"

FilterContoursPlugin::FilterContoursPlugin( wxWindow* parent_, MyFrame *win_ ): PluginBase(GetStaticName(), parent_, win_, true, true) {
	sidebar =  new FilterContoursSidebar(parent_, this);
	sidebarw = sidebar;
	double maxArea = cm->size.width*cm->size.height;
	sidebar->minArea->SetRange(0, maxArea);
	sidebar->maxArea->SetRange(0, maxArea);
	sidebar->minArea->SetValue(pow(10, ceil(log10(maxArea/100.0))));
	sidebar->maxArea->SetValue(pow(10, ceil(log10(maxArea/10.0))));
	DoPreview();	
}
int FilterContoursPlugin::GetScope() {	return sidebar->scope->GetSelection() ? 1 : 0; }
bool FilterContoursPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void FilterContoursPlugin::DoPreview()
{
	cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img);
	cm->Redraw(false);
}
void FilterContoursPlugin::ProcessImage( ImagePlus *img ){
	CvSeq *seq;
	for (int i=(int)img->contourArray.size()-1; i>=0; i--) {
		seq = img->contourArray[i];
		if (sidebar->isMinArea->GetValue() || sidebar->isMaxArea->GetValue()){
			double area = fabs(cvContourArea(seq));
			if ( (sidebar->isMinArea->GetValue() && area < sidebar->minArea->GetValue())
				||(sidebar->isMaxArea->GetValue() && area > sidebar->maxArea->GetValue()) ){
				img->RemoveContour(i);
				continue;
			}
		}
		if (sidebar->isMinDist->GetValue()){
			bool removed = false;
			for (int j=0; j<seq->total; j++) {
				MyPoint p( (CvPoint*) cvGetSeqElem(seq, j) );
				if ( !(p >= sidebar->minDist->GetValue()) || !(MyPoint(MyPoint(cm->GetSize()) -p) >= sidebar->minDist->GetValue()) ){
					img->RemoveContour(i);
					removed = true;
					break;
				}
			}
			if (removed)
				continue;
		}
	}
}
