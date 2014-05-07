#ifndef __MatchTemplateSidebar__
#define __MatchTemplateSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "MatchTemplatePlugin.h"
class MatchTemplatePlugin;

class MatchTemplateSidebar : public MatchTemplateSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(MatchTemplate)
	DECLARE_DYNAMIC_CLASS(MatchTemplateSidebar)
};

#endif // __MatchTemplateSidebar__
