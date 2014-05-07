#ifndef __EditContoursSidebar__
#define __EditContoursSidebar__

#include "Gui.h"
#include <wx/msgdlg.h>
#include "PluginDefinitions.h"
#include "EditContoursPlugin.h"
class EditContoursPlugin;

class EditContoursSidebar : public EditContoursSidebar_
{
	DEFINE_PLUGIN_SIDEBAR(EditContours)
	DECLARE_DYNAMIC_CLASS(EditContoursSidebar)
	void OnSelectAll( wxCommandEvent& event );
	void OnDeselectAll( wxCommandEvent& event );
	void OnInvertSelection( wxCommandEvent& event );
	void OnDeleteSelected( wxCommandEvent& event );
	void OnDeleteAll( wxCommandEvent& event );
	void OnCleanAllFrames( wxCommandEvent& event );
	void OnUseMouseTo( wxCommandEvent& event );
	int count;
	void OnNavigate(int count_);
	void OnNormalizeEdges(wxCommandEvent& e);
	void OnDoReload(wxCommandEvent& e);
};

#endif // __EditContoursSidebar__
