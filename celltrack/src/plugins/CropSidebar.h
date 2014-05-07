#ifndef __CropSidebar__
#define __CropSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "CropPlugin.h"
class CropPlugin;

class CropSidebar : public CropSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(Crop)
	DECLARE_DYNAMIC_CLASS(CropSidebar)
};

#endif // __CropSidebar__
