///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 17 2007)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include <wx/wxprec.h>

#include "MyCanvas.h"
#include "PictureCanvas.h"
#include "mathplot.h"
#include "wxTextCtrl_double.h"

#include "Gui.h"

///////////////////////////////////////////////////////////////////////////

MyFrame_::MyFrame_( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 50,50 ), wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	menu_file = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( menu_file, ID_OPEN_MOVIE, wxString( _("Open movie file") ) + wxT('\t') + wxT("Ctrl+O"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append(m_menuItem1);
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( menu_file, wxID_ANY, wxString( _("Open image files") ) + wxT('\t') + wxT("Ctrl+Shift+O"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append(m_menuItem6);
	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( menu_file, wxID_ANY, wxString( _("Save movie as..") ) + wxT('\t') + wxT("Ctrl+S"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append(m_menuItem12);
	m_menuItem12->Enable( false );
	
	wxMenuItem* m_menuItem123;
	m_menuItem123 = new wxMenuItem( menu_file, wxID_ANY, wxString( _("Save current frame as..") ) + wxT('\t') + wxT("Ctrl+Shift+S"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append(m_menuItem123);
	m_menuItem123->Enable( false );
	
	wxMenuItem* m_menuItem42;
	m_menuItem42 = new wxMenuItem( menu_file, wxID_ANY, wxString( _("Import Tracking Data") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append(m_menuItem42);
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( menu_file, wxID_ANY, wxString( _("Preferences") ) + wxT('\t') + wxT("Ctrl+K"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append(m_menuItem4);
	m_menubar1->Append( menu_file, _("File") );
	
	menu_go = new wxMenu();
	wxMenuItem* m_menuItem81;
	m_menuItem81 = new wxMenuItem( menu_go, wxID_ANY, wxString( _("Next frame") ) + wxT('\t') + wxT("Alt+Right"), wxEmptyString, wxITEM_NORMAL );
	menu_go->Append(m_menuItem81);
	wxMenuItem* m_menuItem91;
	m_menuItem91 = new wxMenuItem( menu_go, wxID_ANY, wxString( _("Previous frame") ) + wxT('\t') + wxT("Alt+Left"), wxEmptyString, wxITEM_NORMAL );
	menu_go->Append(m_menuItem91);
	wxMenuItem* m_menuItem111;
	m_menuItem111 = new wxMenuItem( menu_go, wxID_ANY, wxString( _("First frame") ) + wxT('\t') + wxT("Alt+Up"), wxEmptyString, wxITEM_NORMAL );
	menu_go->Append(m_menuItem111);
	wxMenuItem* m_menuItem1111;
	m_menuItem1111 = new wxMenuItem( menu_go, wxID_ANY, wxString( _("Last frame") ) + wxT('\t') + wxT("Alt+Down"), wxEmptyString, wxITEM_NORMAL );
	menu_go->Append(m_menuItem1111);
	wxMenuItem* m_menuItem11111;
	m_menuItem11111 = new wxMenuItem( menu_go, wxID_ANY, wxString( _("Play/pause movie") ) + wxT('\t') + wxT("Ctrl+Enter"), wxEmptyString, wxITEM_NORMAL );
	menu_go->Append(m_menuItem11111);
	m_menubar1->Append( menu_go, _("Go") );
	
	menu_image = new wxMenu();
	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( menu_image, wxID_ANY, wxString( _("Resize") ) , wxEmptyString, wxITEM_NORMAL );
	menu_image->Append(m_menuItem8);
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( menu_image, wxID_ANY, wxString( _("Crop") ) , wxEmptyString, wxITEM_NORMAL );
	menu_image->Append(m_menuItem11);
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( menu_image, wxID_ANY, wxString( _("Smooth") ) + wxT('\t') + wxT("Ctrl+M"), wxEmptyString, wxITEM_NORMAL );
	menu_image->Append(m_menuItem9);
	wxMenuItem* m_menuItem111112;
	m_menuItem111112 = new wxMenuItem( menu_image, wxID_ANY, wxString( _("Delete current frame") ) + wxT('\t') + wxT("Ctrl+Back"), wxEmptyString, wxITEM_NORMAL );
	menu_image->Append(m_menuItem111112);
	wxMenuItem* m_menuItem1111121;
	m_menuItem1111121 = new wxMenuItem( menu_image, wxID_ANY, wxString( _("Delete preceeding frames") ) , wxEmptyString, wxITEM_NORMAL );
	menu_image->Append(m_menuItem1111121);
	wxMenuItem* m_menuItem1111122;
	m_menuItem1111122 = new wxMenuItem( menu_image, wxID_ANY, wxString( _("Delete proceeding frames") ) , wxEmptyString, wxITEM_NORMAL );
	menu_image->Append(m_menuItem1111122);
	m_menubar1->Append( menu_image, _("Image") );
	
	menu_contours = new wxMenu();
	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( menu_contours, wxID_ANY, wxString( _("Detect cell boundaries") ) + wxT('\t') + wxT("Ctrl+D"), wxEmptyString, wxITEM_NORMAL );
	menu_contours->Append(m_menuItem2);
	wxMenuItem* m_menuItem21;
	m_menuItem21 = new wxMenuItem( menu_contours, wxID_ANY, wxString( _("Filter cells") ) + wxT('\t') + wxT("Ctrl+F"), wxEmptyString, wxITEM_NORMAL );
	menu_contours->Append(m_menuItem21);
	wxMenuItem* m_menuItem121;
	m_menuItem121 = new wxMenuItem( menu_contours, wxID_ANY, wxString( _("Edit cells") ) + wxT('\t') + wxT("Ctrl+E"), wxEmptyString, wxITEM_NORMAL );
	menu_contours->Append(m_menuItem121);
	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( menu_contours, wxID_ANY, wxString( _("Improve boundaries") ) + wxT('\t') + wxT("Ctrl+I"), wxEmptyString, wxITEM_NORMAL );
	menu_contours->Append(m_menuItem7);
	wxMenuItem* m_menuItem71;
	m_menuItem71 = new wxMenuItem( menu_contours, wxID_ANY, wxString( _("Resample boundaries") ) , wxEmptyString, wxITEM_NORMAL );
	menu_contours->Append(m_menuItem71);
	
	
	wxMenuItem* m_menuItem14;
	m_menuItem14 = new wxMenuItem( menu_contours, wxID_ANY, wxString( _("Find intracellular features") ) + wxT('\t') + wxT("Ctrl+G"), wxEmptyString, wxITEM_NORMAL );
	menu_contours->Append(m_menuItem14);
	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( menu_contours, wxID_ANY, wxString( _("Background subtraction") ) + wxT('\t') + wxT("Ctrl+B"), wxEmptyString, wxITEM_NORMAL );
	menu_contours->Append(m_menuItem10);
	m_menubar1->Append( menu_contours, _("Detection") );
	
	menu_track = new wxMenu();
	wxMenuItem* m_menuItem38;
	m_menuItem38 = new wxMenuItem( menu_track, wxID_ANY, wxString( _("Template-matching") ) + wxT('\t') + wxT("Ctrl+M"), wxEmptyString, wxITEM_NORMAL );
	menu_track->Append(m_menuItem38);
	wxMenuItem* m_menuItem39;
	m_menuItem39 = new wxMenuItem( menu_track, wxID_ANY, wxString( _("CAM-Shift tracking") ) + wxT('\t') + wxT("Ctrl+C"), wxEmptyString, wxITEM_NORMAL );
	menu_track->Append(m_menuItem39);
	wxMenuItem* m_menuItem382;
	m_menuItem382 = new wxMenuItem( menu_track, wxID_ANY, wxString( _("Optical flow tracking") ) + wxT('\t') + wxT("Ctrl+L"), wxEmptyString, wxITEM_NORMAL );
	menu_track->Append(m_menuItem382);
	wxMenuItem* m_menuItem16;
	m_menuItem16 = new wxMenuItem( menu_track, wxID_ANY, wxString( _("Extended Snake tracking") ) + wxT('\t') + wxT("Ctrl+A"), wxEmptyString, wxITEM_NORMAL );
	menu_track->Append(m_menuItem16);
	wxMenuItem* m_menuItem161;
	m_menuItem161 = new wxMenuItem( menu_track, wxID_ANY, wxString( _("Combined Tracking") ) + wxT('\t') + wxT("Ctrl+T"), wxEmptyString, wxITEM_NORMAL );
	menu_track->Append(m_menuItem161);
	m_menubar1->Append( menu_track, _("Tracking") );
	
	menu_analyze = new wxMenu();
	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItem383;
	m_menuItem383 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Plot speed") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append(m_menuItem383);
	wxMenuItem* m_menuItem56;
	m_menuItem56 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Export speed data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append(m_menuItem56);
	menu_analyze->Append( -1, _("Cell Speed"), m_menu4 );
	
	m_menu5 = new wxMenu();
	wxMenuItem* m_menuItem391;
	m_menuItem391 = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Plot area") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append(m_menuItem391);
	wxMenuItem* m_menuItem58;
	m_menuItem58 = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Plot change in area") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append(m_menuItem58);
	wxMenuItem* m_menuItem57;
	m_menuItem57 = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Export area data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append(m_menuItem57);
	menu_analyze->Append( -1, _("Cell Area"), m_menu5 );
	
	m_menu41 = new wxMenu();
	wxMenuItem* m_menuItem3831;
	m_menuItem3831 = new wxMenuItem( m_menu41, wxID_ANY, wxString( _("Plot deformation") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu41->Append(m_menuItem3831);
	wxMenuItem* m_menuItem561;
	m_menuItem561 = new wxMenuItem( m_menu41, wxID_ANY, wxString( _("Export deformation data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu41->Append(m_menuItem561);
	menu_analyze->Append( -1, _("Cell Deformation"), m_menu41 );
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem41;
	m_menuItem41 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("View tracking") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append(m_menuItem41);
	wxMenuItem* m_menuItem36;
	m_menuItem36 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Save as image") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append(m_menuItem36);
	wxMenuItem* m_menuItem35;
	m_menuItem35 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Export tracking data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append(m_menuItem35);
	wxMenuItem* m_menuItem421;
	m_menuItem421 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Import tracking data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append(m_menuItem421);
	menu_analyze->Append( -1, _("Tracking"), m_menu2 );
	
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem40;
	m_menuItem40 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("View trajectory") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append(m_menuItem40);
	wxMenuItem* m_menuItem381;
	m_menuItem381 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Save as image") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append(m_menuItem381);
	wxMenuItem* m_menuItem37;
	m_menuItem37 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Export trajectory data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append(m_menuItem37);
	menu_analyze->Append( -1, _("Trajectory"), m_menu1 );
	
	m_menubar1->Append( menu_analyze, _("Analysis") );
	
	menu_help = new wxMenu();
	wxMenuItem* m_menuItem122;
	m_menuItem122 = new wxMenuItem( menu_help, wxID_ANY, wxString( _("Help contents") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	menu_help->Append(m_menuItem122);
	wxMenuItem* m_menuItem13;
	m_menuItem13 = new wxMenuItem( menu_help, wxID_ANY, wxString( _("About CellTrack") ) , wxEmptyString, wxITEM_NORMAL );
	menu_help->Append(m_menuItem13);
	m_menubar1->Append( menu_help, _("Help") );
	
	this->SetMenuBar( m_menubar1 );
	
	sbar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	splitterBottombar = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	splitterBottombar->SetSashGravity( 1 );
	splitterBottombar->Connect( wxEVT_IDLE, wxIdleEventHandler( MyFrame_::splitterBottombarOnIdle ), NULL, this );
	m_panel4 = new wxPanel( splitterBottombar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	splitterSidebar = new wxSplitterWindow( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	splitterSidebar->SetSashGravity( 0 );
	splitterSidebar->Connect( wxEVT_IDLE, wxIdleEventHandler( MyFrame_::splitterSidebarOnIdle ), NULL, this );
	m_panel11 = new wxPanel( splitterSidebar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel11->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	
	m_panel23 = new wxPanel( splitterSidebar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	splitterCanvas = new wxSplitterWindow( m_panel23, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	splitterCanvas->SetSashGravity( 0.5 );
	splitterCanvas->Connect( wxEVT_IDLE, wxIdleEventHandler( MyFrame_::splitterCanvasOnIdle ), NULL, this );
	canvas2 = new MyCanvas( splitterCanvas, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	canvas2->Hide();
	canvas2->SetMinSize( wxSize( 10,10 ) );
	
	canvas = new MyCanvas( splitterCanvas, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	canvas->SetMinSize( wxSize( 10,10 ) );
	
	splitterCanvas->SplitVertically( canvas2, canvas, 203 );
	bSizer37->Add( splitterCanvas, 1, wxEXPAND, 5 );
	
	m_panel23->SetSizer( bSizer37 );
	m_panel23->Layout();
	bSizer37->Fit( m_panel23 );
	splitterSidebar->SplitVertically( m_panel11, m_panel23, 6 );
	bSizer11->Add( splitterSidebar, 1, wxEXPAND, 5 );
	
	m_panel4->SetSizer( bSizer11 );
	m_panel4->Layout();
	bSizer11->Fit( m_panel4 );
	m_panel12 = new wxPanel( splitterBottombar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel12->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	
	splitterBottombar->SplitHorizontally( m_panel4, m_panel12, 244 );
	bSizer9->Add( splitterBottombar, 1, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer3->SetMinSize( wxSize( -1,10 ) ); 
	m_delete = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 32,32 ), 0 );
	m_delete->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_delete->Enable( false );
	m_delete->SetToolTip( _("Delete current frame") );
	
	m_delete->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_delete->Enable( false );
	m_delete->SetToolTip( _("Delete current frame") );
	
	bSizer3->Add( m_delete, 0, wxALIGN_CENTER_VERTICAL, 0 );
	
	m_stop = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 32,32 ), 0 );
	m_stop->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_stop->Enable( false );
	m_stop->SetToolTip( _("Stop movie") );
	
	m_stop->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_stop->Enable( false );
	m_stop->SetToolTip( _("Stop movie") );
	
	bSizer3->Add( m_stop, 0, wxALL, 5 );
	
	m_play = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 32,32 ), 0 );
	m_play->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_play->Enable( false );
	m_play->SetToolTip( _("Play movie") );
	
	m_play->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_play->Enable( false );
	m_play->SetToolTip( _("Play movie") );
	
	bSizer3->Add( m_play, 0, wxALIGN_CENTER_VERTICAL, 0 );
	
	m_prev = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 32,32 ), 0 );
	m_prev->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_prev->Enable( false );
	m_prev->SetToolTip( _("Previous frame") );
	
	m_prev->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_prev->Enable( false );
	m_prev->SetToolTip( _("Previous frame") );
	
	bSizer3->Add( m_prev, 0, wxALIGN_CENTER_VERTICAL, 0 );
	
	m_next = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 32,32 ), 0 );
	m_next->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_next->Enable( false );
	m_next->SetToolTip( _("Next frame") );
	
	m_next->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	m_next->Enable( false );
	m_next->SetToolTip( _("Next frame") );
	
	bSizer3->Add( m_next, 0, wxALIGN_CENTER_VERTICAL, 0 );
	
	m_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_BOTH );
	m_slider->Enable( false );
	
	bSizer3->Add( m_slider, 1, wxALIGN_CENTER_VERTICAL, 0 );
	
	bSizer1->Add( bSizer3, 0, wxEXPAND, 0 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame_::OnClose ) );
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( MyFrame_::OnKeyDown ) );
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnOpenMovie ) );
	this->Connect( m_menuItem6->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnOpenImages ) );
	this->Connect( m_menuItem12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSaveMovieAs ) );
	this->Connect( m_menuItem123->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSaveFrameAs ) );
	this->Connect( m_menuItem42->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnImportTrackData ) );
	this->Connect( m_menuItem4->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPreferences ) );
	this->Connect( m_menuItem81->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnNext ) );
	this->Connect( m_menuItem91->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPrev ) );
	this->Connect( m_menuItem111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFirst ) );
	this->Connect( m_menuItem1111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnLast ) );
	this->Connect( m_menuItem11111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnTogglePlay ) );
	this->Connect( m_menuItem8->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnResizeMovie ) );
	this->Connect( m_menuItem11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnCrop ) );
	this->Connect( m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSmooth ) );
	this->Connect( m_menuItem111112->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnDelete ) );
	this->Connect( m_menuItem1111121->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnDeleteBefore ) );
	this->Connect( m_menuItem1111122->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnDeleteAfter ) );
	this->Connect( m_menuItem2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFindContours ) );
	this->Connect( m_menuItem21->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFilterContours ) );
	this->Connect( m_menuItem121->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnEditContours ) );
	this->Connect( m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnImproveContours ) );
	this->Connect( m_menuItem71->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnNormalizeContours ) );
	this->Connect( m_menuItem14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFindFeatures ) );
	this->Connect( m_menuItem10->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSubtractBackground ) );
	this->Connect( m_menuItem38->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnMatchTemplate ) );
	this->Connect( m_menuItem39->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnCamShift ) );
	this->Connect( m_menuItem382->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnLKContours ) );
	this->Connect( m_menuItem16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnTrackContours ) );
	this->Connect( m_menuItem161->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnCombinedTracking ) );
	this->Connect( m_menuItem383->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotSpeed ) );
	this->Connect( m_menuItem56->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportSpeedData ) );
	this->Connect( m_menuItem391->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotArea ) );
	this->Connect( m_menuItem58->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotAreaDiff ) );
	this->Connect( m_menuItem57->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportAreaData ) );
	this->Connect( m_menuItem3831->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotDeformation ) );
	this->Connect( m_menuItem561->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportDeformationData ) );
	this->Connect( m_menuItem41->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnViewTrackImage ) );
	this->Connect( m_menuItem36->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrackImage ) );
	this->Connect( m_menuItem35->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrackData ) );
	this->Connect( m_menuItem421->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnImportTrackData ) );
	this->Connect( m_menuItem40->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnViewTrajectoryImage ) );
	this->Connect( m_menuItem381->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrajectoryImage ) );
	this->Connect( m_menuItem37->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrajectoryData ) );
	this->Connect( m_menuItem122->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnHelp ) );
	this->Connect( m_menuItem13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnAbout ) );
	m_delete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnDelete ), NULL, this );
	m_stop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnStop ), NULL, this );
	m_play->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnPlay ), NULL, this );
	m_prev->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnPrev ), NULL, this );
	m_next->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnNext ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
}

