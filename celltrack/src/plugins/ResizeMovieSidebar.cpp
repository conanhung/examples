#include "ResizeMovieSidebar.h"

IMPLEMENT_DYNAMIC_CLASS( ResizeMovieSidebar, wxPanel )
DECLARE_PLUGIN_SIDEBAR(ResizeMovie)

void ResizeMovieSidebar::OnChangeWidth( wxSpinEvent& event )
{
	plugin->OnChangeWidth();
}
void ResizeMovieSidebar::OnChangeHeight( wxSpinEvent& event )
{
	plugin->OnChangeHeight();
}
void ResizeMovieSidebar::OnConstrain( wxCommandEvent& event )
{
	plugin->OnChangeWidth();
}
void ResizeMovieSidebar::OnReset( wxCommandEvent& e )
{
	plugin->OnBookChange();
}
