#include "myframe.h"
#include "util.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include "CustomEvents.h"
#include "Preferences.h"
#include "IncludePlugins.h"


#define WX_SET_ENABLED(win, to)	if(to) win->Enable(); else win->Disable();

IMPLEMENT_DYNAMIC_CLASS( MyFrame, wxFrame )
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_CUSTOM(EVT_PLUGIN_END, wxID_ANY, MyFrame::OnPluginEnd)
EVT_TIMER(wxID_ANY, MyFrame::OnTimer)
// 	EVT_CLOSE(MyFrame::OnClose)
//	EVT_BUTTON(wxID_OK, MyFrame::OnOK)
//	EVT_CANNY( wxID_ANY, MyFrame::OnCanny )
//	EVT_SPINCTRL(wxID_ANY, MyFrame::OnTemp)
// EVT_MOUSE_EVENTS(MyFrame::OnTemp)
END_EVENT_TABLE()

MyFrame::MyFrame(): MyFrame_(NULL), cm(NULL) {}
MyFrame::~MyFrame()
{
	if ( hotplug ) {
		hotplug->OnCancel();
		OnPluginEnd(wxCommandEvent());
	}
	if (cm)
		delete cm;
	if (timer)
		delete timer;
}

#define SPLITTER_UNSPLIT_DESTROY(splitter, i)	\
	if ( splitter->IsSplit() ){ \
		wxWindow *toremove = splitter->GetWindow##i(); \
		splitter->Unsplit(toremove);  \
		toremove->Destroy(); \
	}

