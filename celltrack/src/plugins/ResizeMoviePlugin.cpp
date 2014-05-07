#include "ResizeMoviePlugin.h"
#include "Util.h"

ResizeMoviePlugin::ResizeMoviePlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true)
{
	sidebar =  new ResizeMovieSidebar(parent_, this);
	sidebarw = sidebar;
	OnBookChange();
	DoPreview();
}
void ResizeMoviePlugin::OnBookChange()
{
	sidebar->width->SetValue(cm->size.width);
	sidebar->height->SetValue(cm->size.height);
}

void ResizeMoviePlugin::OnChangeWidth()
{
	if(!sidebar->constrain->GetValue())
		return;
	sidebar->height->SetValue( ceil((float)(sidebar->width->GetValue() * cm->size.height/cm->size.width) ));
}

void ResizeMoviePlugin::OnChangeHeight()
{
	if(!sidebar->constrain->GetValue())
		return;
	sidebar->width->SetValue( ceil((float)(sidebar->height->GetValue() * cm->size.width/cm->size.height)) );
}

void ResizeMoviePlugin::OnOK()
{
	int INTERPOLATION_METHODS[]={CV_INTER_NN, CV_INTER_LINEAR, CV_INTER_AREA, CV_INTER_CUBIC};
	cm->Resize(sidebar->width->GetValue(), sidebar->height->GetValue(), INTERPOLATION_METHODS[sidebar->interpolation->GetSelection()]);
}

