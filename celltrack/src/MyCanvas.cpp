		#include "MyCanvas.h"
#include <wx/dcbuffer.h>
#include <wx/dcmemory.h>
#include <wx/msgdlg.h>
#include <wx/image.h>
#include "Preferences.h"
#include "MyPoint.h"
#include "Util.h"

IMPLEMENT_DYNAMIC_CLASS(MyCanvas,wxPanel)
BEGIN_EVENT_TABLE(MyCanvas, wxPanel)
    EVT_PAINT(MyCanvas::OnPaint)
	EVT_ERASE_BACKGROUND(MyCanvas::OnEraseBackGround)
	EVT_SIZE(MyCanvas::OnSize)
	EVT_MOUSE_EVENTS(MyCanvas::OnMouse)
END_EVENT_TABLE()
//TODO: remove EVT_MOUSE_EVENTS from static event table, and Connect to it on demand

MyCanvas::MyCanvas(void)
{
}

MyCanvas::~MyCanvas(void)
{
	if (selectedContours)
		delete[] selectedContours;
}

MyCanvas::MyCanvas(wxWindow* parent_, wxWindowID id, const wxPoint& pos, 
				   const wxSize& size, long style, const wxString& name):
wxPanel(parent_, id, pos, size, style, name), MouseListener(NULL), topleft(wxPoint(0,0)), scale(wxRealPoint(1.0,1.0)), doingRoi(false), RoiListener(NULL), lastRoiEndTime(wxDateTime::Now()), doingSelectContour(false), SelectContourListener(NULL), selectedContours(NULL), DragContourListener(false), DragVertexListener(NULL), doingDragContour(false), doingDragVertex(false), hoverContour(-1), dv(MyPoint(-1,-1)), draggedContour(-1), doingRect(false), RectListener(NULL)
{
	bmp.Create(1,1);
	SetBackgroundColour(*wxBLACK);
	SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}

//coordinate conversion macros, relative to original image pixels
#define FROM_IMG(X)	(MyPoint(X)*scale+topleft)
#define TO_IMG(X)	(MyPoint(X-topleft)/scale)
#define TO_BMP(X)	(MyPoint(X)*scale)
#define TO_CANVAS(X)	(MyPoint(X)*scale+topleft)
#define FROM_CANVAS(X)	(MyPoint(X-topleft)/scale)


void MyCanvas::OnPaint( wxPaintEvent &event )
{
    wxBufferedPaintDC dc( this, bmpBuffer );
    PrepareDC( dc );
	dc.SetBackground(wxBrush(GetBackgroundColour(), wxSOLID));
	dc.Clear();
	if (!drawn.Ok() || !img.orig)
		return;
	topleft = wxPoint((GetSize().GetWidth()-drawn.GetWidth())/2, (GetSize().GetHeight()-drawn.GetHeight())/2);
	dc.DrawBitmap(drawn, topleft);
}