// icons
#include "all_icons.xpm"
#define SET_ICON_IMAGES(key)	\
	(m_##key)->SetBitmapLabel(xpm_##key); \
	(m_##key)->SetBitmapSelected(xpm_##key); \
	(m_##key)->SetBitmapDisabled(xpm_disabled_##key); \
	(m_##key)->SetBitmapHover(xpm_hover_##key);


////////////////////////////////////////////////////////////////////
// Method:	Constructor
// Purpose:	
// Input:	
// Output:	NONE
////////////////////////////////////////////////////////////////////
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style) 
: MyFrame_(NULL, -1, title, pos, size, style), hotplug(NULL), isplaying(false), loaded(false)
{
	config = wxConfig::Get();
	cm = new CaptureManager();
	cm->SetCanvas(canvas);
	//	  SetIcon(wxIcon(wxT("celltrack.xpm")));
	SPLITTER_UNSPLIT_DESTROY( splitterSidebar, 1 )
	SPLITTER_UNSPLIT_DESTROY( splitterBottombar, 2 )
	EnableMenus( false );

	SET_ICON_IMAGES( delete )
	SET_ICON_IMAGES( stop )
	SET_ICON_IMAGES( play )
	SET_ICON_IMAGES( prev )
	SET_ICON_IMAGES( next )
	
	timer = new wxTimer(this);
	int widths[] = {-1,100};
	sbar->SetStatusWidths(2, widths);
	
	if(Config_ReadBool(config,"Frame/maximized", false))
		Maximize();
	else if(Config_ReadBool(config,"Frame/fullscreen", false))
		ShowFullScreen(true);
	ShowCanvas2(false);
	getCWD();
}
void MyFrame::myShow(bool askLoad){
	Show();
	if (!loaded && askLoad){
		LoadImagesDialog_ w(this);
		if(w.ShowModal() == wxID_OK){
			if (w.filetype->GetSelection()==0)
				OnOpenMovie(wxCommandEvent());
			else
				OnOpenImages(wxCommandEvent());
		}
//		else OpenMovie(config->Read("AppDir")+"sampleMovie.avi");
	}
	loaded = true;
}
void MyFrame::EnableMenus( bool enable )
{
	EnableMenu(menu_go, enable);
	EnableMenu(menu_image, enable);
	EnableMenu(menu_contours, enable);
	EnableMenu(menu_track, enable);
	EnableMenu(menu_analyze, enable);
	if(enable)
		EnableMenu(menu_file);
//	EnableMenu(menu_help, enable);
//	EnableMenuItem(menu_file,wxID_MENU_SAVE,enable);
}


void MyFrame::OnPreferences( wxCommandEvent &event )
{
	Preferences d(this);
	if (d.ShowModal() == wxID_OK)
		canvas->OnSize(wxSizeEvent());

}
void MyFrame::OnOpenMovie( wxCommandEvent &event )
{
	wxString filename = wxFileSelector("Select a movie file to load", cwd, "", "", "Movie Files (*.avi)|*.avi", wxOPEN | wxCHANGE_DIR | wxFILE_MUST_EXIST, this);
	if (!filename.empty()) {
		OpenMovie(filename);
	}
}
void MyFrame::OpenMovie( const wxString& filename )
{
	wxBeginBusyCursor();
		setCWD(wxPathOnly(filename));
		if(cm->OpenMovie(filename.c_str()))
			OnNewMovieOpened();
	wxEndBusyCursor();
}


void MyFrame::OnOpenImages( wxCommandEvent& event )
{
	wxFileDialog d(this, "Select image files to load", cwd, "", "Windows bitmaps (*.bmp, *.dib)|*.bmp;*.dib|JPEG files (*.jpeg,*.jpg,*.jpe)|*.jpeg;*.jpg;*.jpe|Portable Network Graphics (*.png)|*.png|Portable image format (*.pbm,*.pgm,*.ppm)|*.pbm;*.pgm;*.ppm|Sun rasters (*.sr,*.ras)|*.sr;*.ras|TIFF files (*.tiff,*.tif)|*.tiff;*.tif|OpenEXR HDR images (.exr)|*.exr|JPEG 2000 images (.jp2)|*.jp2|All files (*.*)|*.*", wxOPEN | wxCHANGE_DIR | wxFILE_MUST_EXIST | wxFD_MULTIPLE);
	d.SetFilterIndex(config->Read("OpenImages/filterIndex",1l));
	if (d.ShowModal() == wxID_OK){
		config->Write("OpenImages/filterIndex",(long)d.GetFilterIndex());
		wxArrayString files;
		d.GetFilenames(files);
		if (!files.GetCount())
			return;
	wxBeginBusyCursor();
		if(cm->OpenMovie(files))
			OnNewMovieOpened();
	wxEndBusyCursor();
	}
}
#include <wx/sound.h>
#include "FilterContoursSidebar.h"
void MyFrame::OnNewMovieOpened()
{
	cm->SetPos( 0 );
	OnNavigate();
	m_delete->Enable();
	m_stop->Enable();
	EnableMenus( true );

	return;
	OnFindContours(wxCommandEvent() );
	hotplug->OnOK(); OnPluginEnd(wxCommandEvent());
	OnFilterContours(wxCommandEvent());
	FilterContoursSidebar *s = (FilterContoursSidebar *) hotplug->GetSidebar();
	s->isMinArea->SetValue(true);
	s->minArea->SetValue(1800);
	s->scope->SetSelection(1);
	s->preview->SetValue(false);
	hotplug->OnOK(); OnPluginEnd(wxCommandEvent());
	OnImproveContours(wxCommandEvent() );
	hotplug->OnOK(); OnPluginEnd(wxCommandEvent());
//	OnLKContours(wxCommandEvent() );
	OnCombinedTracking(wxCommandEvent());
	((CombinedTrackingSidebar *) hotplug->GetSidebar())->useNC->SetValue(false);
	hotplug->OnOK(); OnPluginEnd(wxCommandEvent());
//	OnExportTrackData(wxCommandEvent());
	OnPlotDeformation(wxCommandEvent());
}
void MyFrame::OnSaveMovieAs( wxCommandEvent &event )
{
	wxString filename = wxFileSelector("Save movie file as...", cwd, "", "", "Movie Files (*.avi)|*.avi", wxSAVE | wxCHANGE_DIR | wxFD_OVERWRITE_PROMPT, this);
	if (!filename.empty()){
		setCWD(wxPathOnly(filename));
	wxBeginBusyCursor();
		cm->SaveMovie(filename.c_str());
	wxEndBusyCursor();
	}
}
void MyFrame::OnSaveFrameAs( wxCommandEvent &event )
{
	wxString filename = wxFileSelector("Save current frame as...", cwd, "", "", "Image Files|*.png;*.bmp;*.jpg;*.gif", wxSAVE | wxCHANGE_DIR | wxFD_OVERWRITE_PROMPT, this);
	if (!filename.empty()){
		setCWD(wxPathOnly(filename));
		wxBeginBusyCursor();
		canvas->drawn.ConvertToImage().SaveFile(filename);
		wxEndBusyCursor();
	}
}
void MyFrame::OnClose(wxCloseEvent &event)
{
	config->Write("Frame/maximized", IsMaximized());
	config->Write("Frame/fullscreen", IsFullScreen());
	config->Write("Frame/iconized", IsIconized());
	if (!IsMaximized() && !IsFullScreen() && !IsIconized()){
		wxRect frameDim = GetRect();
		config->Write(wxT("Frame/width"), frameDim.width);
		config->Write(wxT("Frame/height"), frameDim.height);
		config->Write(wxT("Frame/x"), frameDim.x);
		config->Write(wxT("Frame/y"), frameDim.y);
	}
	Show(false);
	if(hotplug){
		OnPluginEnd(wxCommandEvent());
	}
	event.Skip();
}

wxString MyFrame::getCWD()
{
	config->Read("CWD", &cwd);
	return cwd;
}
void MyFrame::setCWD(const wxString& path)
{
	cwd = path;
	config->Write("CWD", cwd);
}
void MyFrame::OnDelete( wxCommandEvent& event )
{
	if(cm->OnDelete())
		OnNavigate();
}
void MyFrame::OnDeleteBefore( wxCommandEvent& event )
{
	if(cm->OnDeleteBefore())
		OnNavigate();
}
void MyFrame::OnDeleteAfter( wxCommandEvent& event )
{
	if(cm->OnDeleteAfter())
		OnNavigate();
}
void MyFrame::OnPlay( wxCommandEvent& event )
{
	m_play->Disable();
	isplaying = true;
	timer->Start(1000/(cm->fps ? cm->fps : 1), wxTIMER_CONTINUOUS );
}

void MyFrame::OnStop( wxCommandEvent& event )
{
	if (isplaying) {
		m_play->Enable();
		isplaying = false;
		timer->Stop();
	}
	else if(cm->SetPos(0))
		OnNavigate();
}
void MyFrame::OnTogglePlay( wxCommandEvent& event )
{
	if (isplaying)
		OnStop(wxCommandEvent());
	else
		OnPlay(wxCommandEvent());
}

void MyFrame::OnTimer( wxTimerEvent &e )
{
	if (isplaying) {
		if(m_next->IsEnabled())
			OnNext(wxCommandEvent());
		else {
			OnStop(wxCommandEvent());
			if(cm->SetPos(0))
				OnNavigate();
		}
	}
	else {
		return;
	}
}

void MyFrame::OnPrev( wxCommandEvent &event )
{
	if(cm->OnPrev())
		OnNavigate();
}
void MyFrame::OnNext( wxCommandEvent &event )
{
	if(cm->OnNext())
		OnNavigate();
}
void MyFrame::OnScroll( wxScrollEvent &event )
{
	if (cm->SetPos(m_slider->GetValue()))
		OnNavigate();
}

void MyFrame::OnFirst( wxCommandEvent& event )
{
	if (cm->SetPos(0))
		OnNavigate();	
}
void MyFrame::OnLast( wxCommandEvent& event )
{
	if (cm->SetPos(cm->GetFrameCount()-1))
		OnNavigate();
}
void MyFrame::UpdateControls(){
	WX_SET_ENABLED ( m_prev, cm->GetPos() > 0 );
	WX_SET_ENABLED ( m_next, cm->GetPos() < cm->GetFrameCount() -1 );
	m_slider->SetRange( 0, cm->GetFrameCount() - 1 );
	m_slider->SetValue( cm->GetPos() );
	WX_SET_ENABLED ( m_slider, cm->GetFrameCount() > 1 );
	WX_SET_ENABLED ( m_play, cm->GetFrameCount() > 1 );
	sbar->SetStatusText(wxString::Format("%d of %d", cm->pos+1, cm->GetFrameCount()),SBAR_POS);
}
void MyFrame::OnNavigate()
{
	UpdateControls();
	if ( hotplug )
		hotplug->OnNavigate();
}
bool MyFrame::CheckPluginAlreadyHot(string pluginname)
{
	if ( pluginname != "" && hotplug && hotplug->GetName() == pluginname  ){
//		wxMessageBox(wxString("There is already an active ") + pluginname + " plugin.");
		return true;
	}
	return false;
}

template <class Plugin>
void MyFrame::StartPlugin(Plugin *newplugin, wxWindow *parentwin)
{
	if (CheckPluginAlreadyHot(Plugin::GetStaticName()))
		return;
	if ( hotplug ) {
//		if (wxMessageBox(wxString("There is already an active plugin named \"")+hotplug->GetStaticName()+"\". Do you want to continue starting new plugin named \""+Plugin::GetStaticName()+"\"?", "Cancel active plugin?", wxOK|wxCANCEL, this) != wxOK)
//			return;
		hotplug->OnCancel();
		OnPluginEnd(wxCommandEvent());
	}
	hotplug = new Plugin(parentwin, this);
	wxWindow *sidebar = hotplug->GetSidebar();
	if ( sidebar ){
		splitterSidebar->SplitVertically(sidebar, splitterSidebar->GetWindow1(), sidebar->GetSize().GetWidth());
	}
	sidebar = hotplug->GetBottombar();
	if ( sidebar ){		
		splitterBottombar->SplitHorizontally(splitterBottombar->GetWindow1(), sidebar,
			splitterBottombar->GetSize().GetHeight() - sidebar->GetSize().GetHeight());
	}
	if (hotplug->ShowsCanvas2())
		ShowCanvas2(true);
}
template <class Plugin>
void MyFrame::MemTestPlugin(){
	for (int i=0; i<100; i++){
		Plugin *p=NULL;
		StartPlugin(p, splitterSidebar);
		hotplug->OnCancel();
		OnPluginEnd(wxCommandEvent());
	}
}
#define DEFINE_ONPLUGIN(name)	\
	void MyFrame::On##name(wxCommandEvent &event) { \
	name##Plugin *p=NULL;	StartPlugin(p, splitterSidebar); }
DEFINE_ONPLUGIN(FindContours)
DEFINE_ONPLUGIN(FilterContours)
DEFINE_ONPLUGIN(EditContours)
DEFINE_ONPLUGIN( ImproveContours )
DEFINE_ONPLUGIN( SubtractBackground )
DEFINE_ONPLUGIN( Smooth )
DEFINE_ONPLUGIN( TrackContours )
DEFINE_ONPLUGIN( LKContours )
DEFINE_ONPLUGIN( CamShift )
DEFINE_ONPLUGIN( MatchTemplate )
DEFINE_ONPLUGIN( CombinedTracking )
DEFINE_ONPLUGIN( FindFeatures )
DEFINE_ONPLUGIN( NormalizeContours )
DEFINE_ONPLUGIN( ResizeMovie )
DEFINE_ONPLUGIN( Crop )

void MyFrame::OnPluginEnd(wxEvent &event){
	wxWindow *sidebar=hotplug->GetSidebar(), *bottombar=hotplug->GetBottombar();
	if ( sidebar )
		splitterSidebar->Unsplit(sidebar);
	if ( bottombar )
		splitterBottombar->Unsplit(bottombar);
	ShowCanvas2(false);
	delete hotplug;
	hotplug = NULL;
}
void MyFrame::OnKeyDown( wxKeyEvent& e )
{
	if (e.GetKeyCode() == WXK_LEFT)
		OnPrev(wxCommandEvent());
	else if (e.GetKeyCode() == WXK_RIGHT)
		OnNext(wxCommandEvent());
}
void MyFrame::OnMouse( wxMouseEvent& event )
{
		event.Skip();
		return;
		if (event.GetEventObject() != canvas)
			return;
		if (!event.AltDown())
			return;
		if (event.GetEventObject() == canvas && event.m_leftDown)
			sbar->SetStatusText(wxString::Format("x=%d, y=%d", event.GetX(), event.GetY()));
}



void MyFrame::SetStatusText( const wxString& text, int i )
{
	sbar->SetStatusText(text, i);
}

void MyFrame::ShowCanvas2(bool show){
	if (show){
		if (!splitterCanvas->IsSplit()){
			canvas2->Show(true);
			splitterCanvas->SplitVertically(canvas2,canvas);
		}
	}
	else{
		if (splitterCanvas->IsSplit()){
			splitterCanvas->Unsplit(canvas2);
			canvas2->Show(false);
		}
	}
}
//---------------------- Analysis ------------------------------
bool MyFrame::SetupCellPlot(wxString title, wxString ytitle, PlotDialog* &pd, mpWindow* &p, int &numCells){
	numCells=cm->book[0]->contourArray.size();
	if (!numCells){
		wxLogError("No cells in the first frame. Detect/draw boundaries in the first frame and apply tracking first.");
		return false;
	}
	pd = new PlotDialog(this, wxID_ANY, title);
	p = pd->plot;
    p->AddLayer(     new mpScaleX(wxT("frame"), mpALIGN_BOTTOM, true) );
    p->AddLayer(     new mpScaleY(ytitle, mpALIGN_LEFT, true) );
	return true;
}

#include "mpFXVector.h"
void MyFrame::OnPlotSpeed( wxCommandEvent& e )
{
	PlotDialog *pd; mpWindow *p; int numCells;
	if(!SetupCellPlot("Cell Speed", "speed (pixel/frame)", pd, p, numCells)) return;
	for (int i=0; i<numCells; i++){
		float totalDisp, avgSpeed;
		std::vector<float> speeds = cm->GetSpeeds(i, totalDisp, avgSpeed);
		wxString name = wxString::Format("Cell-%d (distance=%.1f, speed=%.1f)", i+1, totalDisp, avgSpeed);
		mpFXVector *v = new mpFXVector(name);
		v->SetData( speeds );
		v->SetContinuity(true);
		//wxPen mypen(*wxRED, 5, wxSOLID); v->SetPen( mypen);
		p->AddLayer(   v   );
	}
	p->Fit();
	pd->ShowModal();
	delete pd;
}
void MyFrame::OnPlotArea( wxCommandEvent& e )
{
	PlotDialog *pd; mpWindow *p; int numCells;
	if(!SetupCellPlot("Cell Area", "area (pixel^2)", pd, p, numCells)) return;
	for (int i=0; i<numCells; i++){
		float avgArea;
		std::vector<float> areas = cm->GetAreas(i, avgArea);
		wxString name = wxString::Format("Cell-%d (avgArea=%.1f)", i+1, avgArea);
		mpFXVector *v = new mpFXVector(name);
		v->SetData( areas );
		v->SetContinuity(true);
		p->AddLayer(   v   );
	}
	p->Fit();
	pd->ShowModal();
	delete pd;
}
void MyFrame::OnPlotAreaDiff( wxCommandEvent& e )
{
	PlotDialog *pd; mpWindow *p; int numCells;
	if(!SetupCellPlot("Change in Cell Area", "d-area (pixel^2/frame)", pd, p, numCells)) return;
	for (int i=0; i<numCells; i++){
		float avgArea;
		std::vector<float> areas = cm->GetAreaDiff(i, avgArea);
		wxString name = wxString::Format("Cell-%d (avgChange=%.1f)", i+1, avgArea);
		mpFXVector *v = new mpFXVector(name);
		v->SetData( areas );
		v->SetContinuity(true);
		p->AddLayer(   v   );
	}
	p->Fit();
	pd->ShowModal();
	delete pd;
}
void MyFrame::OnPlotDeformation( wxCommandEvent& e )
{
	PlotDialog *pd; mpWindow *p; int numCells;
	if(!SetupCellPlot("Cell Deformation", "deformation (pixel^2/frame)", pd, p, numCells)) return;
	for (int i=0; i<numCells; i++){
		float avgDef;
		std::vector<float> defs = cm->GetDeformation(i, avgDef);
		wxString name = wxString::Format("Cell-%d (avgDeform=%.1f)", i+1, avgDef);
		mpFXVector *v = new mpFXVector(name);
		v->SetData( defs );
		v->SetContinuity(true);
		p->AddLayer(   v   );
	}
	p->Fit();
	pd->ShowModal();
	delete pd;
}

#include "PictureCanvas.h"
void MyFrame::OnViewImage(wxString title, bool (CaptureManager::*func)(wxBitmap &)){
	wxBitmap bmp;
	if((cm->*func)(bmp)){
		ShowImageDialog d(this,wxID_ANY,"Cell Tracking");
		d.canvas->SetImage(bmp);
		d.ShowModal();
	}		
}
void MyFrame::OnExportImage(wxString title, bool (CaptureManager::*func)(wxBitmap &)){
	wxString filename = wxFileSelector(title, cwd, "", "", "Image Files|*.png;*.jpg;*.gif", wxSAVE | wxCHANGE_DIR | wxFD_OVERWRITE_PROMPT, this);
	  if (!filename.empty()){
		setCWD(wxPathOnly(filename));
		wxBeginBusyCursor();
		wxBitmap bmp;
		if((cm->*func)(bmp))
			bmp.ConvertToImage().SaveFile(filename);
		wxEndBusyCursor();
	  }
}
void MyFrame::OnViewTrackImage( wxCommandEvent& e ) {
	OnViewImage("Cell Tracking", &CaptureManager::SaveTrackImage);
}
void MyFrame::OnViewTrajectoryImage( wxCommandEvent& e ) {
	OnViewImage("Cell Trajectory", &CaptureManager::SaveTrajectoryImage);
}
void MyFrame::OnExportTrackImage( wxCommandEvent& e ) {
	OnExportImage("Save tracking image as...", &CaptureManager::SaveTrackImage);
}
void MyFrame::OnExportTrajectoryImage( wxCommandEvent& e ) {
	OnExportImage("Save trajectory image as...", &CaptureManager::SaveTrajectoryImage);
}

void MyFrame::OnExportData(wxString title, bool (CaptureManager::*func)(const char*)){
	wxString filename = wxFileSelector(title, cwd, "", "", "Text Files|*.txt", wxSAVE | wxCHANGE_DIR | wxFD_OVERWRITE_PROMPT, this);
	  if (!filename.empty()){
		setCWD(wxPathOnly(filename));
		wxBeginBusyCursor();
		(cm->*func)(filename.c_str());
		wxEndBusyCursor();
	}	
}
void MyFrame::OnExportTrajectoryData(wxCommandEvent& e ) {
	OnExportData("Save Trajectory data as...", &CaptureManager::SaveTrajectoryData);
}
void MyFrame::OnExportTrackData(wxCommandEvent& e ){
	OnExportData("Save Tracking data as...", &CaptureManager::SaveTrackData);
}
void MyFrame::OnExportSpeedData(wxCommandEvent& e ){
	OnExportData("Save Cell Speed data as...", &CaptureManager::SaveSpeedData);
}
void MyFrame::OnExportAreaData(wxCommandEvent& e ){
	OnExportData("Save Cell Area data as...", &CaptureManager::SaveAreaData);
}
void MyFrame::OnExportDeformationData(wxCommandEvent& e ){
	OnExportData("Save Cell Area data as...", &CaptureManager::SaveDeformationData);
}

void MyFrame::OnImportTrackData(wxCommandEvent& e )
{
	wxString filename = wxFileSelector("Import tracking data...", cwd, "", "", "Text Files|*.txt", wxOPEN | wxCHANGE_DIR | wxFILE_MUST_EXIST, this);
	  if (!filename.empty()){
		setCWD(wxPathOnly(filename));
		wxBeginBusyCursor();
		cm->ImportTrackData(filename.c_str());
//TODO: is this necessary?
		canvas->OnSize(wxSizeEvent());
		wxEndBusyCursor();
	}	
}

#include <wx/aboutdlg.h>
void MyFrame::OnAbout(wxCommandEvent &e){
	wxAboutDialogInfo i;
	i.SetName("CellTrack");
	i.SetVersion("1.1");
	i.SetDescription("An Open-Source Software for Cell Tracking and Motility Analysis");
	i.SetCopyright("(C) 2008 Ahmet Sacan <sacan@cse.ohio-state.edu>");
	i.SetWebSite("http://db.cse.ohio-state.edu/CellTrack");
	wxAboutBox(i);
}
void MyFrame::OnHelp(wxCommandEvent &e){
	wxLaunchDefaultBrowser("http://db.cse.ohio-state.edu/CellTrack");
}