MyFrame_::~MyFrame_()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame_::OnClose ) );
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( MyFrame_::OnKeyDown ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnOpenMovie ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnOpenImages ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSaveMovieAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSaveFrameAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnImportTrackData ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPreferences ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnNext ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPrev ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFirst ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnLast ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnTogglePlay ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnResizeMovie ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnCrop ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSmooth ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnDelete ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnDeleteBefore ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnDeleteAfter ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFindContours ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFilterContours ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnEditContours ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnImproveContours ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnNormalizeContours ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnFindFeatures ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnSubtractBackground ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnMatchTemplate ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnCamShift ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnLKContours ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnTrackContours ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnCombinedTracking ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotSpeed ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportSpeedData ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotArea ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotAreaDiff ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportAreaData ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnPlotDeformation ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportDeformationData ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnViewTrackImage ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrackImage ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrackData ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnImportTrackData ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnViewTrajectoryImage ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrajectoryImage ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnExportTrajectoryData ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnHelp ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame_::OnAbout ) );
	m_delete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnDelete ), NULL, this );
	m_stop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnStop ), NULL, this );
	m_play->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnPlay ), NULL, this );
	m_prev->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnPrev ), NULL, this );
	m_next->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame_::OnNext ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame_::OnScroll ), NULL, this );
}

