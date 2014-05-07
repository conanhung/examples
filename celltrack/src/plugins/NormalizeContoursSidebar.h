#ifndef __NormalizeContoursSidebar__
#define __NormalizeContoursSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "NormalizeContoursPlugin.h"
class NormalizeContoursPlugin;

class NormalizeContoursSidebar : public NormalizeContoursSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(NormalizeContours)
	DECLARE_DYNAMIC_CLASS(NormalizeContoursSidebar)
};

#endif // __NormalizeContoursSidebar__
