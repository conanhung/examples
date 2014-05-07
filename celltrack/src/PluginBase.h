#pragma once
#include <wx/window.h>
#include <wx/image.h>
#include "ImagePlus.h"
#include "CaptureManager.h"
#include "MyCanvas.h"
#include "MyFrame.h"
#include "Util.h"
#include <string.h>
#include <wx/progdlg.h>

class ImagePlus;
class CaptureManager;
class MyCanvas;
class MyFrame;

class PluginBase
{
private:
	PluginBase(void) {}
protected:
	string name;
	wxWindow *parent;
	wxWindow *sidebarw;
	wxWindow *bottombarw;
	MyFrame *win;
	CaptureManager *cm;
	MyCanvas *canvas, *canvas2;
	bool hasPreview;
	bool doProcessImageOnOK;
	bool showsCanvas2;
	wxProgressDialog *progressDlg;

	void CreateProgressDlg(int maxFrames=-1);
	void DestroyProgressDlg();
	bool UpdateProgressDlg(int frame);
public:
	virtual ~PluginBase(void); //calls PluginBase::ReleaseTemps. must be overridden if want to delete additional temps.
	PluginBase( string name_, wxWindow* parent_, MyFrame *win_, bool hasPreview_=false, bool doProcessImageOnOK_=true, bool showsCanvas2_=false);
	virtual string GetName(){ return name; }
	static string GetStaticName() { return ""; }
	virtual wxWindow* GetSidebar(){ return sidebarw; }
	virtual wxWindow* GetBottombar(){ return bottombarw; }
	virtual void OnOK();
	virtual void OnCancel();
	virtual void OnApply() { OnOK(); }
	virtual bool IsPreviewOn(){ return false; }
	bool HasPreview(){ return hasPreview; }
	bool ShowsCanvas2(){ return showsCanvas2; }
	virtual int GetScope() { return -1; } //-1:None, 0:current-frame, 1:all-frames
	virtual void DoPreview(){}
	virtual void OnEndPreview(); //called when the preview option is switched from on to off.
	virtual void OnMouse( wxMouseEvent& event ){}
	virtual void OnRoi( ){} //fired by canvas when user finishes drawing a roi-poly
	virtual void OnSelectContour(int index ){} //fired by canvas when user (de)selects a contour
	virtual void OnDragContour(int index, CvSeq *seq){} //fired by canvas when user finishes dragging a contour
	virtual void OnDragVertex(int index, int vertex, const CvPoint &loc){}//fired by canvas when user finishes dragging a vertex
	virtual void OnRect(wxPoint topleft, wxPoint botright){}//fired by canvas
	virtual void OnRedraw(); //fired by capture-manager when frame is being sent to canvas for drawing.
	virtual void OnReload(){} //fired by capture-manager when a new frame is being loaded
	virtual void ShowProcessInfo(){} //override if you wish to give any info (e.g. on the statusbar)
	virtual void OnNavigate(); //fired by MyFrame after a navigation event. use this if not have Preview
	virtual void ProcessImage( ImagePlus *img ){} //where the actual plugin processing is done.
	virtual void ProcessImage( ImagePlus *img, int pos ){ ProcessImage(img); }
	virtual void OnBookChange(){ ReleaseTemps(); } //Triggered by CaptureManager when a frame deleted/new movie loaded.
	virtual void ReleaseTemps(){} //Release temporary images/structures/memory
};
