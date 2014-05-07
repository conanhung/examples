#ifndef __ResizeMovieSidebar__
#define __ResizeMovieSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "ResizeMoviePlugin.h"
class ResizeMoviePlugin;

class ResizeMovieSidebar : public ResizeMovieSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(ResizeMovie)
	DECLARE_DYNAMIC_CLASS(ResizeMovieSidebar)
	void OnChangeWidth( wxSpinEvent& event );
	void OnChangeHeight( wxSpinEvent& event );
	void OnConstrain( wxCommandEvent& event );
	void OnReset( wxCommandEvent& e);
};

#endif // __ResizeMovieSidebar__
