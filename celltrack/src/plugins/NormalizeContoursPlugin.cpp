#include "NormalizeContoursPlugin.h"
#include "Util.h"

NormalizeContoursPlugin::NormalizeContoursPlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true)
{
	sidebar =  new NormalizeContoursSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void NormalizeContoursPlugin::ReleaseTemps()
{
}
int NormalizeContoursPlugin::GetScope() {	return sidebar->scope->GetSelection() ? 1 : 0; }
bool NormalizeContoursPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void NormalizeContoursPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img);
	cm->Redraw(false);
}
#include <vector>
void NormalizeContoursPlugin::ProcessImage( ImagePlus *img ){
	ProcessStatic(img, sidebar->isMinLength->GetValue() ? sidebar->minLength->GetValue() : 0, sidebar->isMaxLength->GetValue() ? sidebar->maxLength->GetValue() : 0);
}
void NormalizeContoursPlugin::ProcessStatic( ImagePlus *img, int minLength, int maxLength ){
	CvSeq *seq;
	//split long edges
	if (maxLength){
		for(int c=0; c<(int)img->contourArray.size(); c++){
			seq = img->contourArray[c];
			int n=seq->total;
			wxPoint *ps = ContourToPointArray(seq);
			std::vector<wxPoint> ps_;
			for (int i=0; i<n; i++){
				int j = (i==n-1 ? 0 : i+1);
				int dx = ps[j].x-ps[i].x;
				int dy = ps[j].y-ps[i].y;
				float dist = sqrt((float)(dx*dx + dy*dy));
				ps_.push_back(ps[i]);
				if (dist <= maxLength)
					continue;
				float d=(dist - maxLength*(int)(dist/maxLength))/2;
				while (d < dist){
					int x = ps[i].x + (int) (d * dx / dist);
					int y = ps[i].y + (int) (d * dy / dist);
					if (x!=ps_.back().x || y!=ps_.back().y)
						ps_.push_back(wxPoint(x,y));
					d+=maxLength;
				}
			}
			delete[] ps;
			img->ReplaceContour(c,ps_);
		}
	}
	//remove vertices that are too close
	if (minLength){
		for(int c=0; c<(int)img->contourArray.size(); c++){
			seq = img->contourArray[c];
			int n=seq->total;
			wxPoint *ps = ContourToPointArray(seq);
			std::vector<wxPoint> ps_;
			ps_.push_back(ps[0]);
			for (int i=1; i<n; i++){
				int j = i-1;
				int dx = ps[j].x-ps_.back().x;
				int dy = ps[j].y-ps_.back().y;
				float dist = sqrt((float)(dx*dx + dy*dy));
				if (dist >= minLength)
					ps_.push_back(ps[i]);
			}
			delete[] ps;
			img->ReplaceContour(c,ps_);
		}
	}
}
