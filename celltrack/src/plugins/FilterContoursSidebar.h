#ifndef __FilterContoursSidebar__
#define __FilterContoursSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "FilterContoursPlugin.h"
class FilterContoursPlugin;

class FilterContoursSidebar : public FilterContoursSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(FilterContours)
	DECLARE_DYNAMIC_CLASS(FilterContoursSidebar)
};

#endif // __FilterContoursSidebar__
