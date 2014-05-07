#pragma once
#include "PluginBase.h"
#include "SubtractBackgroundSidebar.h"
#include "ImagePlus.h"
#include "Util.h"
#include "wxTextCtrl_double.h"
#include <cv.h>
#include <cvaux.h>
#include <highgui.h>
#include <wx/choicebk.h>

class SubtractBackgroundSidebar;

class SubtractBackgroundPlugin :
	public PluginBase
{
private:
	SubtractBackgroundSidebar *sidebar;
	IplImage *avgImg, *temp, *temp32; //temporary images.
	CvBGStatModel* gaussModel;
public:
	~SubtractBackgroundPlugin(){ ReleaseTemps(); }
	SubtractBackgroundPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "SubtractBackground"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();

	void ProcessImage( ImagePlus *img, int pos );
	void InitModels(bool reinit=false);
};
