#include "EditContoursSidebar.h"

IMPLEMENT_DYNAMIC_CLASS( EditContoursSidebar, wxPanel )
DECLARE_PLUGIN_SIDEBAR(EditContours)

void EditContoursSidebar::OnSelectAll( wxCommandEvent& event )
{
	for (int i=0; i<count; i++)
		listbox->Select(i);
	plugin->DoPreview();
}
void EditContoursSidebar::OnDeselectAll( wxCommandEvent& event )
{
	listbox->DeselectAll();
	plugin->DoPreview();
}
#include "Util.h"
void EditContoursSidebar::OnInvertSelection( wxCommandEvent& event )
{
	for (int i=0; i<count; i++)
		TOGGLE_LISTBOX_SELECTION(listbox,i);
	plugin->DoPreview();	
}

void EditContoursSidebar::OnDeleteSelected( wxCommandEvent& event )
{
	plugin->OnDeleteSelected();
}
void EditContoursSidebar::OnDeleteAll( wxCommandEvent& event )
{
	for (int i=0; i<count; i++)
		listbox->Select(i);
	plugin->OnDeleteSelected();
}

void EditContoursSidebar::OnCleanAllFrames( wxCommandEvent& event )
{
	if(wxMessageBox("Are you sure you want to remove all cells from ALL frames?", "Confirm removal", wxOK | wxCANCEL, this)==wxOK)
		plugin->OnCleanAllFrames();
}
void EditContoursSidebar::OnUseMouseTo( wxCommandEvent& event )
{
	plugin->OnUseMouseTo();	
}
#include <wx/listbox.h>
void EditContoursSidebar::OnNavigate( int count_ )
{
	count = count_;
	listbox->Clear();
	for (int i=0; i<count; i++)
		listbox->Append(wxString::Format("%d",i+1));
}
void EditContoursSidebar::OnNormalizeEdges(wxCommandEvent& e){
	plugin->OnNormalizeEdges();
}
void EditContoursSidebar::OnDoReload( wxCommandEvent& e )
{
	plugin->OnDoReload();
}

