#pragma once
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/file.h>
#include <map>
#include <wx/dc.h>


class PictureCanvas : public wxPanel
{
public:
	PictureCanvas(void){}
	~PictureCanvas(void){ if(img) delete img; }
	PictureCanvas(wxWindow* parent_, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, 
				   const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name=wxT("PictureCanvas"));
	void SetImage(const wxBitmap &bmp_);

protected:
	wxImage *img;
	wxBitmap bmp, bmpBuffer;
	wxPoint topleft;
	wxRealPoint scale;

	void OnPaint( wxPaintEvent &event );
    void OnEraseBackGround(wxEraseEvent& event) {};
	void OnSize(wxSizeEvent& event);

	DECLARE_EVENT_TABLE()
	DECLARE_DYNAMIC_CLASS(PictureCanvas)
};