void MyCanvas::OnSize(wxSizeEvent& event)
{
	if(!img.orig)
		return;
	wxSize newsize(0,0);
	if ( GetSize().GetWidth() * imgheight > GetSize().GetHeight() * imgwidth ){
		newsize.SetHeight(wxMax(GetSize().GetHeight(),1));
		newsize.SetWidth(newsize.GetHeight() * imgwidth / imgheight);
	}
	else if ( GetSize().GetWidth() * imgheight < GetSize().GetHeight() * imgwidth ){
		newsize.SetWidth(wxMax(GetSize().GetWidth(),1));
		newsize.SetHeight(newsize.GetWidth() * imgheight / imgwidth);
	}
	if (newsize.GetHeight() && newsize.GetWidth())
		scale = wxRealPoint(newsize.GetWidth()/(float)imgwidth, newsize.GetHeight()/(float)imgheight);
	else
		scale = wxRealPoint(1.0,1.0);
	unsigned char* imgdata = (unsigned char *) malloc(imgwidth*imgheight*3*sizeof(unsigned char));
	int step = img.orig->widthStep/sizeof(unsigned char);
	for (int h=0; h<imgheight; h++){
		//the color order is different BGR-->RGB, so memcpy won't give correct result.
//		memcpy(imgdata + h*imgwidth*3, img.orig->imageData + h*step, imgwidth*3*sizeof(unsigned char));
		for (int w=0; w<imgwidth; w++){
			for (int k=0; k<3; k++){
				imgdata[(h*imgwidth+w)*3 + (2-k)] = img.orig->imageData[h*step + w*3 + k];
			}
		}
	}
	bmp = wxBitmap(wxImage(imgwidth, imgheight, imgdata, false).Scale(imgwidth*scale.x, imgheight*scale.y));
	DrawContours();
	DrawRoi();
	Refresh( true );
	Update();
}
void MyCanvas::SetImage( const ImagePlus& img_ )
{
	img = img_;
	if (!img.orig){
		Refresh(true);
		Update();
		return;
	}
	roi.clear();
	theRect.x = -1;
	ResetSelectedContours();
	imgwidth = img.orig->width;
	imgheight = img.orig->height;
	OnSize(wxSizeEvent());
}
void MyCanvas::DrawContours()
{
	if (!img.contours)
		return;
	wxMemoryDC dc(bmp);
	CvSeq *seq = img.contours;
	int i=0;
	while (seq) {
		DrawContour(&dc, wxPoint(0,0), seq, selectedContours[i++], i);
		seq = seq->h_next;
	}
	for (int c=0; c<(int)img.feats.size(); c++){
		dc.SetPen(wxPen(wxColour(selectedContours[c] ? Preferences::GetColorContourSelectedColor() : Preferences::GetColorFeatureColor()), Preferences::GetColorContourBorderWidth()));
		for (int f=0; f<img.feats[c].size(); f++){
			MyPoint p = MyPoint(img.feats[c][f])*scale;
			dc.DrawLine(p.x-1, p.y, p.x+1, p.y);
			dc.DrawLine(p.x, p.y-1, p.x, p.y+1);
		}
	}
	if (theRect.x != -1)
		dc.DrawRectangle(TO_CANVAS(theRect.GetTopLeft()), MyPoint(MyPoint(theRect.GetSize())*scale).ToSize());
}
void MyCanvas::SetContourSelection( int index, bool selected )
{
	if (selectedContours[index] == selected)
		return;
	selectedContours[index] = selected;
	wxClientDC cdc(this);
	wxBufferedDC dc(&cdc);
	DrawContour(&dc, topleft, img.contourArray[index], selectedContours[index]);
}
void MyCanvas::DrawContour(wxDC *dc, wxPoint shift, CvSeq *seq, bool selected, int label){
	DrawContour_static(dc, seq, shift, scale, selected, 0, label);
}
void MyCanvas::DrawContour_static(wxDC *dc, CvSeq *seq, wxPoint shift, wxRealPoint scale, bool selected, const wxColor *borderColor, int label){
	wxPoint *ps = ContourToPointArray(seq, shift, scale);
		if (Preferences::GetColorContourBorderDraw() || selected){
			dc->SetPen(wxPen(borderColor ? *borderColor : wxColour(selected ? Preferences::GetColorContourSelectedColor() : Preferences::GetColorContourBorderColor()), Preferences::GetColorContourBorderWidth()));
			dc->SetBrush(*wxTRANSPARENT_BRUSH);
			dc->DrawPolygon(seq->total, ps);
		}

		if (Preferences::GetColorContourCornerDraw()){
			dc->SetPen(wxPen(wxColour(Preferences::GetColorContourCornerColor())));
			dc->SetBrush(*wxTRANSPARENT_BRUSH);
//			dc->SetBrush(wxBrush(wxColor(Preferences::GetColorContourCornerColor())));
			dc->DrawCircle(ps[0], Preferences::GetColorContourCornerWidth()/2);
			for (int i=1; i<seq->total; i++)
				dc->DrawRectangle(ps[i]-MyPoint(Preferences::GetColorContourCornerWidth())/2, MyPoint(Preferences::GetColorContourCornerWidth()).ToSize());
		}
		dc->SetTextForeground(Preferences::GetColorContourBorderColor());
		dc->DrawText(wxString::Format("%d", label), ps[0]);
		delete[] ps;
}
void MyCanvas::DrawRoi(bool lastPointOnly)
{
	if (!lastPointOnly)
		drawn = bmp;
	if (!doingRoi || !roi.size())
		return;
	int i,j;
	wxSize pointerSize(POINTER_SIZE, POINTER_SIZE);
	wxMemoryDC mdc(drawn);
	mdc.SetPen(wxPen(wxColour(Preferences::GetColorContourBorderColor()), Preferences::GetColorContourBorderWidth()));
	for (i=lastPointOnly ? (signed) roi.size()-1 : 1; i>0 && i<(signed)roi.size(); i++){
		j = i ? i-1 : (signed)roi.size()-1;
		mdc.DrawLine(TO_BMP(roi[i]), TO_BMP(roi[j]));
		mdc.DrawLine(TO_BMP(roi[j]), TO_BMP(roi[i]));
	}
	mdc.SetPen(wxPen(wxColour(Preferences::GetColorContourCornerColor())));
	mdc.SetBrush(wxBrush(wxColor(Preferences::GetColorContourCornerColor())));
	mdc.DrawCircle(TO_BMP(roi[0]), POINTER_SIZE/2);
	mdc.SetBrush(*wxTRANSPARENT_BRUSH);
	for (i=lastPointOnly ? (signed)roi.size()-1 : 0; i>0 && i<(signed)roi.size(); i++)
		mdc.DrawRectangle(TO_BMP(roi[i])-MyPoint(pointerSize)/2, pointerSize);
}

