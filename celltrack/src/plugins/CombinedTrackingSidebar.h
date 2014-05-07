#ifndef __CombinedTrackingSidebar__
#define __CombinedTrackingSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "CombinedTrackingPlugin.h"
class CombinedTrackingPlugin;

class CombinedTrackingSidebar : public CombinedTrackingSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(CombinedTracking)
	DECLARE_DYNAMIC_CLASS(CombinedTrackingSidebar)
};

#endif // __CombinedTrackingSidebar__
