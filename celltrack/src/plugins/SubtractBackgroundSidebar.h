#ifndef __SubtractBackgroundSidebar__
#define __SubtractBackgroundSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "SubtractBackgroundPlugin.h"
class SubtractBackgroundPlugin;

class SubtractBackgroundSidebar : public SubtractBackgroundSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(SubtractBackground)
	DECLARE_DYNAMIC_CLASS(SubtractBackgroundSidebar)
};

#endif // __SubtractBackgroundSidebar__
