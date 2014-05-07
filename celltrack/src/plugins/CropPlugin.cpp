#include "CropPlugin.h"
#include "Util.h"

CropPlugin::CropPlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true)
{
	sidebar =  new CropSidebar(parent_, this);
	sidebarw = sidebar;
	sidebar->fromx->SetMax(cm->size.width-1);
	sidebar->fromy->SetMax(cm->size.width-1);
	sidebar->width->SetMin(-cm->size.height+1);
	sidebar->height->SetMin(-cm->size.height+1);
	sidebar->width->SetMax(cm->size.height-1);
	sidebar->height->SetMax(cm->size.height-1);
	sidebar->width->SetValue(cm->size.width-1);
	sidebar->height->SetValue(cm->size.height-1);
	canvas->SetRectListener(this);
	canvas->SetMouseListener(this);
	canvas->BeginRect();
}
CropPlugin::~CropPlugin( ){
	canvas->CancelRect();
	canvas->SetRectListener(NULL);
	canvas->SetMouseListener(NULL);
}
void CropPlugin::OnOK(){
	if(canvas->theRect.x >=0){
		CvPoint topleft = MyPoint(canvas->theRect.GetTopLeft()).ToCvPoint();
		CvSize size = MyPoint(canvas->theRect.GetSize()).ToCvSize();
		if (size.width < 0){
			topleft.x += size.width;
			size.width *= -1;
		}
		if (size.height < 0){
			topleft.y += size.height;
			size.height *= -1;
		}
		cm->Crop(topleft, size);
	}
}
void CropPlugin::OnMouse(wxMouseEvent &e){
	if (canvas->theRect.x >= 0){
		sidebar->fromx->SetValue(canvas->theRect.x);
		sidebar->fromy->SetValue(canvas->theRect.y);
		sidebar->width->SetValue(canvas->theRect.width);
		sidebar->height->SetValue(canvas->theRect.height);
	}
}
void CropPlugin::DoPreview(){
	canvas->theRect = wxRect(sidebar->fromx->GetValue(), sidebar->fromy->GetValue(), sidebar->width->GetValue(), sidebar->height->GetValue());
}