//TODO: can optimize the update process using SetClippingRegion ?
void MyCanvas::OnMouse( wxMouseEvent& e )
{
	wxPoint newPoint = FROM_CANVAS(wxPoint(e.m_x, e.m_y));
	if (doingRoi) {
		wxClientDC cdc(this);
		wxBufferedDC dc(&cdc);
		wxMemoryDC mdc(drawn);
		wxPoint lastPoint;
		dc.SetClippingRegion(wxPoint(0,0), wxSize(bmp.GetWidth(), bmp.GetHeight()));
		if (roi.size())
			lastPoint = roi.back();
		bool inrange = !e.Leaving() && MyPoint(newPoint) >= wxPoint(0,0) && MyPoint(newPoint) <= wxPoint(imgwidth, imgheight);
		wxSize pointerSize(POINTER_SIZE, POINTER_SIZE);

		// Check if we need to add a new point:
		if (inrange &&
			(e.LeftDown() ||
			(e.LeftDClick() && (wxDateTime::Now()-lastRoiEndTime).IsLongerThan(wxTimeSpan::Milliseconds(500))) )) {
				if (!roi.size() || MyPoint(lastPoint-newPoint).ToDist_Manhattan())
					roi.push_back(newPoint);
			DrawRoi(true);
			Update();
			if(roi.size()>1 && (e.LeftDClick() ||  MyPoint(roi[0]-roi.back()).ToDistSqr() <= 2)){
				if (e.LeftDown() && !e.LeftDClick())
					lastRoiEndTime = wxDateTime::Now();
				OnRoi();
			}
		}
		else {
			if (MyPoint(oldMousePos) >= wxPoint(0,0)) {
				// Restore previous drawings from the bmp:
				if (roi.size()) {
					MyPoint width = TO_BMP(oldMousePos - lastPoint);
					MyPoint width_sign(width.x>0 ? 1:-1, width.y>0 ? 1:-1);
					int penwidth = wxMax(dc.GetPen().GetWidth(),Preferences::GetColorContourBorderWidth())+1;
					width += width_sign * (2*penwidth+1);
					dc.Blit(TO_CANVAS(lastPoint) - width_sign*penwidth, width.ToSize(), &mdc, TO_BMP(lastPoint)- width_sign*penwidth);
				}
				dc.Blit(TO_CANVAS(oldMousePos)-MyPoint(pointerSize)/2, pointerSize, &mdc, TO_BMP(oldMousePos)-MyPoint(pointerSize)/2);
			}
			if (inrange) {
				if (roi.size()){
					dc.SetPen(wxPen(wxColour(Preferences::GetColorContourBorderColor()), Preferences::GetColorContourBorderWidth()));
					dc.DrawLine(TO_CANVAS(lastPoint), TO_CANVAS(newPoint));
					dc.DrawLine(TO_CANVAS(newPoint), TO_CANVAS(lastPoint));
	//				dc.DrawLine(TO_CANVAS(roi[0]), TO_CANVAS(newPoint));
	//				dc.DrawLine(TO_CANVAS(newPoint), TO_CANVAS(roi[0]));
				}
				dc.SetPen(wxPen(wxColour(Preferences::GetColorContourCornerColor()),1));
				if ( roi.size()<2 || MyPoint(roi[0]-newPoint).ToDistSqr() > 2)
					dc.SetBrush(*wxTRANSPARENT_BRUSH);
				dc.DrawRectangle(TO_CANVAS(newPoint)-MyPoint(pointerSize)/2, pointerSize);
				oldMousePos = newPoint;
			}
		}
	}
	if (doingSelectContour){
		wxClientDC cdc(this);
		wxBufferedDC dc(&cdc);
		int minSeq = -1;
		if (!e.Leaving())
			minSeq = GetContourHit(newPoint);		
		if (minSeq != hoverContour){
			if(hoverContour>=0)
				DrawContour(&dc, topleft, img.contourArray[hoverContour], selectedContours[hoverContour]);
			hoverContour = minSeq;
			if(hoverContour>=0){
				DrawContour(&dc, topleft, img.contourArray[hoverContour], !selectedContours[hoverContour]);
			}
		}
		if (hoverContour>=0 && e.LeftDown())
			OnSelectContour();
	}
	if (doingDragContour){
		if (e.LeftDown()){
			if((draggedContour = GetContourHit(newPoint))>=0){
				draggedContourOrig = cvBoundingRect(img.contourArray[draggedContour],1);
				draggedContourRect = draggedContourOrig;
				dragStart = newPoint;
				selectedContours[draggedContour] = selectedContours[draggedContour];
			}
		}
		if (draggedContour>=0 && (e.Dragging() || e.LeftUp() || e.Entering())){
			CvPoint shift = MyPoint(newPoint - dragStart).ToCvPoint();
			CvRect newRect;
			RestrictRectShift(shift, newRect, draggedContourRect, cvRect(0,0,imgwidth,imgheight));
			if (MyPoint(shift)!=0){
				ShiftContour(img.contourArray[draggedContour], shift);
				dragStart = newPoint;
				draggedContourRect = newRect;
				OnSize(wxSizeEvent());
			}
			if (!e.LeftIsDown()){
				selectedContours[draggedContour] = !selectedContours[draggedContour];
				OnDragContour();
			}
		}
	}
	if (doingRect) {
		bool inrange = !e.Leaving() && MyPoint(newPoint) >= wxPoint(0,0) && MyPoint(newPoint) <= wxPoint(imgwidth, imgheight);
		if (inrange){
			wxClientDC cdc(this);
			wxBufferedDC dc(&cdc);
			wxMemoryDC mdc(drawn);
			if (e.LeftDown()){
				if (theRect.x >=0)
					dc.Blit(TO_CANVAS(theRect.GetTopLeft()), MyPoint(MyPoint(theRect.GetSize())*scale).ToSize(), &mdc, TO_BMP(theRect.GetTopLeft()));
				theRect.SetTopLeft(newPoint);
				theRect.SetBottomRight(newPoint);
				drawingRect = true;
			}
			if (drawingRect && theRect.x>=0 && (e.Dragging() || e.LeftUp() || e.Entering())) {
				dc.Blit(TO_CANVAS(theRect.GetTopLeft()), MyPoint(MyPoint(theRect.GetSize())*scale).ToSize(), &mdc, TO_BMP(theRect.GetTopLeft()));
				theRect.SetBottomRight(newPoint);
				if (!e.LeftIsDown()){
					drawingRect = false;
					OnRect();
				}
				dc.SetPen(*wxRED_PEN);
				dc.SetBrush(*wxTRANSPARENT_BRUSH);
				dc.DrawRectangle(TO_CANVAS(theRect.GetTopLeft()), MyPoint(MyPoint(theRect.GetSize())*scale).ToSize());
			}
		}
	}
	if (doingDragVertex){
		if (e.LeftDown()){
			if(dv!=-1)
				dv=dv;
			if((dv = GetVertexHit(newPoint))!=-1){
				dvOrig = MyPoint(newPoint).ToCvPoint();
			}
		}
		else if (dv!=-1 && (e.Dragging() || e.LeftUp() || e.Entering())){
			if (MyPoint(0,0)<=newPoint && MyPoint(imgwidth,imgheight)>=newPoint){
				CvPoint *p = (CvPoint*) cvGetSeqElem(img.contourArray[dv.x], dv.y);
				p->x = newPoint.x;
				p->y = newPoint.y;
				OnSize(wxSizeEvent());
			}
			if (!e.LeftIsDown()){
				OnDragVertex();
			}
		}
	}
	if (MouseListener){
		e.m_x = newPoint.x;
		e.m_y = newPoint.y;
		MouseListener->OnMouse(e);
	}

	e.Skip();
}

