#include <wx/msw/winundef.h>
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifdef __BORLANDC__
    #pragma hdrstop
#endif
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
#if defined(__WXMSW__)
    #ifdef wxHAVE_RAW_BITMAP
    #include "wx/rawbmp.h"
    #endif
#endif

#if defined(__WXMAC__) || defined(__WXGTK__)
    #define wxHAVE_RAW_BITMAP
    #include "wx/rawbmp.h"
#endif

#include <wx/config.h>

class MyApp: public wxApp
{
public:
    bool OnInit();

    // we get all the exceptions occurring in any
    // event handler here
    virtual bool OnExceptionInMainLoop();

    // whenever an unhandled
    // exception is caught, this function is called
    virtual void OnUnhandledException();

    // this function is called in case of a
    // crash (e.g. dereferencing null pointer, division by 0, ...)
    virtual void OnFatalException();

#ifdef __WXDEBUG__
    // in debug mode, you can override this function to do something different
    // (e.g. log the assert to file) whenever an assertion fails
    virtual void OnAssert(const wxChar *file,
                          int line,
                          const wxChar *cond,
                          const wxChar *msg);
#endif // __WXDEBUG__

};
IMPLEMENT_APP(MyApp)

#include "myframe.h"
#include "Preferences.h"
bool MyApp::OnInit()
{
    // use standard command line handling:
//    if ( !wxApp::OnInit() )
        //return false;

	wxImage::AddHandler( new wxPNGHandler );
	wxImage::AddHandler( new wxJPEGHandler );
	wxImage::AddHandler( new wxGIFHandler );
#if wxUSE_HELP
//    wxHelpProvider::Set( new wxSimpleHelpProvider );
#endif // wxUSE_HELP

	// Set up the global config
	wxConfig *config = new wxConfig(wxT("CellTrack"));
	wxConfigBase::Set(config);

	wxString cwd;
	config->Read("CWD", &cwd);
	if (cwd.empty()) {
		char path[1024];
		_getcwd(path,1024);
		config->Write("CWD",wxString(path)+"/");
	}
	Preferences::InitializeOnDemand();

	wxInt32 width = (wxInt32) config->Read(wxT("Frame/width"), 400l);
	wxInt32 height = (wxInt32) config->Read(wxT("Frame/height"), 400l);
	wxInt32 x = (wxInt32) config->Read(wxT("Frame/x"), 50l);
	wxInt32 y = (wxInt32) config->Read(wxT("Frame/y"), 50l);
    // Create the main frame window
    MyFrame *frame = new MyFrame("CellTrack", wxPoint(x, y), wxSize(width, height), wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE);
    frame->myShow(argc<=1);
	if (argc > 1)
		frame->OpenMovie(argv[1]);
    return true;
}

bool MyApp::OnExceptionInMainLoop()
{
    try
    {
        throw;
    }
    catch ( int i )
    {
        wxLogWarning(_T("Caught an int %d in MyApp."), i);
    }
    catch ( ... )
    {
        throw;
    }

    return true;
}

class UnhandledException
{
};
void MyApp::OnUnhandledException()
{
    // this shows how we may let some exception propagate uncaught
    try
    {
        throw;
    }
    catch ( UnhandledException& )
    {
        throw;
    }
    catch ( ... )
    {
        wxMessageBox(_T("Unhandled exception caught, program will terminate."),
                     _T("wxExcept Sample"), wxOK | wxICON_ERROR);
    }
}

void MyApp::OnFatalException()
{
    wxMessageBox(_T("Program has crashed and will terminate."),
                 _T("wxExcept Sample"), wxOK | wxICON_ERROR);
}

#ifdef __WXDEBUG__

void MyApp::OnAssert(const wxChar *file,
                     int line,
                     const wxChar *cond,
                     const wxChar *msg)
{
    // we don't have anything special to do here
    wxApp::OnAssert(file, line, cond, msg);
}

#endif // __WXDEBUG__
