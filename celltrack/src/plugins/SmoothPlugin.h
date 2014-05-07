#pragma once
#include "PluginBase.h"
#include "SmoothSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class SmoothSidebar;

class SmoothPlugin :
	public PluginBase
{
private:
	IplImage *temp, *edge; //temporary images.
	SmoothSidebar *sidebar;
public:
	~SmoothPlugin(){ ReleaseTemps(); }
	SmoothPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "Smooth"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();

	void ProcessImage( ImagePlus *img );
};
