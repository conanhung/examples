#include "EditContoursPlugin.h"
#include "Util.h"

EditContoursPlugin::EditContoursPlugin( wxWindow* parent_, MyFrame *win_ ): PluginBase(GetStaticName(), parent_, win_,false,false), dirty(false) {
	cm->SetReloadListener(this);
	sidebar =  new EditContoursSidebar(parent_, this);
	sidebarw = sidebar;
	canvas->SetRoiListener(this);
	canvas->SetSelectContourListener(this);
	canvas->SetDragContourListener(this);
	canvas->SetDragVertexListener(this);
	OnNavigate();
	OnUseMouseTo();
}
EditContoursPlugin::~EditContoursPlugin()
{
	cm->SetReloadListener(NULL);
	canvas->SetRoiListener(NULL);
	canvas->SetSelectContourListener(NULL);
	canvas->SetDragContourListener(NULL);
	canvas->SetDragVertexListener(NULL);
	canvas->CancelRoi();
	canvas->CancelSelectContour();
	canvas->CancelDragContour();
	canvas->CancelDragVertex();
	canvas->ResetSelectedContours();
	canvas->Refresh();
	canvas->Update();
}
#include <wx/msgdlg.h>
void EditContoursPlugin::OnReload(){
	if (dirty){
		if(wxMessageDialog(win,"Do you want to save changes to the current frame?", "Save changes?", wxYES_NO).ShowModal()==wxID_YES){
			cm->PushbackCurrentFrame();
		}
	}
	dirty = false;
}
void EditContoursPlugin::OnNavigate()
{
	sidebar->OnNavigate(GetContourCount(cm->img.contours));
}
void EditContoursPlugin::DoPreview()
{
	for (int i=0; i<sidebar->count; i++)
		canvas->SetContourSelection(i,sidebar->listbox->IsSelected(i));
}
void EditContoursPlugin::OnDeleteSelected()
{
	for (int i=sidebar->count-1; i>=0; i--) {
		if (sidebar->listbox->IsSelected(i))
			cm->img.RemoveContour(i);
	}
	cm->Redraw();
	dirty = true;
	OnNavigate();
}
void EditContoursPlugin::OnCleanAllFrames()
{
	for (int i=0; i<cm->frameCount; i++){
		cm->book[i]->RemoveAllContours();
	}
	cm->ReloadCurrentFrame(true);
	dirty = false;
	OnNavigate();
}

void EditContoursPlugin::OnUseMouseTo()
{
	canvas->CancelRoi();
	canvas->CancelSelectContour();
	canvas->CancelDragContour();
	canvas->CancelDragVertex();
	if(sidebar->useMouseTo->GetSelection()==0){
		canvas->BeginSelectContour();
	}
	else if(sidebar->useMouseTo->GetSelection()==1){
		canvas->BeginRoi();
	}
	else if(sidebar->useMouseTo->GetSelection()==2){
		canvas->BeginDragContour();
	}
	else if(sidebar->useMouseTo->GetSelection()==3){
		canvas->BeginDragVertex();
	}
}

void EditContoursPlugin::OnRoi()
{
	cm->img.AddRoi(canvas->roi);
	dirty = true;
	cm->Redraw();
	sidebar->listbox->Append(wxString::Format("%d",++sidebar->count));
	canvas->BeginRoi();
}
#include "Util.h"
void EditContoursPlugin::OnSelectContour(int index)
{
	TOGGLE_LISTBOX_SELECTION(sidebar->listbox, index);
}
void EditContoursPlugin::OnDragContour(int index, CvSeq *seq)
{
	cm->img.ReplaceContour(index, seq);
	dirty = true;
	canvas->BeginDragContour();
}

void EditContoursPlugin::OnDragVertex(int index, int vertex, const CvPoint &loc)
{
	CvPoint *p = (CvPoint*) cvGetSeqElem(cm->img.contourArray[index], vertex);
	p->x = loc.x;
	p->y = loc.y;
	dirty = true;
	canvas->BeginDragVertex();
}


void EditContoursPlugin::OnNormalizeEdges(){
}
void EditContoursPlugin::OnOK(){
	cm->PushbackCurrentFrame();
	dirty = false;
}
void EditContoursPlugin::OnCancel(){
	cm->ReloadCurrentFrame(true, false);
}
void EditContoursPlugin::OnDoReload()
{
	OnCancel();
}