SmoothSidebar_::SmoothSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 215,350 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Smooth image") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	method = new wxChoicebook( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxCHB_DEFAULT );
	method->SetBackgroundColour( wxColour( 225, 225, 225 ) );
	
	m_panel8 = new wxPanel( method, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer121;
	fgSizer121 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer121->SetFlexibleDirection( wxBOTH );
	fgSizer121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText243 = new wxStaticText( m_panel8, wxID_ANY, _("Initial neighborhood"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText243->Wrap( -1 );
	fgSizer121->Add( m_staticText243, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	blur1 = new wxSpinCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 1, 100, 3 );
	fgSizer121->Add( blur1, 0, wxALL, 5 );
	
	m_staticText2421 = new wxStaticText( m_panel8, wxID_ANY, _("Neighborhood scaling"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2421->Wrap( -1 );
	fgSizer121->Add( m_staticText2421, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	blur2 = new wxSpinCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 0, 100, 0 );
	fgSizer121->Add( blur2, 0, wxALL, 5 );
	
	m_panel8->SetSizer( fgSizer121 );
	m_panel8->Layout();
	fgSizer121->Fit( m_panel8 );
	method->AddPage( m_panel8, _("Simple blur"), false );
	m_panel9 = new wxPanel( method, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText24 = new wxStaticText( m_panel9, wxID_ANY, _("Kernel width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer12->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	gauss1 = new wxSpinCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 4 );
	fgSizer12->Add( gauss1, 0, wxALL, 5 );
	
	m_staticText242 = new wxStaticText( m_panel9, wxID_ANY, _("Kernel height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText242->Wrap( -1 );
	fgSizer12->Add( m_staticText242, 0, wxALL, 5 );
	
	gauss2 = new wxSpinCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 0 );
	fgSizer12->Add( gauss2, 0, wxALL, 5 );
	
	m_staticText2411 = new wxStaticText( m_panel9, wxID_ANY, _("Std. dev. (horizontal)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2411->Wrap( -1 );
	fgSizer12->Add( m_staticText2411, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	gauss3 = new wxTextCtrl_double( m_panel9, wxID_ANY, _("0.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( gauss3, 0, wxALL, 5 );
	
	m_staticText24111 = new wxStaticText( m_panel9, wxID_ANY, _("Std. dev. (vertical)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24111->Wrap( -1 );
	fgSizer12->Add( m_staticText24111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	gauss4 = new wxTextCtrl_double( m_panel9, wxID_ANY, _("0.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( gauss4, 0, wxALL, 5 );
	
	m_panel9->SetSizer( fgSizer12 );
	m_panel9->Layout();
	fgSizer12->Fit( m_panel9 );
	method->AddPage( m_panel9, _("Gaussian"), false );
	m_panel81 = new wxPanel( method, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1211;
	fgSizer1211 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1211->SetFlexibleDirection( wxBOTH );
	fgSizer1211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2431 = new wxStaticText( m_panel81, wxID_ANY, _("Neighborhood size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2431->Wrap( -1 );
	fgSizer1211->Add( m_staticText2431, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	median1 = new wxSpinCtrl( m_panel81, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 4 );
	fgSizer1211->Add( median1, 0, wxALL, 5 );
	
	m_panel81->SetSizer( fgSizer1211 );
	m_panel81->Layout();
	fgSizer1211->Fit( m_panel81 );
	method->AddPage( m_panel81, _("Median"), false );
	m_panel811 = new wxPanel( method, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer12111;
	fgSizer12111 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12111->SetFlexibleDirection( wxBOTH );
	fgSizer12111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText24311 = new wxStaticText( m_panel811, wxID_ANY, _("Color standard deviation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24311->Wrap( -1 );
	fgSizer12111->Add( m_staticText24311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bilateral1 = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 2 );
	fgSizer12111->Add( bilateral1, 0, wxALL, 5 );
	
	m_staticText243111 = new wxStaticText( m_panel811, wxID_ANY, _("Space standard deviation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText243111->Wrap( -1 );
	fgSizer12111->Add( m_staticText243111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bilateral2 = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 2 );
	fgSizer12111->Add( bilateral2, 0, wxALL, 5 );
	
	m_panel811->SetSizer( fgSizer12111 );
	m_panel811->Layout();
	fgSizer12111->Fit( m_panel811 );
	method->AddPage( m_panel811, _("Bilateral"), true );
	bSizer9->Add( method, 0, wxEXPAND | wxALL, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline3 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	method->Connect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	blur1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	blur2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss4->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	median1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	bilateral1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	bilateral2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SmoothSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SmoothSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SmoothSidebar_::OnCancel ), NULL, this );
}

SmoothSidebar_::~SmoothSidebar_()
{
	// Disconnect Events
	method->Disconnect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	blur1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	blur2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	gauss4->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	median1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	bilateral1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	bilateral2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SmoothSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SmoothSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SmoothSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SmoothSidebar_::OnCancel ), NULL, this );
}

FindContoursSidebar_::FindContoursSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 190,375 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Find Boundaries") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Initial edge threshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	thresh2 = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 255, 150 );
	fgSizer1->Add( thresh2, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Edge linking threshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	thresh1 = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 255, 50 );
	fgSizer1->Add( thresh1, 0, wxALL, 5 );
	
	m_staticText61 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Aperture size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer1->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString apertureChoices[] = { _("3"), _("5"), _("7") };
	int apertureNChoices = sizeof( apertureChoices ) / sizeof( wxString );
	aperture = new wxChoice( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxSize( 45,-1 ), apertureNChoices, apertureChoices, 0 );
	aperture->SetSelection( 0 );
	fgSizer1->Add( aperture, 0, wxALL, 5 );
	
	m_staticText71 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Number of dilations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer1->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dilate = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 10, 1 );
	fgSizer1->Add( dilate, 0, wxALL, 5 );
	
	m_staticText711 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Number of erosions"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText711->Wrap( -1 );
	fgSizer1->Add( m_staticText711, 0, wxALL, 5 );
	
	erode = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer1->Add( erode, 0, wxALL, 5 );
	
	bSizer9->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	approx = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Approximate polygons"), wxDefaultPosition, wxDefaultSize, 0 );
	approx->SetValue(true);
	
	bSizer9->Add( approx, 0, wxALL, 5 );
	
	wxString intraChoices[] = { _("Find external borders only"), _("Include internal borders") };
	int intraNChoices = sizeof( intraChoices ) / sizeof( wxString );
	intra = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, intraNChoices, intraChoices, 1, wxRA_SPECIFY_COLS );
	intra->SetSelection( 0 );
	bSizer9->Add( intra, 0, wxALL|wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 0 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 2 );
	
	clean = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Remove previous boundaries"), wxDefaultPosition, wxDefaultSize, 0 );
	clean->SetValue(true);
	
	bSizer9->Add( clean, 0, wxALL, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	thresh2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	thresh1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	aperture->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	dilate->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	erode->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	approx->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	intra->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	clean->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnCancel ), NULL, this );
}

FindContoursSidebar_::~FindContoursSidebar_()
{
	// Disconnect Events
	thresh2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	thresh1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	aperture->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	dilate->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	erode->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	approx->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	intra->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	clean->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindContoursSidebar_::OnCancel ), NULL, this );
}

CropSidebar_::CropSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 190,150 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Crop Movie") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText106 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Use mouse to draw crop region"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	bSizer9->Add( m_staticText106, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText712 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("location:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText712->Wrap( -1 );
	fgSizer11->Add( m_staticText712, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	fromx = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer11->Add( fromx, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	fromy = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 0 );
	fgSizer11->Add( fromy, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText621 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText621->Wrap( -1 );
	fgSizer11->Add( m_staticText621, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	width = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 320 );
	fgSizer11->Add( width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	height = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 240 );
	fgSizer11->Add( height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	bSizer9->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	fromx->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	fromy->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CropSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CropSidebar_::OnCancel ), NULL, this );
}

CropSidebar_::~CropSidebar_()
{
	// Disconnect Events
	fromx->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	fromy->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CropSidebar_::OnChange ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CropSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CropSidebar_::OnCancel ), NULL, this );
}

ResizeMovieSidebar_::ResizeMovieSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 190,175 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Resize movie") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("New width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	width = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10240, 320 );
	fgSizer1->Add( width, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("New height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	height = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10240, 240 );
	fgSizer1->Add( height, 0, wxALL, 5 );
	
	bSizer9->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	constrain = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Constrain proportions"), wxDefaultPosition, wxDefaultSize, 0 );
	constrain->SetValue(true);
	
	bSizer9->Add( constrain, 0, wxALL, 5 );
	
	wxString interpolationChoices[] = { _("Nearest-neighbor"), _("Bilinear"), _("Pixel area relation"), _("Bicubic") };
	int interpolationNChoices = sizeof( interpolationChoices ) / sizeof( wxString );
	interpolation = new wxRadioBox( m_scrolledWindow3, wxID_ANY, _("Interpolation method"), wxDefaultPosition, wxDefaultSize, interpolationNChoices, interpolationChoices, 1, wxRA_SPECIFY_COLS );
	interpolation->SetSelection( 1 );
	bSizer9->Add( interpolation, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button122 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button122, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button131 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button131, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button121 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Reset"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button121, 0, wxALL, 2 );
	
	bSizer9->Add( bSizer111, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ResizeMovieSidebar_::OnChangeWidth ), NULL, this );
	height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ResizeMovieSidebar_::OnChangeHeight ), NULL, this );
	constrain->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnConstrain ), NULL, this );
	m_button122->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnOK ), NULL, this );
	m_button131->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnCancel ), NULL, this );
	m_button121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnReset ), NULL, this );
}

ResizeMovieSidebar_::~ResizeMovieSidebar_()
{
	// Disconnect Events
	width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ResizeMovieSidebar_::OnChangeWidth ), NULL, this );
	height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ResizeMovieSidebar_::OnChangeHeight ), NULL, this );
	constrain->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnConstrain ), NULL, this );
	m_button122->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnOK ), NULL, this );
	m_button131->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnCancel ), NULL, this );
	m_button121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResizeMovieSidebar_::OnReset ), NULL, this );
}

NormalizeContoursSidebar_::NormalizeContoursSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 190,250 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Resample Boundaries") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer42;
	sbSizer42 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Inter-vertex distance") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer36;
	fgSizer36 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer36->SetFlexibleDirection( wxBOTH );
	fgSizer36->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	isMinLength = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Minimum length"), wxDefaultPosition, wxDefaultSize, 0 );
	isMinLength->SetValue(true);
	
	fgSizer36->Add( isMinLength, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	minLength = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 1 );
	fgSizer36->Add( minLength, 0, wxALL, 1 );
	
	isMaxLength = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Maximum length"), wxDefaultPosition, wxDefaultSize, 0 );
	isMaxLength->SetValue(true);
	
	fgSizer36->Add( isMaxLength, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	maxLength = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 5 );
	fgSizer36->Add( maxLength, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	sbSizer42->Add( fgSizer36, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer42, 0, wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 0 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 2 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button122 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button122, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button1313 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button1313, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button1211 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button1211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	bSizer9->Add( bSizer111, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	isMinLength->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	minLength->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	isMaxLength->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	maxLength->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnChangePreview ), NULL, this );
	m_button122->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnOK ), NULL, this );
	m_button1313->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnCancel ), NULL, this );
	m_button1211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnApply ), NULL, this );
}

NormalizeContoursSidebar_::~NormalizeContoursSidebar_()
{
	// Disconnect Events
	isMinLength->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	minLength->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	isMaxLength->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	maxLength->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( NormalizeContoursSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnChangePreview ), NULL, this );
	m_button122->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnOK ), NULL, this );
	m_button1313->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnCancel ), NULL, this );
	m_button1211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NormalizeContoursSidebar_::OnApply ), NULL, this );
}

