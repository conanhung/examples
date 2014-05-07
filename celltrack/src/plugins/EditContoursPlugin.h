#pragma once
#include "PluginBase.h"
#include "EditContoursSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>

class EditContoursSidebar;

class EditContoursPlugin :
	public PluginBase
{
private:
	EditContoursSidebar *sidebar;
	bool dirty;
public:
	EditContoursPlugin( wxWindow* parent_, MyFrame *win_ );
	~EditContoursPlugin(void);
	static string GetStaticName() { return "EditContours"; }
	virtual void OnNavigate();
	void OnUseMouseTo();
	virtual void DoPreview();
	void OnDeleteSelected();
	void OnCleanAllFrames();
	virtual void OnRoi();
	virtual void OnSelectContour(int index);
	virtual void OnDragContour(int index, CvSeq *seq);
	virtual void OnDragVertex(int index, int vertex, const CvPoint &loc);
	void OnNormalizeEdges();
	void OnDoReload();
	virtual void OnReload();
	virtual void OnOK();
	virtual void OnCancel();
};
