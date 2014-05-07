#ifndef __ResizeSidebar__
#define __ResizeSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "ResizePlugin.h"
class ResizePlugin;

class ResizeSidebar : public ResizeSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(Resize)
	DECLARE_DYNAMIC_CLASS(ResizeSidebar)
	void OnChangeWidth( wxSpinEvent& event );
	void OnChangeHeight( wxSpinEvent& event );
	void OnConstrain( wxCommandEvent& event );
	void OnReset( wxCommandEvent& e);
};

#endif // __ResizeSidebar__
