#include "ResizeSidebar.h"

IMPLEMENT_DYNAMIC_CLASS( ResizeSidebar, wxPanel )
DECLARE_PLUGIN_SIDEBAR(Resize)

void ResizeSidebar::OnChangeWidth( wxSpinEvent& event )
{
	plugin->OnChangeWidth();
}
void ResizeSidebar::OnChangeHeight( wxSpinEvent& event )
{
	plugin->OnChangeHeight();
}
void ResizeSidebar::OnConstrain( wxCommandEvent& event )
{
	plugin->OnChangeWidth();
}
void ResizeSidebar::OnReset( wxCommandEvent& e )
{
	plugin->OnBookChange();
}
