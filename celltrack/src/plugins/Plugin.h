#pragma once
#include "PluginBase.h"
#include "ImproveContoursSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>

class ImproveContoursSidebar;

class ImproveContoursPlugin :
	public PluginBase
{
private:
	IplImage *gray, *edge; //temporary images.
	ImproveContoursSidebar *sidebar;
public:
	ImproveContoursPlugin( wxWindow* parent_, CaptureManager *ms_ );
	~ImproveContoursPlugin(void);
	static string GetStaticName() { return "ImproveContours"; }
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual int GetScope();

	void ProcessImage( ImagePlus *img );
};