FilterContoursSidebar_::FilterContoursSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 200,300 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Filter Cells") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("by size...") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	isMinArea = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Minimum area"), wxDefaultPosition, wxDefaultSize, 0 );
	isMinArea->SetValue(true);
	
	fgSizer6->Add( isMinArea, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	minArea = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 10000, 3000 );
	fgSizer6->Add( minArea, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	isMaxArea = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Maximum area"), wxDefaultPosition, wxDefaultSize, 0 );
	
	fgSizer6->Add( isMaxArea, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	maxArea = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100000, 10000 );
	fgSizer6->Add( maxArea, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer8->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer8, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer81;
	sbSizer81 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("by distance to borders...") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	isMinDist = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Minimum distance"), wxDefaultPosition, wxDefaultSize, 0 );
	isMinDist->SetValue(true);
	
	fgSizer61->Add( isMinDist, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	minDist = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 3 );
	fgSizer61->Add( minDist, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer81->Add( fgSizer61, 1, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer81, 0, wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 2 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline3 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	isMinArea->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	minArea->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	isMaxArea->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	maxArea->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	isMinDist->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	minDist->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnCancel ), NULL, this );
}

FilterContoursSidebar_::~FilterContoursSidebar_()
{
	// Disconnect Events
	isMinArea->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	minArea->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	isMaxArea->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	maxArea->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	isMinDist->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	minDist->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FilterContoursSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FilterContoursSidebar_::OnCancel ), NULL, this );
}

EditContoursSidebar_::EditContoursSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 180,350 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Edit Cells") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	listbox = new wxListBox( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxSize( 50,-1 ), 0, NULL, wxLB_EXTENDED|wxLB_HSCROLL|wxLB_NEEDED_SB );
	listbox->Append( _("1234") );
	bSizer24->Add( listbox, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	m_button14 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Select all"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	bSizer25->Add( m_button14, 0, wxALL, 1 );
	
	m_button142 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Deselect all"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	bSizer25->Add( m_button142, 0, wxALL, 1 );
	
	m_button141 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Invert selection"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	bSizer25->Add( m_button141, 0, wxALL, 1 );
	
	m_button131 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Remove selected"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	bSizer25->Add( m_button131, 0, wxALL, 1 );
	
	m_button1312 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Remove all"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	bSizer25->Add( m_button1312, 0, wxALL, 1 );
	
	m_button1311 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Clean all Frames"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	bSizer25->Add( m_button1311, 0, wxALL, 1 );
	
	bSizer24->Add( bSizer25, 1, wxEXPAND, 5 );
	
	bSizer9->Add( bSizer24, 0, wxEXPAND, 5 );
	
	wxString useMouseToChoices[] = { _("Select cells"), _("Draw a new cell"), _("Drag a cell"), _("Drag a vertex") };
	int useMouseToNChoices = sizeof( useMouseToChoices ) / sizeof( wxString );
	useMouseTo = new wxRadioBox( m_scrolledWindow3, wxID_ANY, _("Use mouse to..."), wxDefaultPosition, wxDefaultSize, useMouseToNChoices, useMouseToChoices, 1, wxRA_SPECIFY_COLS );
	useMouseTo->SetSelection( 1 );
	bSizer9->Add( useMouseTo, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer9->Add( bSizer47, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button122 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button122, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button1313 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button1313, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button1211 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button1211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	bSizer9->Add( bSizer111, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	listbox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( EditContoursSidebar_::OnChange ), NULL, this );
	m_button14->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnSelectAll ), NULL, this );
	m_button142->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnDeselectAll ), NULL, this );
	m_button141->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnInvertSelection ), NULL, this );
	m_button131->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnDeleteSelected ), NULL, this );
	m_button1312->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnDeleteAll ), NULL, this );
	m_button1311->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnCleanAllFrames ), NULL, this );
	useMouseTo->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( EditContoursSidebar_::OnUseMouseTo ), NULL, this );
	m_button122->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnOK ), NULL, this );
	m_button1313->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnCancel ), NULL, this );
	m_button1211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnApply ), NULL, this );
}

EditContoursSidebar_::~EditContoursSidebar_()
{
	// Disconnect Events
	listbox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( EditContoursSidebar_::OnChange ), NULL, this );
	m_button14->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnSelectAll ), NULL, this );
	m_button142->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnDeselectAll ), NULL, this );
	m_button141->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnInvertSelection ), NULL, this );
	m_button131->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnDeleteSelected ), NULL, this );
	m_button1312->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnDeleteAll ), NULL, this );
	m_button1311->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnCleanAllFrames ), NULL, this );
	useMouseTo->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( EditContoursSidebar_::OnUseMouseTo ), NULL, this );
	m_button122->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnOK ), NULL, this );
	m_button1313->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnCancel ), NULL, this );
	m_button1211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditContoursSidebar_::OnApply ), NULL, this );
}

ManualContoursBottombar_::ManualContoursBottombar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("Click to outline, double-click to end an outline."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer12->Add( m_staticText8, 0, wxALL, 5 );
	
	
	bSizer12->Add( 0, 0, 1, wxEXPAND, 0 );
	
	m_button6 = new wxButton( this, wxID_ANY, _("Finish"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	bSizer12->Add( m_button6, 0, wxALL, 0 );
	
	this->SetSizer( bSizer12 );
	this->Layout();
}

ManualContoursBottombar_::~ManualContoursBottombar_()
{
}

FindFeaturesSidebar_::FindFeaturesSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 190,375 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Find Intracellular Features") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Minimum quality"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	quality = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("0.01"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer1->Add( quality, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Minimum distance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	minDist = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("4"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer1->Add( minDist, 0, wxALL, 5 );
	
	m_staticText61 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Harris parameter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer1->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	harrisK = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("0.04"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer1->Add( harrisK, 0, wxALL, 5 );
	
	m_staticText611 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Block size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	fgSizer1->Add( m_staticText611, 0, wxALL, 5 );
	
	blockSize = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 1 );
	fgSizer1->Add( blockSize, 0, wxALL, 5 );
	
	m_staticText6111 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Maximum count"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6111->Wrap( -1 );
	fgSizer1->Add( m_staticText6111, 0, wxALL, 5 );
	
	maxCount = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 100 );
	fgSizer1->Add( maxCount, 0, wxALL, 5 );
	
	bSizer9->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxString methodChoices[] = { _("Use eigen values"), _("Use Harris operator") };
	int methodNChoices = sizeof( methodChoices ) / sizeof( wxString );
	method = new wxRadioBox( m_scrolledWindow3, wxID_ANY, _("Method"), wxDefaultPosition, wxDefaultSize, methodNChoices, methodChoices, 1, wxRA_SPECIFY_COLS );
	method->SetSelection( 0 );
	bSizer9->Add( method, 0, wxALL|wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 0 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 2 );
	
	clean = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Remove previous features"), wxDefaultPosition, wxDefaultSize, 0 );
	clean->SetValue(true);
	
	bSizer9->Add( clean, 0, wxALL, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	quality->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	minDist->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	harrisK->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	blockSize->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	maxCount->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	method->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	clean->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnCancel ), NULL, this );
}

FindFeaturesSidebar_::~FindFeaturesSidebar_()
{
	// Disconnect Events
	quality->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	minDist->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	harrisK->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	blockSize->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	maxCount->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	method->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	clean->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFeaturesSidebar_::OnCancel ), NULL, this );
}

