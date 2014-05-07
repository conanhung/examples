#ifndef __LKContoursSidebar__
#define __LKContoursSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "LKContoursPlugin.h"
class LKContoursPlugin;

class LKContoursSidebar : public LKContoursSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(LKContours)
	DECLARE_DYNAMIC_CLASS(LKContoursSidebar)
};

#endif // __LKContoursSidebar__
