#pragma once
#include "PluginBase.h"
#include "NormalizeContoursSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class NormalizeContoursSidebar;

class NormalizeContoursPlugin :
	public PluginBase
{
private:
	IplImage *gray, *edge; //temporary images.
	NormalizeContoursSidebar *sidebar;
public:
	~NormalizeContoursPlugin(){ ReleaseTemps(); }
	NormalizeContoursPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "NormalizeContours"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();

	void ProcessImage( ImagePlus *img );
	static void NormalizeContoursPlugin::ProcessStatic( ImagePlus *img, int minLength, int maxLength );
};
