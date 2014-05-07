#ifndef __TrackContoursSidebar__
#define __TrackContoursSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "TrackContoursPlugin.h"
class TrackContoursPlugin;

class TrackContoursSidebar : public TrackContoursSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(TrackContours)
	DECLARE_DYNAMIC_CLASS(TrackContoursSidebar)
};

#endif // __TrackContoursSidebar__
