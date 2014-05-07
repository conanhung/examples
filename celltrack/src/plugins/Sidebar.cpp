#include "ImproveContoursSidebar.h"
#include "CustomEvents.h"

IMPLEMENT_DYNAMIC_CLASS( ImproveContoursSidebar, wxPanel )

void ImproveContoursSidebar::OnChange()
{
	plugin->DoPreview();
}

bool ImproveContoursSidebar::IsPreviewOn(){
	return preview->GetValue();
}

void ImproveContoursSidebar::OnChangePreview( wxCommandEvent& event )
{
	if (IsPreviewOn())
		OnChange();
	else
		plugin->OnEndPreview();
}

void ImproveContoursSidebar::OnOK(wxCommandEvent &event)
{
	plugin->OnOK();
	ProcessEvent(wxCommandEvent(EVT_PLUGIN_END));
}

void ImproveContoursSidebar::OnCancel(wxCommandEvent &event)
{
	plugin->OnCancel();
	ProcessEvent(wxCommandEvent(EVT_PLUGIN_END));
}
