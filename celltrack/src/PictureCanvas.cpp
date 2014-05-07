#include "PictureCanvas.h"
#include <wx/dcbuffer.h>
#include <wx/dcmemory.h>
#include <wx/msgdlg.h>
#include <wx/image.h>
#include "Util.h"
#include "MyPoint.h"

IMPLEMENT_DYNAMIC_CLASS(PictureCanvas,wxPanel)
BEGIN_EVENT_TABLE(PictureCanvas, wxPanel)
    EVT_PAINT(PictureCanvas::OnPaint)
	EVT_ERASE_BACKGROUND(PictureCanvas::OnEraseBackGround)
	EVT_SIZE(PictureCanvas::OnSize)
END_EVENT_TABLE()
PictureCanvas::PictureCanvas(wxWindow* parent_, wxWindowID id, const wxPoint& pos, 
				   const wxSize& size, long style, const wxString& name):
wxPanel(parent_, id, pos, size, style, name), topleft(wxPoint(0,0)), scale(wxRealPoint(1.0,1.0)), img(NULL)
{
	bmp.Create(1,1);
	SetBackgroundColour(*wxBLACK);
	SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}
void PictureCanvas::OnPaint( wxPaintEvent &event )
{
    wxBufferedPaintDC dc( this, bmpBuffer );
    PrepareDC( dc );
	dc.SetBackground(wxBrush(GetBackgroundColour(), wxSOLID));
	dc.Clear();
	topleft = wxPoint((GetSize().GetWidth()-bmp.GetWidth())/2, (GetSize().GetHeight()-bmp.GetHeight())/2);
	dc.DrawBitmap(bmp, topleft);
}
void PictureCanvas::OnSize(wxSizeEvent& event)
{
	if(img){
		scale = GetImageScaling(img->GetWidth(), img->GetHeight(), GetSize().GetWidth(), GetSize().GetHeight());
		bmp = wxBitmap(img->Scale(img->GetWidth()*scale.x, img->GetHeight()*scale.y));
	}
	else
		bmp = wxBitmap(1,1);
	Refresh( true );
	Update();
}
void PictureCanvas::SetImage( const wxBitmap& bmp_ )
{
	if (img) delete img;
	img = new wxImage();
	*img = bmp_.ConvertToImage();
	OnSize(wxSizeEvent());
}


