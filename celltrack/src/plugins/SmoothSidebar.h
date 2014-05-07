#ifndef __SmoothSidebar__
#define __SmoothSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "SmoothPlugin.h"
class SmoothPlugin;

class SmoothSidebar : public SmoothSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(Smooth)
	DECLARE_DYNAMIC_CLASS(SmoothSidebar)
};

#endif // __SmoothSidebar__
