#ifndef __ImproveContoursSidebar__
#define __ImproveContoursSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "ImproveContoursPlugin.h"
class ImproveContoursPlugin;

class ImproveContoursSidebar : public ImproveContoursSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(ImproveContours)
	DECLARE_DYNAMIC_CLASS(ImproveContoursSidebar)
};

#endif // __ImproveContoursSidebar__
