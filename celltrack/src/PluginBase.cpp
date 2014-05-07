#include "PluginBase.h"

PluginBase::PluginBase( string name_, wxWindow* parent_, MyFrame *win_, bool hasPreview_, bool doProcessImageOnOK_, bool showsCanvas2_)
: name(name_), parent(parent_), win(win_), cm(win->cm), sidebarw(NULL), bottombarw(NULL), hasPreview(hasPreview_), doProcessImageOnOK(doProcessImageOnOK_), canvas(win->canvas), canvas2(win->canvas2), showsCanvas2(showsCanvas2_), progressDlg(NULL)
{
	if (hasPreview)
		cm->SetRedrawListener(this);
	cm->SetBookChangeListener(this);
	if (showsCanvas2)
		OnNavigate();
}
PluginBase::~PluginBase(void)
{
	if (hasPreview)
		cm->SetRedrawListener(NULL);
	cm->SetBookChangeListener(NULL);
	ReleaseTemps();
	if (sidebarw)
		sidebarw->Destroy();
	if(progressDlg)
		progressDlg->Destroy();
}
void PluginBase::OnNavigate(){
	if (showsCanvas2){
		if(cm->GetPos())
			canvas2->SetImage(*(cm->book[cm->GetPos()-1]));
		else
			canvas2->SetImage(ImagePlus());
	}
	if (IsPreviewOn())
		ShowProcessInfo();
}
void PluginBase::OnEndPreview()
{
	if ( cm && cm->GetFrameCount() )
		cm->ReloadCurrentFrame(true,false);
	/*
	if (showsCanvas2){
		win->ShowCanvas2(false);
		canvas2->SetImage(ImagePlus());
	}
	*/
}
void PluginBase::OnCancel()
{
	if ( IsPreviewOn() )
		OnEndPreview();
}
void PluginBase::OnRedraw(  )
{
	if ( IsPreviewOn() && cm && cm->GetFrameCount())
		ProcessImage(&cm->img, cm->GetPos());	
}
void PluginBase::OnOK()
{
	if (doProcessImageOnOK && GetScope()>=0){
		wxBeginBusyCursor();
		if (GetScope()) {
			CreateProgressDlg();
			for (int i=(GetScope()==1 ? 0 : cm->pos); i<cm->GetFrameCount() && UpdateProgressDlg(i); i++){
				ProcessImage(cm->book[i], i);
			}
			DestroyProgressDlg();
		}
		else if (IsPreviewOn())
			cm->PushbackCurrentFrame();
		else
			ProcessImage( cm->book[cm->GetPos()] , cm->GetPos() );
		if (!IsPreviewOn())
			cm->ReloadCurrentFrame(true, false);
		wxEndBusyCursor();
	}
}

void PluginBase::CreateProgressDlg(int maxFrames)
{
	DestroyProgressDlg();
	progressDlg = new wxProgressDialog(name+" processing...", wxString::Format("Frame 0 of %d...", cm->GetFrameCount()), maxFrames>=0 ? maxFrames : cm->GetFrameCount(), win, wxPD_CAN_ABORT|wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_REMAINING_TIME|wxPD_AUTO_HIDE);
}
bool PluginBase::UpdateProgressDlg(int frame){
	if (!progressDlg)
		CreateProgressDlg();
	return progressDlg->Update(frame+1, wxString::Format("Frame %d of %d...", frame+1, cm->GetFrameCount()));
}
void PluginBase::DestroyProgressDlg(){
	if (progressDlg){
		if (!progressDlg->Update(0))
			cm->ReloadCurrentFrame();
		progressDlg->Destroy();
		progressDlg = NULL;
	}
}