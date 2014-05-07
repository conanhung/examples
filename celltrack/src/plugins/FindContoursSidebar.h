#ifndef __FindContoursSidebar__
#define __FindContoursSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "FindContoursPlugin.h"
class FindContoursPlugin;

class FindContoursSidebar : public FindContoursSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(FindContours)
	DECLARE_DYNAMIC_CLASS(FindContoursSidebar)
};

#endif // __FindContoursSidebar__
