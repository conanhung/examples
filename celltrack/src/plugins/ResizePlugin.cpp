#include "ResizePlugin.h"
#include "Util.h"

ResizePlugin::ResizePlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true)
{
	sidebar =  new ResizeSidebar(parent_, this);
	sidebarw = sidebar;
	OnBookChange();
	DoPreview();
}
void ResizePlugin::OnBookChange()
{
	sidebar->width->SetValue(cm->size.width);
	sidebar->width->SetValue(cm->size.height);
}

void ResizePlugin::OnChangeWidth()
{
	if(!sidebar->constrain->GetValue())
		return;
	sidebar->height->SetValue( ceil(sidebar->width->GetValue() * cm->size.height/cm->size.width) );
}

void ResizePlugin::OnChangeHeight()
{
	if(!sidebar->constrain->GetValue())
		return;
	sidebar->width->SetValue( ceil(sidebar->height->GetValue() * cm->size.width/cm->size.height) );
}

void ResizePlugin::OnOK()
{
	cm->Resize(sidebar->width->GetValue(), sidebar->height->GetValue());
}

