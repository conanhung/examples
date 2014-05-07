#ifndef __CamShiftSidebar__
#define __CamShiftSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "CamShiftPlugin.h"
class CamShiftPlugin;

class CamShiftSidebar : public CamShiftSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(CamShift)
	DECLARE_DYNAMIC_CLASS(CamShiftSidebar)
};

#endif // __CamShiftSidebar__
