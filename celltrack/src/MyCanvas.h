#pragma once
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include "PluginBase.h"
#include <vector>
#include "MyPoint.h"
#include "ImagePlus.h"
#include "Util.h"
#include <wx/datetime.h>

class PluginBase;

class MyCanvas : public wxPanel
{
public:
	MyCanvas(void);
	~MyCanvas(void);
	MyCanvas(wxWindow* parent_, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, 
				   const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name=wxT("MyCanvas"));
	void OnPaint( wxPaintEvent &event );
    void OnEraseBackGround(wxEraseEvent& event) {};
	void OnSize(wxSizeEvent& event);
	void OnMouse(wxMouseEvent& event);

public:
	enum {
		POINTER_SIZE = 7
	};

	ImagePlus img; //original img (comes from CaptureManager::img)
	wxBitmap bmp; //scaled img with contours and features drawn
	wxBitmap drawn; //can contain temporary user-drawn objects. refreshes from bmp.
	wxBitmap bmpBuffer; //used for double-buffering
	wxPoint topleft;
	wxRealPoint scale;
	int imgwidth;
	int imgheight;

#define DECLARE_LISTENER(X)	\
	PluginBase *X##Listener; \
	void Set##X##Listener(PluginBase *a); \
	void Begin##X(); \
	void Cancel##X(); \
	void On##X(); \
	bool doing##X;

	DECLARE_LISTENER(Roi)
	DECLARE_LISTENER(SelectContour)
	DECLARE_LISTENER(DragContour)
	DECLARE_LISTENER(DragVertex)
	DECLARE_LISTENER(Rect)

	PluginBase *MouseListener;
	void SetMouseListener(PluginBase *a);

	std::vector<wxPoint> roi;
	wxPoint oldMousePos;
	wxDateTime lastRoiEndTime;
	void DrawRoi(bool lastPointOnly=false);

	bool *selectedContours;
	int hoverContour;
	void ResetSelectedContours();

	int draggedContour;
	CvRect draggedContourRect;
	CvRect draggedContourOrig;
	wxPoint dragStart;

	wxRect theRect;
	bool drawingRect;

	int GetContourHit(wxPoint p); //returns the index of the innermost contour where p is located. -1 if not in any contours.

	MyPoint dv;
	CvPoint dvOrig;
	CvPoint dvStart;
	MyPoint GetVertexHit(const MyPoint &p,int fuzz=1); //return contour/vertex pair

private:
	DECLARE_EVENT_TABLE()
	DECLARE_DYNAMIC_CLASS(MyCanvas)
public:
	void SetImage(const ImagePlus& img_);
	void DrawContours();
	void DrawContour(wxDC *dc, wxPoint shift, CvSeq *seq, bool selected=false, int label=0);
	static void MyCanvas::DrawContour_static(wxDC *dc, CvSeq *seq, wxPoint shift=wxPoint(0,0), wxRealPoint scale=wxRealPoint(1,1), bool selected=false, const wxColor *borderColor=NULL, int label=0);
	void SetContourSelection(int index, bool selected);

};
