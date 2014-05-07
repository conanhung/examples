///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 17 2007)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __Gui__
#define __Gui__

class MyCanvas;
class PictureCanvas;
class mpWindow;
class wxTextCtrl_double;

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/slider.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/choicebk.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/scrolwin.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/listbox.h>
#include <wx/radiobut.h>
#include <wx/clrpicker.h>
#include <wx/notebook.h>
#include <wx/dialog.h>
#include <wx/statbmp.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame_
///////////////////////////////////////////////////////////////////////////////
class MyFrame_ : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			ID_OPEN_MOVIE = 1000,
		};
		
		wxMenuBar* m_menubar1;
		wxMenu* menu_file;
		wxMenu* menu_go;
		wxMenu* menu_image;
		wxMenu* menu_contours;
		wxMenu* menu_track;
		wxMenu* menu_analyze;
		wxMenu* m_menu4;
		wxMenu* m_menu5;
		wxMenu* m_menu41;
		wxMenu* m_menu2;
		wxMenu* m_menu1;
		wxMenu* menu_help;
		wxStatusBar* sbar;
		wxSplitterWindow* splitterBottombar;
		wxPanel* m_panel4;
		wxSplitterWindow* splitterSidebar;
		wxPanel* m_panel11;
		wxPanel* m_panel23;
		wxSplitterWindow* splitterCanvas;
		MyCanvas* canvas2;
		MyCanvas* canvas;
		wxPanel* m_panel12;
		wxBitmapButton* m_delete;
		wxBitmapButton* m_stop;
		wxBitmapButton* m_play;
		wxBitmapButton* m_prev;
		wxBitmapButton* m_next;
		wxSlider* m_slider;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnKeyDown( wxKeyEvent& event ){ event.Skip(); }
		virtual void OnOpenMovie( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOpenImages( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSaveMovieAs( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSaveFrameAs( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnImportTrackData( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPreferences( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnNext( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPrev( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnFirst( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnLast( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTogglePlay( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnResizeMovie( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCrop( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSmooth( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDelete( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDeleteBefore( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDeleteAfter( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnFindContours( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnFilterContours( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnEditContours( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnImproveContours( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnNormalizeContours( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnFindFeatures( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSubtractBackground( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMatchTemplate( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCamShift( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnLKContours( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTrackContours( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCombinedTracking( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPlotSpeed( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExportSpeedData( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPlotArea( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPlotAreaDiff( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExportAreaData( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPlotDeformation( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExportDeformationData( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnViewTrackImage( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExportTrackImage( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExportTrackData( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnViewTrajectoryImage( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExportTrajectoryImage( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExportTrajectoryData( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnStop( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPlay( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnScroll( wxScrollEvent& event ){ event.Skip(); }
		
	
	public:
		MyFrame_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("CellTrack v1.1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 426,355 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MyFrame_();
		void splitterBottombarOnIdle( wxIdleEvent& )
		{
		splitterBottombar->SetSashPosition( 244 );
		splitterBottombar->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MyFrame_::splitterBottombarOnIdle ), NULL, this );
		}
		
		void splitterSidebarOnIdle( wxIdleEvent& )
		{
		splitterSidebar->SetSashPosition( 6 );
		splitterSidebar->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MyFrame_::splitterSidebarOnIdle ), NULL, this );
		}
		
		void splitterCanvasOnIdle( wxIdleEvent& )
		{
		splitterCanvas->SetSashPosition( 203 );
		splitterCanvas->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MyFrame_::splitterCanvasOnIdle ), NULL, this );
		}
		
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SmoothSidebar_
///////////////////////////////////////////////////////////////////////////////
class SmoothSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxChoicebook* method;
		wxPanel* m_panel8;
		wxStaticText* m_staticText243;
		wxStaticText* m_staticText2421;
		wxPanel* m_panel9;
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText242;
		wxStaticText* m_staticText2411;
		wxTextCtrl_double* gauss3;
		wxStaticText* m_staticText24111;
		wxTextCtrl_double* gauss4;
		wxPanel* m_panel81;
		wxStaticText* m_staticText2431;
		wxPanel* m_panel811;
		wxStaticText* m_staticText24311;
		wxStaticText* m_staticText243111;
		wxStaticLine* m_staticline3;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxChoicebookEvent& event ){ event.Skip(); }
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxSpinCtrl* blur1;
		wxSpinCtrl* blur2;
		wxSpinCtrl* gauss1;
		wxSpinCtrl* gauss2;
		wxSpinCtrl* median1;
		wxSpinCtrl* bilateral1;
		wxSpinCtrl* bilateral2;
		wxRadioBox* scope;
		wxCheckBox* preview;
		SmoothSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 228,350 ), long style = wxTAB_TRAVERSAL );
		~SmoothSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FindContoursSidebar_
///////////////////////////////////////////////////////////////////////////////
class FindContoursSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText7;
		wxSpinCtrl* thresh2;
		wxStaticText* m_staticText6;
		wxSpinCtrl* thresh1;
		wxStaticText* m_staticText61;
		wxChoice* aperture;
		wxStaticText* m_staticText71;
		wxSpinCtrl* dilate;
		wxStaticText* m_staticText711;
		wxSpinCtrl* erode;
		wxCheckBox* approx;
		wxRadioBox* intra;
		wxCheckBox* clean;
		wxCheckBox* preview;
		wxStaticLine* m_staticline1;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		FindContoursSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 195,448 ), long style = wxTAB_TRAVERSAL );
		~FindContoursSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CropSidebar_
///////////////////////////////////////////////////////////////////////////////
class CropSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText106;
		wxStaticText* m_staticText712;
		wxSpinCtrl* fromx;
		wxSpinCtrl* fromy;
		wxStaticText* m_staticText621;
		wxSpinCtrl* width;
		wxSpinCtrl* height;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		CropSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 195,151 ), long style = wxTAB_TRAVERSAL );
		~CropSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ResizeMovieSidebar_
///////////////////////////////////////////////////////////////////////////////
class ResizeMovieSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText7;
		wxSpinCtrl* width;
		wxStaticText* m_staticText6;
		wxSpinCtrl* height;
		wxCheckBox* constrain;
		wxRadioBox* interpolation;
		wxStaticLine* m_staticline1;
		wxButton* m_button122;
		wxButton* m_button131;
		wxButton* m_button121;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChangeWidth( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChangeHeight( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnConstrain( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnReset( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		ResizeMovieSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 195,295 ), long style = wxTAB_TRAVERSAL );
		~ResizeMovieSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class NormalizeContoursSidebar_
///////////////////////////////////////////////////////////////////////////////
class NormalizeContoursSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxCheckBox* isMinLength;
		wxSpinCtrl* minLength;
		wxCheckBox* isMaxLength;
		wxSpinCtrl* maxLength;
		wxCheckBox* preview;
		wxButton* m_button122;
		wxButton* m_button1313;
		wxButton* m_button1211;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		NormalizeContoursSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 195,250 ), long style = wxTAB_TRAVERSAL );
		~NormalizeContoursSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FilterContoursSidebar_
///////////////////////////////////////////////////////////////////////////////
class FilterContoursSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticLine* m_staticline3;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxCheckBox* isMinArea;
		wxSpinCtrl* minArea;
		wxCheckBox* isMaxArea;
		wxSpinCtrl* maxArea;
		wxCheckBox* isMinDist;
		wxSpinCtrl* minDist;
		wxRadioBox* scope;
		wxCheckBox* preview;
		FilterContoursSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 200,345 ), long style = wxTAB_TRAVERSAL );
		~FilterContoursSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class EditContoursSidebar_
///////////////////////////////////////////////////////////////////////////////
class EditContoursSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxButton* m_button14;
		wxButton* m_button142;
		wxButton* m_button141;
		wxButton* m_button131;
		wxButton* m_button1312;
		wxButton* m_button1311;
		wxRadioBox* useMouseTo;
		wxButton* m_button122;
		wxButton* m_button1313;
		wxButton* m_button1211;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectAll( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDeselectAll( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInvertSelection( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDeleteSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDeleteAll( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCleanAllFrames( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnUseMouseTo( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxListBox* listbox;
		EditContoursSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 196,350 ), long style = wxTAB_TRAVERSAL );
		~EditContoursSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ManualContoursBottombar_
///////////////////////////////////////////////////////////////////////////////
class ManualContoursBottombar_ : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText8;
		
		wxButton* m_button6;
	
	public:
		ManualContoursBottombar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 358,32 ), long style = wxTAB_TRAVERSAL );
		~ManualContoursBottombar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FindFeaturesSidebar_
///////////////////////////////////////////////////////////////////////////////
class FindFeaturesSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText7;
		wxTextCtrl_double* quality;
		wxStaticText* m_staticText6;
		wxTextCtrl_double* minDist;
		wxStaticText* m_staticText61;
		wxTextCtrl_double* harrisK;
		wxStaticText* m_staticText611;
		wxSpinCtrl* blockSize;
		wxStaticText* m_staticText6111;
		wxSpinCtrl* maxCount;
		wxCheckBox* clean;
		wxCheckBox* preview;
		wxStaticLine* m_staticline1;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* method;
		wxRadioBox* scope;
		FindFeaturesSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 190,446 ), long style = wxTAB_TRAVERSAL );
		~FindFeaturesSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SubtractBackgroundSidebar_
///////////////////////////////////////////////////////////////////////////////
class SubtractBackgroundSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxChoicebook* method;
		wxPanel* m_panel8;
		wxStaticText* m_staticText22;
		wxStaticText* m_staticText23;
		wxPanel* m_panel9;
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText242;
		wxStaticText* m_staticText241;
		wxStaticText* m_staticText2411;
		wxTextCtrl_double* bg_threshold;
		wxStaticText* m_staticText24111;
		wxTextCtrl_double* std_threshold;
		wxStaticText* m_staticText2412;
		wxStaticText* m_staticText24121;
		wxTextCtrl_double* weight_init;
		wxStaticText* m_staticText24122;
		wxStaticLine* m_staticline3;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxChoicebookEvent& event ){ event.Skip(); }
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxSpinCtrl* numFrames;
		wxSpinCtrl* win_size;
		wxSpinCtrl* n_gauss;
		wxSpinCtrl* minArea;
		wxSpinCtrl* variance_init;
		wxCheckBox* preview;
		SubtractBackgroundSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 210,411 ), long style = wxTAB_TRAVERSAL );
		~SubtractBackgroundSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ImproveContoursSidebar_
///////////////////////////////////////////////////////////////////////////////
class ImproveContoursSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText7;
		wxSpinCtrl* alpha;
		wxStaticText* m_staticText6;
		wxSpinCtrl* beta;
		wxStaticText* m_staticText61;
		wxSpinCtrl* gamma;
		wxCheckBox* gradient;
		wxStaticText* m_staticText71;
		wxSpinCtrl* width;
		wxStaticText* m_staticText62;
		wxSpinCtrl* height;
		wxStaticText* m_staticText72;
		wxSpinCtrl* max_iter;
		wxStaticText* m_staticText73;
		wxTextCtrl_double* epsilon;
		wxCheckBox* preview;
		wxStaticLine* m_staticline2;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		ImproveContoursSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 210,432 ), long style = wxTAB_TRAVERSAL );
		~ImproveContoursSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MatchTemplateSidebar_
///////////////////////////////////////////////////////////////////////////////
class MatchTemplateSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText78;
		wxChoice* method;
		wxCheckBox* useFirst;
		wxStaticText* m_staticText71;
		wxSpinCtrl* width;
		wxStaticText* m_staticText62;
		wxSpinCtrl* height;
		wxCheckBox* preview;
		wxStaticLine* m_staticline17;
		wxButton* m_button12;
		wxButton* m_button13;
		wxButton* m_button121;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		MatchTemplateSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 225,290 ), long style = wxTAB_TRAVERSAL );
		~MatchTemplateSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CamShiftSidebar_
///////////////////////////////////////////////////////////////////////////////
class CamShiftSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText7;
		wxSpinCtrl* hsize;
		wxCheckBox* useFirst;
		wxStaticText* m_staticText72;
		wxSpinCtrl* max_iter;
		wxStaticText* m_staticText73;
		wxTextCtrl_double* epsilon;
		wxCheckBox* preview;
		wxStaticLine* m_staticline17;
		wxButton* m_button12;
		wxButton* m_button13;
		wxButton* m_button121;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		CamShiftSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 195,300 ), long style = wxTAB_TRAVERSAL );
		~CamShiftSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LKContoursSidebar_
///////////////////////////////////////////////////////////////////////////////
class LKContoursSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText7;
		wxSpinCtrl* level;
		wxCheckBox* useAvailable;
		wxCheckBox* fixOutliers;
		wxStaticText* m_staticText74;
		wxTextCtrl_double* outliers;
		wxStaticText* m_staticText741;
		wxSpinCtrl* intwin;
		wxStaticText* m_staticText71;
		wxSpinCtrl* width;
		wxStaticText* m_staticText62;
		wxSpinCtrl* height;
		wxStaticText* m_staticText72;
		wxSpinCtrl* max_iter;
		wxStaticText* m_staticText73;
		wxTextCtrl_double* epsilon;
		wxCheckBox* preview;
		wxStaticLine* m_staticline17;
		wxButton* m_button12;
		wxButton* m_button13;
		wxButton* m_button121;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		LKContoursSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 214,468 ), long style = wxTAB_TRAVERSAL );
		~LKContoursSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TrackContoursSidebar_
///////////////////////////////////////////////////////////////////////////////
class TrackContoursSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		
		wxStaticText* m_staticText721;
		wxStaticText* m_staticText7211;
		wxStaticText* m_staticText7;
		wxSpinCtrl* oalpha;
		wxSpinCtrl* alpha;
		wxStaticText* m_staticText6;
		wxSpinCtrl* obeta;
		wxSpinCtrl* beta;
		wxStaticText* m_staticText61;
		wxSpinCtrl* ogamma;
		wxSpinCtrl* gamma;
		wxStaticText* m_staticText612;
		wxSpinCtrl* oomega;
		
		wxStaticText* m_staticText6111;
		wxSpinCtrl* ozeta;
		
		wxStaticText* m_staticText611;
		wxSpinCtrl* oteta;
		wxCheckBox* gradient;
		wxCheckBox* useAvailable;
		wxStaticText* m_staticText71;
		wxSpinCtrl* width;
		wxStaticText* m_staticText62;
		wxSpinCtrl* height;
		wxStaticText* m_staticText72;
		wxSpinCtrl* max_iter;
		wxStaticText* m_staticText73;
		wxTextCtrl_double* epsilon;
		wxCheckBox* preview;
		wxStaticLine* m_staticline2;
		wxButton* m_button12;
		wxButton* m_button13;
		wxButton* m_button121;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		TrackContoursSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 236,527 ), long style = wxTAB_TRAVERSAL );
		~TrackContoursSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CombinedTrackingSidebar_
///////////////////////////////////////////////////////////////////////////////
class CombinedTrackingSidebar_ : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow3;
		wxChoicebook* m_choicebook3;
		wxPanel* m_panel22;
		wxRadioBox* initial_method;
		wxCheckBox* useLK;
		wxCheckBox* useAS;
		wxCheckBox* useNC;
		wxPanel* m_panel23;
		wxStaticText* m_staticText78;
		wxChoice* mt_method;
		wxCheckBox* mt_useFirst;
		wxStaticText* m_staticText71;
		wxSpinCtrl* mt_width;
		wxStaticText* m_staticText62;
		wxSpinCtrl* mt_height;
		wxPanel* m_panel24;
		wxStaticText* m_staticText7;
		wxSpinCtrl* cs_hsize;
		wxCheckBox* cs_useFirst;
		wxStaticText* m_staticText72;
		wxSpinCtrl* cs_max_iter;
		wxStaticText* m_staticText73;
		wxTextCtrl_double* cs_epsilon;
		wxPanel* m_panel25;
		wxStaticText* m_staticText75;
		wxSpinCtrl* lk_level;
		wxCheckBox* lk_useAvailable;
		wxCheckBox* lk_fixOutliers;
		wxStaticText* m_staticText74;
		wxTextCtrl_double* lk_outliers;
		wxStaticText* m_staticText741;
		wxSpinCtrl* lk_intwin;
		wxStaticText* m_staticText711;
		wxSpinCtrl* lk_width;
		wxStaticText* m_staticText621;
		wxSpinCtrl* lk_height;
		wxStaticText* m_staticText721;
		wxSpinCtrl* lk_max_iter;
		wxStaticText* m_staticText731;
		wxTextCtrl_double* lk_epsilon;
		wxPanel* m_panel26;
		
		wxStaticText* m_staticText7212;
		wxStaticText* m_staticText7211;
		wxStaticText* m_staticText76;
		wxSpinCtrl* as_oalpha;
		wxSpinCtrl* as_alpha;
		wxStaticText* m_staticText6;
		wxSpinCtrl* as_obeta;
		wxSpinCtrl* as_beta;
		wxStaticText* m_staticText61;
		wxSpinCtrl* as_ogamma;
		wxSpinCtrl* as_gamma;
		wxStaticText* m_staticText612;
		wxSpinCtrl* as_oomega;
		
		wxStaticText* m_staticText6111;
		wxSpinCtrl* as_ozeta;
		
		wxStaticText* m_staticText611;
		wxSpinCtrl* as_oteta;
		wxCheckBox* as_gradient;
		wxCheckBox* as_useAvailable;
		wxStaticText* m_staticText712;
		wxSpinCtrl* as_width;
		wxStaticText* m_staticText622;
		wxSpinCtrl* as_height;
		wxStaticText* m_staticText722;
		wxSpinCtrl* as_max_iter;
		wxStaticText* m_staticText732;
		wxTextCtrl_double* as_epsilon;
		wxPanel* m_panel21;
		wxCheckBox* nc_isMinLength;
		wxSpinCtrl* nc_minLength;
		wxCheckBox* nc_isMaxLength;
		wxSpinCtrl* nc_maxLength;
		wxCheckBox* preview;
		wxStaticLine* m_staticline1;
		wxButton* m_button122;
		wxButton* m_button131;
		wxButton* m_button121;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChange( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnChangePreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxRadioBox* scope;
		CombinedTrackingSidebar_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 239,573 ), long style = wxTAB_TRAVERSAL );
		~CombinedTrackingSidebar_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PreferencesDialog_
///////////////////////////////////////////////////////////////////////////////
class PreferencesDialog_ : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* c_Notebook;
		wxPanel* m_panel12;
		wxRadioButton* c_SavingCodecUseCombo;
		wxChoice* c_SavingCodecCombo;
		wxRadioButton* c_SavingCodecUseFOURCC;
		wxTextCtrl* c_SavingCodecFOURCC;
		wxCheckBox* c_SavingSizeOverride;
		wxStaticText* m_staticText14;
		wxTextCtrl* c_SavingSizeWidth;
		wxStaticText* m_staticText141;
		wxTextCtrl* c_SavingSizeHeight;
		wxStaticText* m_staticText142;
		wxSpinCtrl* c_SavingFpsDefault;
		wxCheckBox* c_SavingFpsOverride;
		wxPanel* m_panel6;
		
		wxStaticText* m_staticText111;
		wxStaticText* m_staticText112;
		wxCheckBox* c_ColorContourBorderDraw;
		wxColourPickerCtrl* c_ColorContourBorderColor;
		wxSpinCtrl* c_ColorContourBorderWidth;
		wxStaticText* m_staticText22;
		wxColourPickerCtrl* c_ColorContourSelectedColor;
		
		wxCheckBox* c_ColorContourCornerDraw;
		wxColourPickerCtrl* c_ColorContourCornerColor;
		wxSpinCtrl* c_ColorContourCornerWidth;
		wxCheckBox* c_ColorContourPolygonFill;
		wxColourPickerCtrl* c_ColorContourPolygonColor;
		
		wxStaticText* m_staticText92;
		wxColourPickerCtrl* c_ColorFeatureColor;
		wxPanel* m_panel7;
		
		wxButton* m_button5;
		wxButton* m_button51;
		wxButton* m_button6;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRestoreDefaults( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		PreferencesDialog_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("CellTrack Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 363,353 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PreferencesDialog_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LoadImagesDialog_
///////////////////////////////////////////////////////////////////////////////
class LoadImagesDialog_ : public wxDialog 
{
	private:
	
	protected:
		
		wxStaticText* m_staticText99;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
	
	public:
		wxRadioBox* filetype;
		LoadImagesDialog_( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("CellTrack::Load movie"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 275,160 ), long style = wxDEFAULT_DIALOG_STYLE );
		~LoadImagesDialog_();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ShowImageDialog
///////////////////////////////////////////////////////////////////////////////
class ShowImageDialog : public wxDialog 
{
	private:
	
	protected:
	
	public:
		PictureCanvas* canvas;
		ShowImageDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Tracking image"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 348,279 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER );
		~ShowImageDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PlotDialog
///////////////////////////////////////////////////////////////////////////////
class PlotDialog : public wxDialog 
{
	private:
	
	protected:
	
	public:
		mpWindow* plot;
		PlotDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Plot"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 425,333 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER );
		~PlotDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TemporaryPanel
///////////////////////////////////////////////////////////////////////////////
class TemporaryPanel : public wxPanel 
{
	private:
	
	protected:
		wxTextCtrl* from;
		wxStaticBitmap* img1;
		wxTextCtrl* to;
		wxStaticBitmap* img2;
		wxSpinCtrl* direction;
		wxButton* btn;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTemp( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		TemporaryPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 376,159 ), long style = wxTAB_TRAVERSAL );
		~TemporaryPanel();
	
};

#endif //__Gui__
