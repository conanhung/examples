#pragma once
#include "PluginBase.h"
#include "CamShiftSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class CamShiftSidebar;

class CamShiftPlugin :
	public PluginBase
{
private:
	CamShiftSidebar *sidebar;
	IplImage *backproject, **planes;
	CvHistogram *hist;
	CvTermCriteria criteria;
	int hsizes[3];
	CvMat* rotation, *shift;
	bool useFirst;
public:
	~CamShiftPlugin(){ ReleaseTemps(); }
	CamShiftPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "CamShift"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();
	virtual void OnOK();
	void FetchParams();

	void ProcessImage( ImagePlus *img, int pos );
	static void ProcessStatic
( int i, ImagePlus *img, ImagePlus *oimg, int *hsizes, CvTermCriteria criteria,
IplImage** &planes, CvHistogram* &hist, IplImage* &backproject, CvRect &orect, CvPoint &ocenter, CvRect &searchwin, CvMat* &rotation, CvMat* &shift, bool oready);
};