int MyCanvas::GetContourHit( wxPoint p )
{
	int minSeq = -1, i=0;
	double minDist,d;
	CvSeq *seq = img.contours;
	while(seq) {
		d=cvPointPolygonTest(seq,cvPoint2D32f(p.x,p.y),1);
		if (d>=0 && (minSeq<0 || d<minDist)){
			minDist = d;
			minSeq = i;
		}
		seq = seq->h_next;
		i++;
	}
	return minSeq;
}

MyPoint MyCanvas::GetVertexHit(const MyPoint &p, int fuzz){
	int i=0;
	CvSeq *seq = img.contours;
	while(seq) {
		for (int j=0; j<seq->total; j++){
			CvPoint *pp = (CvPoint*) cvGetSeqElem(seq, j);
			if(MyPoint(MyPoint(pp) - p).ToDist_Manhattan()<=1)
				return MyPoint(i,j);
		}
		seq = seq->h_next;
		i++;
	}
	return MyPoint(-1,-1);
}


#define DEFINE_LISTENER(X)	\
	void MyCanvas::Set##X##Listener( PluginBase* p ) { \
	if (X##Listener && p) \
		wxLogError("canvas already had a %s listener.", #X); \
	X##Listener = p; \
}
DEFINE_LISTENER(Mouse)
DEFINE_LISTENER(Roi)
DEFINE_LISTENER(SelectContour)
DEFINE_LISTENER(DragContour)
DEFINE_LISTENER(DragVertex)
DEFINE_LISTENER(Rect)
//----------------------------------- DRAG ROI ------------------------
void MyCanvas::BeginRoi()
{
	CancelRoi();
	doingRoi = true;
	oldMousePos = wxPoint(-1,-1);
}
void MyCanvas::CancelRoi()
{
	doingRoi = false;
	if (roi.size()){
		roi.clear();
		DrawRoi();
		Refresh();
		Update();
	}
}
void MyCanvas::OnRoi()
{
	doingRoi = false;
	if (RoiListener)
		RoiListener->OnRoi();
}
//----------------------------------- DRAG CONTOUR ------------------------
void MyCanvas::BeginDragContour()
{
//	CancelDragContour();
	doingDragContour = true;
	draggedContour = -1;
	oldMousePos = wxPoint(-1,-1);
}
void MyCanvas::CancelDragContour()
{
	doingDragContour = false;
	if (draggedContour>=0){
		CvPoint shift = MyPoint(draggedContourOrig.x - draggedContourRect.x, draggedContourOrig.y-draggedContourRect.y).ToCvPoint();
		CvRect newRect;
		RestrictRectShift(shift, newRect, draggedContourRect, cvRect(0,0,imgwidth,imgheight));
		if (MyPoint(shift)!=0){
			ShiftContour(img.contourArray[draggedContour], shift);
			Refresh();
			Update();
		}
	}
}
void MyCanvas::OnDragContour()
{
	doingDragContour = false;
	if (DragContourListener)
		DragContourListener->OnDragContour(draggedContour, img.contourArray[draggedContour]);
}
//----------------------------------- DRAW RECT ------------------------
void MyCanvas::BeginRect()
{
	CancelRect();
	doingRect = true;
	theRect.x = -1;
}
void MyCanvas::CancelRect()
{
	doingRect = false;
	if (theRect.x>=0){
		wxClientDC cdc(this);
		wxBufferedDC dc(&cdc);
		wxMemoryDC mdc(drawn);
		dc.Blit(TO_CANVAS(theRect.GetTopLeft()), MyPoint(MyPoint(theRect.GetSize())*scale).ToSize(), &mdc, TO_BMP(theRect.GetTopLeft()));
	}
	theRect.x = -1;
}
void MyCanvas::OnRect()
{
	if (RectListener)
		RectListener->OnRect(wxPoint(0,0), wxPoint(0,0));
}
//----------------------------------- DRAG VERTEX ------------------------
void MyCanvas::BeginDragVertex()
{
//	CancelDragVertex();
	doingDragVertex = true;
	dv = MyPoint(-1,-1);
}
void MyCanvas::CancelDragVertex()
{
	doingDragVertex = false;
	if (dv != -1){
		CvPoint *p = (CvPoint*) cvGetSeqElem(img.contourArray[dv.x], dv.y);
		p->x = dvOrig.x;
		p->y = dvOrig.y;
		Refresh();
		Update();
	}
}
void MyCanvas::OnDragVertex()
{
	doingDragVertex = false;
	CvPoint *p = (CvPoint*) cvGetSeqElem(img.contourArray[dv.x], dv.y);
	if (DragVertexListener)
		DragVertexListener->OnDragVertex(dv.x, dv.y, *p);
}
//----------------------------------- SELECT CONTOUR ------------------------
void MyCanvas::BeginSelectContour()
{
	CancelSelectContour();
	doingSelectContour = true;
	hoverContour = -1;
}
void MyCanvas::CancelSelectContour()
{
	doingSelectContour = false;
	if (hoverContour>=0 && hoverContour<(signed) img.contourArray.size()){
		wxClientDC cdc(this);
		wxBufferedDC dc(&cdc);
		DrawContour(&dc, topleft, img.contourArray[hoverContour],selectedContours[hoverContour]);
		Refresh();
		Update();
	}
	hoverContour = -1;
}

void MyCanvas::OnSelectContour()
{
	selectedContours[hoverContour] = !selectedContours[hoverContour];
	if (SelectContourListener)
		SelectContourListener->OnSelectContour(hoverContour);
}
void MyCanvas::ResetSelectedContours()
{
	if(selectedContours)
		delete[] selectedContours;
	selectedContours = NULL;
	if (img.contourArray.size()){
		selectedContours = new bool[img.contourArray.size()];
		for (unsigned int i=0; i<img.contourArray.size(); i++)
			selectedContours[i] = false;
	}
	hoverContour = -1;
}

