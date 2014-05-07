#ifndef __FindFeaturesSidebar__
#define __FindFeaturesSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "FindFeaturesPlugin.h"
class FindFeaturesPlugin;

class FindFeaturesSidebar : public FindFeaturesSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(FindFeatures)
	DECLARE_DYNAMIC_CLASS(FindFeaturesSidebar)
};

#endif // __FindFeaturesSidebar__