SubtractBackgroundSidebar_::SubtractBackgroundSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 200,390 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Subtract background") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	method = new wxChoicebook( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	m_panel8 = new wxPanel( method, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText22 = new wxStaticText( m_panel8, wxID_ANY, _("Uses average as background."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer26->Add( m_staticText22, 0, wxALL, 5 );
	
	m_staticText23 = new wxStaticText( m_panel8, wxID_ANY, _("No parameters available."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer26->Add( m_staticText23, 0, wxALL, 5 );
	
	m_panel8->SetSizer( bSizer26 );
	m_panel8->Layout();
	bSizer26->Fit( m_panel8 );
	method->AddPage( m_panel8, _("Average"), false );
	m_panel9 = new wxPanel( method, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText24 = new wxStaticText( m_panel9, wxID_ANY, _("Number of frames"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer12->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	numFrames = new wxSpinCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 10 );
	fgSizer12->Add( numFrames, 0, wxALL, 5 );
	
	m_staticText242 = new wxStaticText( m_panel9, wxID_ANY, _("Window size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText242->Wrap( -1 );
	fgSizer12->Add( m_staticText242, 0, wxALL, 5 );
	
	win_size = new wxSpinCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 2 );
	fgSizer12->Add( win_size, 0, wxALL, 5 );
	
	m_staticText241 = new wxStaticText( m_panel9, wxID_ANY, _("Number of Gaussians"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText241->Wrap( -1 );
	fgSizer12->Add( m_staticText241, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	n_gauss = new wxSpinCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 1 );
	fgSizer12->Add( n_gauss, 0, wxALL, 5 );
	
	m_staticText2411 = new wxStaticText( m_panel9, wxID_ANY, _("Background threshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2411->Wrap( -1 );
	fgSizer12->Add( m_staticText2411, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bg_threshold = new wxTextCtrl_double( m_panel9, wxID_ANY, _("0.7"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( bg_threshold, 0, wxALL, 5 );
	
	m_staticText24111 = new wxStaticText( m_panel9, wxID_ANY, _("Std threshold (lambda)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24111->Wrap( -1 );
	fgSizer12->Add( m_staticText24111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	std_threshold = new wxTextCtrl_double( m_panel9, wxID_ANY, _("2"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( std_threshold, 0, wxALL, 5 );
	
	m_staticText2412 = new wxStaticText( m_panel9, wxID_ANY, _("Minimum area"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2412->Wrap( -1 );
	fgSizer12->Add( m_staticText2412, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	minArea = new wxSpinCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 20 );
	fgSizer12->Add( minArea, 0, wxALL, 5 );
	
	m_staticText24121 = new wxStaticText( m_panel9, wxID_ANY, _("Initial weight"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24121->Wrap( -1 );
	fgSizer12->Add( m_staticText24121, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	weight_init = new wxTextCtrl_double( m_panel9, wxID_ANY, _("0.05"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( weight_init, 0, wxALL, 5 );
	
	m_staticText24122 = new wxStaticText( m_panel9, wxID_ANY, _("Initial variance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24122->Wrap( -1 );
	fgSizer12->Add( m_staticText24122, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	variance_init = new wxSpinCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 40 );
	fgSizer12->Add( variance_init, 0, wxALL, 5 );
	
	m_panel9->SetSizer( fgSizer12 );
	m_panel9->Layout();
	fgSizer12->Fit( m_panel9 );
	method->AddPage( m_panel9, _("Gaussian"), true );
	bSizer9->Add( method, 0, wxEXPAND | wxALL, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline3 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	method->Connect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	numFrames->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	win_size->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	n_gauss->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	bg_threshold->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	std_threshold->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	minArea->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	weight_init->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	variance_init->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnCancel ), NULL, this );
}

SubtractBackgroundSidebar_::~SubtractBackgroundSidebar_()
{
	// Disconnect Events
	method->Disconnect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	numFrames->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	win_size->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	n_gauss->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	bg_threshold->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	std_threshold->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	minArea->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	weight_init->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	variance_init->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SubtractBackgroundSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SubtractBackgroundSidebar_::OnCancel ), NULL, this );
}

ImproveContoursSidebar_::ImproveContoursSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 200,420 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Improve Boundaries") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer16;
	sbSizer16 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Snake Energy weights") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("alpha (continuity)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	alpha = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 1 );
	fgSizer1->Add( alpha, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("beta (curvature)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	beta = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 1 );
	fgSizer1->Add( beta, 0, wxALL, 5 );
	
	m_staticText61 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("gamma (image)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer1->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	gamma = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 1 );
	fgSizer1->Add( gamma, 0, wxALL, 5 );
	
	sbSizer16->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	gradient = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Use image gradient (gamma)"), wxDefaultPosition, wxDefaultSize, 0 );
	gradient->SetValue(true);
	
	sbSizer16->Add( gradient, 0, wxALL, 5 );
	
	bSizer9->Add( sbSizer16, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer161;
	sbSizer161 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Search window") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText71 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer11->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	width = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 3 );
	fgSizer11->Add( width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText62 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer11->Add( m_staticText62, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	height = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 3 );
	fgSizer11->Add( height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	sbSizer161->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer161, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer162;
	sbSizer162 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Termination criteria") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText72 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("max iterations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	fgSizer12->Add( m_staticText72, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	max_iter = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 10 );
	fgSizer12->Add( max_iter, 1, wxALL, 0 );
	
	m_staticText73 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("epsilon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	fgSizer12->Add( m_staticText73, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	epsilon = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("0.1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( epsilon, 0, wxALL, 1 );
	
	sbSizer162->Add( fgSizer12, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer162, 0, wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 2 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	alpha->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	beta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	gamma->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	gradient->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	max_iter->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	epsilon->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnCancel ), NULL, this );
}

ImproveContoursSidebar_::~ImproveContoursSidebar_()
{
	// Disconnect Events
	alpha->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	beta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	gamma->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	gradient->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	max_iter->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	epsilon->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ImproveContoursSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImproveContoursSidebar_::OnCancel ), NULL, this );
}

MatchTemplateSidebar_::MatchTemplateSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 190,290 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Template-Match Tracking") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText78 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Method:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText78->Wrap( -1 );
	bSizer46->Add( m_staticText78, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	wxString methodChoices[] = { _("Difference Square"), _("Diff. Square (Normalized)"), _("Correlation"), _("Correlation (Normalized)"), _("Correlation Coefficient"), _("Corr. Coeff. (Normalized)") };
	int methodNChoices = sizeof( methodChoices ) / sizeof( wxString );
	method = new wxChoice( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, methodNChoices, methodChoices, 0 );
	method->SetSelection( 1 );
	bSizer46->Add( method, 0, wxALL, 1 );
	
	bSizer9->Add( bSizer46, 0, wxEXPAND, 5 );
	
	useFirst = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Use first frame template for all"), wxDefaultPosition, wxDefaultSize, 0 );
	useFirst->SetValue(true);
	
	bSizer9->Add( useFirst, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer161;
	sbSizer161 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Search window") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText71 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer11->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	width = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 10 );
	fgSizer11->Add( width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText62 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer11->Add( m_staticText62, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	height = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 10 );
	fgSizer11->Add( height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	sbSizer161->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer161, 0, wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline17 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline17, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button121 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button121, 0, wxALL, 2 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	method->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	useFirst->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnCancel ), NULL, this );
	m_button121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnApply ), NULL, this );
}

MatchTemplateSidebar_::~MatchTemplateSidebar_()
{
	// Disconnect Events
	method->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	useFirst->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MatchTemplateSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnCancel ), NULL, this );
	m_button121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MatchTemplateSidebar_::OnApply ), NULL, this );
}

CamShiftSidebar_::CamShiftSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 195,290 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("CAM-Shift Tracking") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Histogram bins"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	hsize = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 2, 100, 20 );
	fgSizer1->Add( hsize, 0, wxALL, 5 );
	
	bSizer9->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	useFirst = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Use first frame template for all"), wxDefaultPosition, wxDefaultSize, 0 );
	useFirst->SetValue(true);
	
	bSizer9->Add( useFirst, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer162;
	sbSizer162 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Termination criteria") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText72 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("max iterations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	fgSizer12->Add( m_staticText72, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	max_iter = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 10 );
	fgSizer12->Add( max_iter, 1, wxALL, 0 );
	
	m_staticText73 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("epsilon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	fgSizer12->Add( m_staticText73, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	epsilon = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("0.1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( epsilon, 0, wxALL, 1 );
	
	sbSizer162->Add( fgSizer12, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer162, 0, wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline17 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline17, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button121 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button121, 0, wxALL, 2 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	hsize->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	useFirst->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	max_iter->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	epsilon->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnCancel ), NULL, this );
	m_button121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnApply ), NULL, this );
}

CamShiftSidebar_::~CamShiftSidebar_()
{
	// Disconnect Events
	hsize->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	useFirst->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	max_iter->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	epsilon->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CamShiftSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnCancel ), NULL, this );
	m_button121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CamShiftSidebar_::OnApply ), NULL, this );
}

LKContoursSidebar_::LKContoursSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 200,425 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Optical Flow Tracking") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Pyramid levels"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	level = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 10, 3 );
	fgSizer1->Add( level, 0, wxALL, 5 );
	
	bSizer9->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	useAvailable = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Use available tracking if any"), wxDefaultPosition, wxDefaultSize, 0 );
	useAvailable->SetValue(true);
	
	bSizer9->Add( useAvailable, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer28;
	sbSizer28 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Outliers") ), wxVERTICAL );
	
	fixOutliers = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Detect and fix outliers"), wxDefaultPosition, wxDefaultSize, 0 );
	fixOutliers->SetValue(true);
	
	sbSizer28->Add( fixOutliers, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText74 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Outlier cutoff (stdev):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText74->Wrap( -1 );
	fgSizer13->Add( m_staticText74, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	outliers = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("2"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer13->Add( outliers, 0, wxALL, 5 );
	
	m_staticText741 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Interpolation window"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText741->Wrap( -1 );
	fgSizer13->Add( m_staticText741, 0, wxALL, 5 );
	
	intwin = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 10 );
	fgSizer13->Add( intwin, 0, wxALL, 5 );
	
	sbSizer28->Add( fgSizer13, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer28, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer161;
	sbSizer161 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Search window") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText71 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer11->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	width = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 2, 10, 6 );
	fgSizer11->Add( width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText62 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer11->Add( m_staticText62, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	height = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 2, 10, 6 );
	fgSizer11->Add( height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	sbSizer161->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer161, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer162;
	sbSizer162 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Termination criteria") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText72 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("max iterations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	fgSizer12->Add( m_staticText72, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	max_iter = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 10 );
	fgSizer12->Add( max_iter, 1, wxALL, 0 );
	
	m_staticText73 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("epsilon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	fgSizer12->Add( m_staticText73, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	epsilon = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("0.1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( epsilon, 0, wxALL, 1 );
	
	sbSizer162->Add( fgSizer12, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer162, 0, wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline17 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline17, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button121 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button121, 0, wxALL, 2 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	level->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	useAvailable->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	fixOutliers->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	outliers->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	intwin->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	max_iter->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	epsilon->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnCancel ), NULL, this );
	m_button121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnApply ), NULL, this );
}

LKContoursSidebar_::~LKContoursSidebar_()
{
	// Disconnect Events
	level->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	useAvailable->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	fixOutliers->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	outliers->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	intwin->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	max_iter->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	epsilon->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LKContoursSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnCancel ), NULL, this );
	m_button121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LKContoursSidebar_::OnApply ), NULL, this );
}

TrackContoursSidebar_::TrackContoursSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 225,510 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Active Snake Tracking") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer16;
	sbSizer16 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Snake Energy weights") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText721 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Match"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText721->Wrap( -1 );
	fgSizer1->Add( m_staticText721, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText7211 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("Improve"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText7211->Wrap( -1 );
	fgSizer1->Add( m_staticText7211, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("alpha (continuity)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	oalpha = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 3 );
	fgSizer1->Add( oalpha, 0, wxALL, 1 );
	
	alpha = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 1 );
	fgSizer1->Add( alpha, 0, wxALL, 1 );
	
	m_staticText6 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("beta (curvature)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	obeta = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 5 );
	fgSizer1->Add( obeta, 0, wxALL, 1 );
	
	beta = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 1 );
	fgSizer1->Add( beta, 0, wxALL, 1 );
	
	m_staticText61 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("gamma (image)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer1->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	ogamma = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 10 );
	fgSizer1->Add( ogamma, 0, wxALL, 1 );
	
	gamma = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 10 );
	fgSizer1->Add( gamma, 0, wxALL, 1 );
	
	m_staticText612 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("signed gradient"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText612->Wrap( -1 );
	fgSizer1->Add( m_staticText612, 0, wxALL, 5 );
	
	oomega = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 10 );
	fgSizer1->Add( oomega, 0, wxALL, 1 );
	
	
	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText6111 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("arc length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6111->Wrap( -1 );
	fgSizer1->Add( m_staticText6111, 0, wxALL, 5 );
	
	ozeta = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 1 );
	fgSizer1->Add( ozeta, 0, wxALL, 1 );
	
	
	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText611 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("intensity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	fgSizer1->Add( m_staticText611, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	oteta = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 100, 0 );
	fgSizer1->Add( oteta, 0, wxALL, 1 );
	
	sbSizer16->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	gradient = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Use image gradient (gamma)"), wxDefaultPosition, wxDefaultSize, 0 );
	gradient->SetValue(true);
	
	sbSizer16->Add( gradient, 0, wxALL, 5 );
	
	useAvailable = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Use available tracking if any"), wxDefaultPosition, wxDefaultSize, 0 );
	useAvailable->SetValue(true);
	
	sbSizer16->Add( useAvailable, 0, wxALL, 5 );
	
	bSizer9->Add( sbSizer16, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer161;
	sbSizer161 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Search window") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText71 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer11->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	width = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 3 );
	fgSizer11->Add( width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText62 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer11->Add( m_staticText62, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	height = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 3 );
	fgSizer11->Add( height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	sbSizer161->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer161, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer162;
	sbSizer162 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow3, wxID_ANY, _("Termination criteria") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText72 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("max iterations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	fgSizer12->Add( m_staticText72, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	max_iter = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 10 );
	fgSizer12->Add( max_iter, 1, wxALL, 0 );
	
	m_staticText73 = new wxStaticText( m_scrolledWindow3, wxID_ANY, _("epsilon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	fgSizer12->Add( m_staticText73, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	epsilon = new wxTextCtrl_double( m_scrolledWindow3, wxID_ANY, _("0.1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( epsilon, 0, wxALL, 1 );
	
	sbSizer162->Add( fgSizer12, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer162, 0, wxEXPAND, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 5 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button12 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button12, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button13 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button13, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button121 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer11->Add( m_button121, 0, wxALL, 2 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	oalpha->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	alpha->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	obeta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	beta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	ogamma->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	gamma->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	oomega->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	ozeta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	oteta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	gradient->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	useAvailable->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	max_iter->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	epsilon->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnOK ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnCancel ), NULL, this );
	m_button121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnApply ), NULL, this );
}

TrackContoursSidebar_::~TrackContoursSidebar_()
{
	// Disconnect Events
	oalpha->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	alpha->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	obeta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	beta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	ogamma->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	gamma->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	oomega->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	ozeta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	oteta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	gradient->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	useAvailable->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	max_iter->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	epsilon->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( TrackContoursSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnChangePreview ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnOK ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnCancel ), NULL, this );
	m_button121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackContoursSidebar_::OnApply ), NULL, this );
}

CombinedTrackingSidebar_::CombinedTrackingSidebar_( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 230,375 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Combined Tracking") ), wxVERTICAL );
	
	m_scrolledWindow3 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_choicebook3 = new wxChoicebook( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	m_choicebook3->SetBackgroundColour( wxColour( 225, 225, 225 ) );
	
	m_panel22 = new wxPanel( m_choicebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	wxString initial_methodChoices[] = { _("None"), _("Template matching"), _("CAM-Shift") };
	int initial_methodNChoices = sizeof( initial_methodChoices ) / sizeof( wxString );
	initial_method = new wxRadioBox( m_panel22, wxID_ANY, _("Initial tracking"), wxDefaultPosition, wxDefaultSize, initial_methodNChoices, initial_methodChoices, 1, wxRA_SPECIFY_COLS );
	initial_method->SetSelection( 0 );
	bSizer52->Add( initial_method, 0, wxALL|wxEXPAND, 5 );
	
	useLK = new wxCheckBox( m_panel22, wxID_ANY, _("Optical Flow tracking"), wxDefaultPosition, wxDefaultSize, 0 );
	useLK->SetValue(true);
	
	bSizer52->Add( useLK, 0, wxALL, 5 );
	
	useAS = new wxCheckBox( m_panel22, wxID_ANY, _("Active Snake tracking"), wxDefaultPosition, wxDefaultSize, 0 );
	useAS->SetValue(true);
	
	bSizer52->Add( useAS, 0, wxALL, 5 );
	
	useNC = new wxCheckBox( m_panel22, wxID_ANY, _("Resample boundaries"), wxDefaultPosition, wxDefaultSize, 0 );
	useNC->SetValue(true);
	
	bSizer52->Add( useNC, 0, wxALL, 5 );
	
	m_panel22->SetSizer( bSizer52 );
	m_panel22->Layout();
	bSizer52->Fit( m_panel22 );
	m_choicebook3->AddPage( m_panel22, _("Select methods to apply"), true );
	m_panel23 = new wxPanel( m_choicebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText78 = new wxStaticText( m_panel23, wxID_ANY, _("Method:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText78->Wrap( -1 );
	bSizer46->Add( m_staticText78, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	wxString mt_methodChoices[] = { _("Difference Square"), _("Diff. Square (Normalized)"), _("Correlation"), _("Correlation (Normalized)"), _("Correlation Coefficient"), _("Corr. Coeff. (Normalized)") };
	int mt_methodNChoices = sizeof( mt_methodChoices ) / sizeof( wxString );
	mt_method = new wxChoice( m_panel23, wxID_ANY, wxDefaultPosition, wxDefaultSize, mt_methodNChoices, mt_methodChoices, 0 );
	mt_method->SetSelection( 1 );
	bSizer46->Add( mt_method, 0, wxALL, 1 );
	
	bSizer91->Add( bSizer46, 0, wxEXPAND, 5 );
	
	mt_useFirst = new wxCheckBox( m_panel23, wxID_ANY, _("Use first frame template for all"), wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer91->Add( mt_useFirst, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer161;
	sbSizer161 = new wxStaticBoxSizer( new wxStaticBox( m_panel23, wxID_ANY, _("Search window") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText71 = new wxStaticText( m_panel23, wxID_ANY, _("width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer11->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	mt_width = new wxSpinCtrl( m_panel23, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 30 );
	fgSizer11->Add( mt_width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText62 = new wxStaticText( m_panel23, wxID_ANY, _("height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer11->Add( m_staticText62, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	mt_height = new wxSpinCtrl( m_panel23, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 30 );
	fgSizer11->Add( mt_height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	sbSizer161->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	bSizer91->Add( sbSizer161, 0, wxEXPAND, 5 );
	
	m_panel23->SetSizer( bSizer91 );
	m_panel23->Layout();
	bSizer91->Fit( m_panel23 );
	m_choicebook3->AddPage( m_panel23, _("Template Matching parameters"), false );
	m_panel24 = new wxPanel( m_choicebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_panel24, wxID_ANY, _("Histogram bins"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	cs_hsize = new wxSpinCtrl( m_panel24, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 2, 100, 20 );
	fgSizer1->Add( cs_hsize, 0, wxALL, 5 );
	
	bSizer92->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	cs_useFirst = new wxCheckBox( m_panel24, wxID_ANY, _("Use first frame template for all"), wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer92->Add( cs_useFirst, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer162;
	sbSizer162 = new wxStaticBoxSizer( new wxStaticBox( m_panel24, wxID_ANY, _("Termination criteria") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText72 = new wxStaticText( m_panel24, wxID_ANY, _("max iterations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	fgSizer12->Add( m_staticText72, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	cs_max_iter = new wxSpinCtrl( m_panel24, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 10 );
	fgSizer12->Add( cs_max_iter, 1, wxALL, 0 );
	
	m_staticText73 = new wxStaticText( m_panel24, wxID_ANY, _("epsilon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	fgSizer12->Add( m_staticText73, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	cs_epsilon = new wxTextCtrl_double( m_panel24, wxID_ANY, _("0.1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer12->Add( cs_epsilon, 0, wxALL, 1 );
	
	sbSizer162->Add( fgSizer12, 0, wxEXPAND, 5 );
	
	bSizer92->Add( sbSizer162, 0, wxEXPAND, 5 );
	
	m_panel24->SetSizer( bSizer92 );
	m_panel24->Layout();
	bSizer92->Fit( m_panel24 );
	m_choicebook3->AddPage( m_panel24, _("CAM-Shift parameters"), false );
	m_panel25 = new wxPanel( m_choicebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer14;
	fgSizer14 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer14->SetFlexibleDirection( wxBOTH );
	fgSizer14->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText75 = new wxStaticText( m_panel25, wxID_ANY, _("Pyramid levels"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText75->Wrap( -1 );
	fgSizer14->Add( m_staticText75, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	lk_level = new wxSpinCtrl( m_panel25, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 10, 3 );
	fgSizer14->Add( lk_level, 0, wxALL, 5 );
	
	bSizer93->Add( fgSizer14, 0, wxEXPAND, 5 );
	
	lk_useAvailable = new wxCheckBox( m_panel25, wxID_ANY, _("Use available tracking if any"), wxDefaultPosition, wxDefaultSize, 0 );
	lk_useAvailable->SetValue(true);
	
	bSizer93->Add( lk_useAvailable, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer28;
	sbSizer28 = new wxStaticBoxSizer( new wxStaticBox( m_panel25, wxID_ANY, _("Outliers") ), wxVERTICAL );
	
	lk_fixOutliers = new wxCheckBox( m_panel25, wxID_ANY, _("Detect and fix outliers"), wxDefaultPosition, wxDefaultSize, 0 );
	lk_fixOutliers->SetValue(true);
	
	sbSizer28->Add( lk_fixOutliers, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText74 = new wxStaticText( m_panel25, wxID_ANY, _("Outlier cutoff (stdev):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText74->Wrap( -1 );
	fgSizer13->Add( m_staticText74, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	lk_outliers = new wxTextCtrl_double( m_panel25, wxID_ANY, _("2.5"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer13->Add( lk_outliers, 0, wxALL, 5 );
	
	m_staticText741 = new wxStaticText( m_panel25, wxID_ANY, _("Interpolation window"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText741->Wrap( -1 );
	fgSizer13->Add( m_staticText741, 0, wxALL, 5 );
	
	lk_intwin = new wxSpinCtrl( m_panel25, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 10 );
	fgSizer13->Add( lk_intwin, 0, wxALL, 5 );
	
	sbSizer28->Add( fgSizer13, 0, wxEXPAND, 5 );
	
	bSizer93->Add( sbSizer28, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1611;
	sbSizer1611 = new wxStaticBoxSizer( new wxStaticBox( m_panel25, wxID_ANY, _("Search window") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer111;
	fgSizer111 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer111->SetFlexibleDirection( wxBOTH );
	fgSizer111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText711 = new wxStaticText( m_panel25, wxID_ANY, _("width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText711->Wrap( -1 );
	fgSizer111->Add( m_staticText711, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	lk_width = new wxSpinCtrl( m_panel25, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 2, 10, 6 );
	fgSizer111->Add( lk_width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText621 = new wxStaticText( m_panel25, wxID_ANY, _("height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText621->Wrap( -1 );
	fgSizer111->Add( m_staticText621, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	lk_height = new wxSpinCtrl( m_panel25, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 2, 10, 6 );
	fgSizer111->Add( lk_height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	sbSizer1611->Add( fgSizer111, 0, wxEXPAND, 5 );
	
	bSizer93->Add( sbSizer1611, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1621;
	sbSizer1621 = new wxStaticBoxSizer( new wxStaticBox( m_panel25, wxID_ANY, _("Termination lk_criteria") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer121;
	fgSizer121 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer121->SetFlexibleDirection( wxBOTH );
	fgSizer121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText721 = new wxStaticText( m_panel25, wxID_ANY, _("max iterations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText721->Wrap( -1 );
	fgSizer121->Add( m_staticText721, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	lk_max_iter = new wxSpinCtrl( m_panel25, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 10 );
	fgSizer121->Add( lk_max_iter, 1, wxALL, 0 );
	
	m_staticText731 = new wxStaticText( m_panel25, wxID_ANY, _("epsilon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText731->Wrap( -1 );
	fgSizer121->Add( m_staticText731, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	lk_epsilon = new wxTextCtrl_double( m_panel25, wxID_ANY, _("0.1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer121->Add( lk_epsilon, 0, wxALL, 1 );
	
	sbSizer1621->Add( fgSizer121, 0, wxEXPAND, 5 );
	
	bSizer93->Add( sbSizer1621, 0, wxEXPAND, 5 );
	
	m_panel25->SetSizer( bSizer93 );
	m_panel25->Layout();
	bSizer93->Fit( m_panel25 );
	m_choicebook3->AddPage( m_panel25, _("Optical Flow parameters"), false );
	m_panel26 = new wxPanel( m_choicebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer16;
	sbSizer16 = new wxStaticBoxSizer( new wxStaticBox( m_panel26, wxID_ANY, _("Snake Energy weights") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer15;
	fgSizer15 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer15->SetFlexibleDirection( wxBOTH );
	fgSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer15->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText7212 = new wxStaticText( m_panel26, wxID_ANY, _("Match"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText7212->Wrap( -1 );
	fgSizer15->Add( m_staticText7212, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText7211 = new wxStaticText( m_panel26, wxID_ANY, _("Improve"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText7211->Wrap( -1 );
	fgSizer15->Add( m_staticText7211, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText76 = new wxStaticText( m_panel26, wxID_ANY, _("alpha (continuity)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText76->Wrap( -1 );
	fgSizer15->Add( m_staticText76, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	as_oalpha = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 10 );
	fgSizer15->Add( as_oalpha, 0, wxALL, 1 );
	
	as_alpha = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 30 );
	fgSizer15->Add( as_alpha, 0, wxALL, 1 );
	
	m_staticText6 = new wxStaticText( m_panel26, wxID_ANY, _("beta (curvature)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer15->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	as_obeta = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 8 );
	fgSizer15->Add( as_obeta, 0, wxALL, 1 );
	
	as_beta = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 20 );
	fgSizer15->Add( as_beta, 0, wxALL, 1 );
	
	m_staticText61 = new wxStaticText( m_panel26, wxID_ANY, _("gamma (image)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer15->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	as_ogamma = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 1 );
	fgSizer15->Add( as_ogamma, 0, wxALL, 1 );
	
	as_gamma = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 30 );
	fgSizer15->Add( as_gamma, 0, wxALL, 1 );
	
	m_staticText612 = new wxStaticText( m_panel26, wxID_ANY, _("signed gradient"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText612->Wrap( -1 );
	fgSizer15->Add( m_staticText612, 0, wxALL, 5 );
	
	as_oomega = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 1 );
	fgSizer15->Add( as_oomega, 0, wxALL, 1 );
	
	
	fgSizer15->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText6111 = new wxStaticText( m_panel26, wxID_ANY, _("arc length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6111->Wrap( -1 );
	fgSizer15->Add( m_staticText6111, 0, wxALL, 5 );
	
	as_ozeta = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 5 );
	fgSizer15->Add( as_ozeta, 0, wxALL, 1 );
	
	
	fgSizer15->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText611 = new wxStaticText( m_panel26, wxID_ANY, _("intensity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	fgSizer15->Add( m_staticText611, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	as_oteta = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 1000, 0 );
	fgSizer15->Add( as_oteta, 0, wxALL, 1 );
	
	sbSizer16->Add( fgSizer15, 0, wxEXPAND, 5 );
	
	as_gradient = new wxCheckBox( m_panel26, wxID_ANY, _("Use image gradient (gamma)"), wxDefaultPosition, wxDefaultSize, 0 );
	as_gradient->SetValue(true);
	
	sbSizer16->Add( as_gradient, 0, wxALL, 5 );
	
	as_useAvailable = new wxCheckBox( m_panel26, wxID_ANY, _("Use available tracking if any"), wxDefaultPosition, wxDefaultSize, 0 );
	as_useAvailable->SetValue(true);
	
	sbSizer16->Add( as_useAvailable, 0, wxALL, 5 );
	
	bSizer94->Add( sbSizer16, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1612;
	sbSizer1612 = new wxStaticBoxSizer( new wxStaticBox( m_panel26, wxID_ANY, _("Search window") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer112;
	fgSizer112 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer112->SetFlexibleDirection( wxBOTH );
	fgSizer112->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText712 = new wxStaticText( m_panel26, wxID_ANY, _("width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText712->Wrap( -1 );
	fgSizer112->Add( m_staticText712, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	as_width = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 4 );
	fgSizer112->Add( as_width, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_staticText622 = new wxStaticText( m_panel26, wxID_ANY, _("height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText622->Wrap( -1 );
	fgSizer112->Add( m_staticText622, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	as_height = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 10, 4 );
	fgSizer112->Add( as_height, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	sbSizer1612->Add( fgSizer112, 0, wxEXPAND, 5 );
	
	bSizer94->Add( sbSizer1612, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1622;
	sbSizer1622 = new wxStaticBoxSizer( new wxStaticBox( m_panel26, wxID_ANY, _("Termination as_criteria") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer122;
	fgSizer122 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer122->SetFlexibleDirection( wxBOTH );
	fgSizer122->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText722 = new wxStaticText( m_panel26, wxID_ANY, _("max iterations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText722->Wrap( -1 );
	fgSizer122->Add( m_staticText722, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	as_max_iter = new wxSpinCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 1000, 10 );
	fgSizer122->Add( as_max_iter, 1, wxALL, 0 );
	
	m_staticText732 = new wxStaticText( m_panel26, wxID_ANY, _("epsilon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText732->Wrap( -1 );
	fgSizer122->Add( m_staticText732, 0, wxALL|wxALIGN_CENTER_VERTICAL, 3 );
	
	as_epsilon = new wxTextCtrl_double( m_panel26, wxID_ANY, _("0.1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer122->Add( as_epsilon, 0, wxALL, 1 );
	
	sbSizer1622->Add( fgSizer122, 0, wxEXPAND, 5 );
	
	bSizer94->Add( sbSizer1622, 0, wxEXPAND, 5 );
	
	m_panel26->SetSizer( bSizer94 );
	m_panel26->Layout();
	bSizer94->Fit( m_panel26 );
	m_choicebook3->AddPage( m_panel26, _("Active Snake parameters"), false );
	m_panel21 = new wxPanel( m_choicebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer42;
	sbSizer42 = new wxStaticBoxSizer( new wxStaticBox( m_panel21, wxID_ANY, _("Inter-vertex distance") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer36;
	fgSizer36 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer36->SetFlexibleDirection( wxBOTH );
	fgSizer36->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	nc_isMinLength = new wxCheckBox( m_panel21, wxID_ANY, _("Minimum length"), wxDefaultPosition, wxDefaultSize, 0 );
	nc_isMinLength->SetValue(true);
	
	fgSizer36->Add( nc_isMinLength, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	nc_minLength = new wxSpinCtrl( m_panel21, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 1 );
	fgSizer36->Add( nc_minLength, 0, wxALL, 1 );
	
	nc_isMaxLength = new wxCheckBox( m_panel21, wxID_ANY, _("Maximum length"), wxDefaultPosition, wxDefaultSize, 0 );
	nc_isMaxLength->SetValue(true);
	
	fgSizer36->Add( nc_isMaxLength, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	nc_maxLength = new wxSpinCtrl( m_panel21, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 100, 5 );
	fgSizer36->Add( nc_maxLength, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	sbSizer42->Add( fgSizer36, 0, wxEXPAND, 5 );
	
	m_panel21->SetSizer( sbSizer42 );
	m_panel21->Layout();
	sbSizer42->Fit( m_panel21 );
	m_choicebook3->AddPage( m_panel21, _("Resampling parameters"), false );
	bSizer9->Add( m_choicebook3, 0, wxEXPAND | wxALL, 5 );
	
	wxString scopeChoices[] = { _("Apply to current frame only"), _("Apply to all frames"), _("Apply to current frame on") };
	int scopeNChoices = sizeof( scopeChoices ) / sizeof( wxString );
	scope = new wxRadioBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, scopeNChoices, scopeChoices, 1, wxRA_SPECIFY_COLS );
	scope->SetSelection( 1 );
	bSizer9->Add( scope, 0, wxALL|wxEXPAND, 2 );
	
	preview = new wxCheckBox( m_scrolledWindow3, wxID_ANY, _("Show preview"), wxDefaultPosition, wxDefaultSize, 0 );
	preview->SetValue(true);
	
	bSizer9->Add( preview, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button122 = new wxButton( m_scrolledWindow3, wxID_ANY, _("OK"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button122, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button131 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button131, 0, wxALL|wxALIGN_BOTTOM, 2 );
	
	m_button121 = new wxButton( m_scrolledWindow3, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer111->Add( m_button121, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );
	
	bSizer9->Add( bSizer111, 0, 0, 5 );
	
	m_scrolledWindow3->SetSizer( bSizer9 );
	m_scrolledWindow3->Layout();
	bSizer9->Fit( m_scrolledWindow3 );
	sbSizer2->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( sbSizer2 );
	this->Layout();
	
	// Connect Events
	initial_method->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	useLK->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	useAS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	useNC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_method->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_useFirst->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_hsize->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_useFirst->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_max_iter->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_epsilon->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_level->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_useAvailable->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_fixOutliers->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_outliers->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_intwin->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_max_iter->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_epsilon->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_oalpha->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_alpha->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_obeta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_beta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_ogamma->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_gamma->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_oomega->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_ozeta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_oteta->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_gradient->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_useAvailable->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_width->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_height->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_max_iter->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_epsilon->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_isMinLength->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_minLength->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_isMaxLength->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_maxLength->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	preview->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChangePreview ), NULL, this );
	m_button122->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnOK ), NULL, this );
	m_button131->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnCancel ), NULL, this );
	m_button121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnApply ), NULL, this );
}

CombinedTrackingSidebar_::~CombinedTrackingSidebar_()
{
	// Disconnect Events
	initial_method->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	useLK->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	useAS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	useNC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_method->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_useFirst->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	mt_height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_hsize->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_useFirst->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_max_iter->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	cs_epsilon->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_level->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_useAvailable->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_fixOutliers->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_outliers->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_intwin->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_max_iter->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	lk_epsilon->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_oalpha->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_alpha->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_obeta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_beta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_ogamma->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_gamma->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_oomega->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_ozeta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_oteta->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_gradient->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_useAvailable->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_width->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_height->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_max_iter->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	as_epsilon->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_isMinLength->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_minLength->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_isMaxLength->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	nc_maxLength->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( CombinedTrackingSidebar_::OnChange ), NULL, this );
	preview->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnChangePreview ), NULL, this );
	m_button122->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnOK ), NULL, this );
	m_button131->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnCancel ), NULL, this );
	m_button121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CombinedTrackingSidebar_::OnApply ), NULL, this );
}

PreferencesDialog_::PreferencesDialog_( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	c_Notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel12 = new wxPanel( c_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel12, wxID_ANY, _("Video codec") ), wxVERTICAL );
	
	c_SavingCodecUseCombo = new wxRadioButton( m_panel12, wxID_ANY, _("Use the following selected codec when saving files:"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	c_SavingCodecUseCombo->SetValue( true ); 
	sbSizer5->Add( c_SavingCodecUseCombo, 0, wxALL, 5 );
	
	wxString c_SavingCodecComboChoices[] = { _("Intel IYUV (uncompressed)"), _("CVID Cinepak codec by Radius"), _("DIVX MPEG-4"), _("Prompt for options upon saving (Windows only)") };
	int c_SavingCodecComboNChoices = sizeof( c_SavingCodecComboChoices ) / sizeof( wxString );
	c_SavingCodecCombo = new wxChoice( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, c_SavingCodecComboNChoices, c_SavingCodecComboChoices, 0 );
	c_SavingCodecCombo->SetSelection( 0 );
	sbSizer5->Add( c_SavingCodecCombo, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	c_SavingCodecUseFOURCC = new wxRadioButton( m_panel12, wxID_ANY, _("or enter the four letter code (FOURCC) of the codec:"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( c_SavingCodecUseFOURCC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_SavingCodecFOURCC = new wxTextCtrl( m_panel12, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 35,-1 ), 0 );
	c_SavingCodecFOURCC->SetMaxLength( 4 ); 
	bSizer15->Add( c_SavingCodecFOURCC, 0, wxALL, 5 );
	
	sbSizer5->Add( bSizer15, 1, wxEXPAND, 5 );
	
	bSizer13->Add( sbSizer5, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel12, wxID_ANY, _("Dimensions") ), wxVERTICAL );
	
	c_SavingSizeOverride = new wxCheckBox( m_panel12, wxID_ANY, _("Overwrite dimensions with the following values when saving:"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbSizer4->Add( c_SavingSizeOverride, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 1, 4, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText14 = new wxStaticText( m_panel12, wxID_ANY, _("Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	fgSizer2->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_SavingSizeWidth = new wxTextCtrl( m_panel12, wxID_ANY, _("320"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer2->Add( c_SavingSizeWidth, 0, wxALL, 5 );
	
	m_staticText141 = new wxStaticText( m_panel12, wxID_ANY, _("Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	fgSizer2->Add( m_staticText141, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_SavingSizeHeight = new wxTextCtrl( m_panel12, wxID_ANY, _("240"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer2->Add( c_SavingSizeHeight, 0, wxALL, 5 );
	
	sbSizer4->Add( fgSizer2, 1, wxEXPAND, 5 );
	
	bSizer13->Add( sbSizer4, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( m_panel12, wxID_ANY, _("Frames per second") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText142 = new wxStaticText( m_panel12, wxID_ANY, _("Default f.p.s."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText142->Wrap( -1 );
	fgSizer21->Add( m_staticText142, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_SavingFpsDefault = new wxSpinCtrl( m_panel12, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 99, 5 );
	fgSizer21->Add( c_SavingFpsDefault, 0, wxALL, 5 );
	
	sbSizer41->Add( fgSizer21, 1, wxEXPAND, 5 );
	
	c_SavingFpsOverride = new wxCheckBox( m_panel12, wxID_ANY, _("Overwrite fps of movies with this value"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbSizer41->Add( c_SavingFpsOverride, 0, wxALL, 5 );
	
	bSizer13->Add( sbSizer41, 0, wxEXPAND, 5 );
	
	m_panel12->SetSizer( bSizer13 );
	m_panel12->Layout();
	bSizer13->Fit( m_panel12 );
	c_Notebook->AddPage( m_panel12, _("Saving"), true );
	m_panel6 = new wxPanel( c_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer51;
	sbSizer51 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, _("Boundaries") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer4->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText111 = new wxStaticText( m_panel6, wxID_ANY, _("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	fgSizer4->Add( m_staticText111, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText112 = new wxStaticText( m_panel6, wxID_ANY, _("Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112->Wrap( -1 );
	fgSizer4->Add( m_staticText112, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	c_ColorContourBorderDraw = new wxCheckBox( m_panel6, wxID_ANY, _("Draw borders"), wxDefaultPosition, wxDefaultSize, 0 );
	c_ColorContourBorderDraw->SetValue(true);
	
	fgSizer4->Add( c_ColorContourBorderDraw, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_ColorContourBorderColor = new wxColourPickerCtrl( m_panel6, wxID_ANY, wxColour( 0, 0, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL );
	fgSizer4->Add( c_ColorContourBorderColor, 0, wxALL, 5 );
	
	c_ColorContourBorderWidth = new wxSpinCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 10, 3 );
	fgSizer4->Add( c_ColorContourBorderWidth, 0, wxALL, 5 );
	
	m_staticText22 = new wxStaticText( m_panel6, wxID_ANY, _("    Selected borders"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer4->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_ColorContourSelectedColor = new wxColourPickerCtrl( m_panel6, wxID_ANY, wxColour( 255, 255, 128 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL );
	fgSizer4->Add( c_ColorContourSelectedColor, 0, wxALL, 5 );
	
	
	fgSizer4->Add( 0, 0, 1, wxEXPAND, 5 );
	
	c_ColorContourCornerDraw = new wxCheckBox( m_panel6, wxID_ANY, _("Show corner points"), wxDefaultPosition, wxDefaultSize, 0 );
	c_ColorContourCornerDraw->SetValue(true);
	
	fgSizer4->Add( c_ColorContourCornerDraw, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_ColorContourCornerColor = new wxColourPickerCtrl( m_panel6, wxID_ANY, wxColour( 0, 128, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL );
	fgSizer4->Add( c_ColorContourCornerColor, 0, wxALL, 5 );
	
	c_ColorContourCornerWidth = new wxSpinCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 10, 3 );
	fgSizer4->Add( c_ColorContourCornerWidth, 0, wxALL, 5 );
	
	c_ColorContourPolygonFill = new wxCheckBox( m_panel6, wxID_ANY, _("Fill inside cells"), wxDefaultPosition, wxDefaultSize, 0 );
	
	fgSizer4->Add( c_ColorContourPolygonFill, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_ColorContourPolygonColor = new wxColourPickerCtrl( m_panel6, wxID_ANY, wxColour( 255, 255, 128 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL );
	fgSizer4->Add( c_ColorContourPolygonColor, 0, wxALL, 5 );
	
	
	fgSizer4->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText92 = new wxStaticText( m_panel6, wxID_ANY, _("     Intracellular points"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	fgSizer4->Add( m_staticText92, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	c_ColorFeatureColor = new wxColourPickerCtrl( m_panel6, wxID_ANY, wxColour( 209, 253, 130 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL );
	fgSizer4->Add( c_ColorFeatureColor, 0, wxALL, 5 );
	
	sbSizer51->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	bSizer16->Add( sbSizer51, 0, wxEXPAND, 5 );
	
	m_panel6->SetSizer( bSizer16 );
	m_panel6->Layout();
	bSizer16->Fit( m_panel6 );
	c_Notebook->AddPage( m_panel6, _("Colors"), false );
	
	bSizer12->Add( c_Notebook, 1, wxEXPAND | wxALL, 5 );
	
	m_panel7 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer151->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button5 = new wxButton( m_panel7, wxID_ANY, _("Restore &Defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer151->Add( m_button5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	m_button51 = new wxButton( m_panel7, wxID_ANY, _("&Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer151->Add( m_button51, 0, wxALL, 1 );
	
	m_button6 = new wxButton( m_panel7, wxID_ANY, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer151->Add( m_button6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	m_panel7->SetSizer( bSizer151 );
	m_panel7->Layout();
	bSizer151->Fit( m_panel7 );
	bSizer12->Add( m_panel7, 0, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer12 );
	this->Layout();
	
	// Connect Events
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog_::OnRestoreDefaults ), NULL, this );
	m_button51->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog_::OnSave ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog_::OnCancel ), NULL, this );
}

PreferencesDialog_::~PreferencesDialog_()
{
	// Disconnect Events
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog_::OnRestoreDefaults ), NULL, this );
	m_button51->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog_::OnSave ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog_::OnCancel ), NULL, this );
}

LoadImagesDialog_::LoadImagesDialog_( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer57->Add( 0, 10, 0, wxEXPAND, 5 );
	
	m_staticText99 = new wxStaticText( this, wxID_ANY, _("What type of files would you like to load?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99->Wrap( -1 );
	bSizer57->Add( m_staticText99, 0, wxALL, 5 );
	
	wxString filetypeChoices[] = { _("A single movie file (*.avi)"), _("A collection of image files") };
	int filetypeNChoices = sizeof( filetypeChoices ) / sizeof( wxString );
	filetype = new wxRadioBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, filetypeNChoices, filetypeChoices, 1, wxRA_SPECIFY_COLS );
	filetype->SetSelection( 0 );
	bSizer57->Add( filetype, 0, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	bSizer57->Add( m_sdbSizer1, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer57 );
	this->Layout();
}

LoadImagesDialog_::~LoadImagesDialog_()
{
}

ShowImageDialog::ShowImageDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	canvas = new PictureCanvas( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer61->Add( canvas, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer61 );
	this->Layout();
}

ShowImageDialog::~ShowImageDialog()
{
}

PlotDialog::PlotDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	plot = new mpWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	plot->SetScrollRate( 5, 5 );
	bSizer61->Add( plot, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer61 );
	this->Layout();
}

PlotDialog::~PlotDialog()
{
}

TemporaryPanel::TemporaryPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	from = new wxTextCtrl( this, wxID_ANY, _("colormap/"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( from, 0, wxALL, 5 );
	
	img1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../../gui/images/png/delete.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( img1, 0, wxALL, 5 );
	
	bSizer10->Add( bSizer12, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	to = new wxTextCtrl( this, wxID_ANY, _("colormap/"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer121->Add( to, 0, wxALL, 5 );
	
	img2 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer121->Add( img2, 0, wxALL, 5 );
	
	bSizer10->Add( bSizer121, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1211;
	bSizer1211 = new wxBoxSizer( wxHORIZONTAL );
	
	direction = new wxSpinCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1, 0 );
	bSizer1211->Add( direction, 0, wxALL, 5 );
	
	btn = new wxButton( this, wxID_ANY, _("convert"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1211->Add( btn, 0, wxALL, 5 );
	
	bSizer10->Add( bSizer1211, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	// Connect Events
	btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TemporaryPanel::OnTemp ), NULL, this );
}

TemporaryPanel::~TemporaryPanel()
{
	// Disconnect Events
	btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TemporaryPanel::OnTemp ), NULL, this );
}
