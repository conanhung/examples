#pragma once
#include "PluginBase.h"
#include "FindContoursSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class FindContoursSidebar;

class FindContoursPlugin :
	public PluginBase
{
private:
	IplImage *gray, *edge; //temporary images.
	FindContoursSidebar *sidebar;
public:
	~FindContoursPlugin(){ ReleaseTemps(); }
	FindContoursPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "FindContours"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();

	void ProcessImage( ImagePlus *img );
	static void ProcessImage_static( ImagePlus *img, IplImage* &gray, IplImage* &edge,
		double thresh1=150, double thresh2=50, int aperture=3,
		int dilate=1, int erode=0, bool clean=true, bool all=false, bool approx=true);
};
