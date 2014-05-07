#pragma once
#include "PluginBase.h"
#include "FindFeaturesSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class FindFeaturesSidebar;

class FindFeaturesPlugin :
	public PluginBase
{
private:
	IplImage *gray, *eig, *cnt_mask, *tempimg; //temporary images.
	FindFeaturesSidebar *sidebar;
	double quality, minDist, harrisK;
	int blockSize, maxCount, method;
	bool clean;

public:
	~FindFeaturesPlugin(){ ReleaseTemps(); }
	FindFeaturesPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "FindFeatures"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();
	void FetchParams();

	void ProcessImage( ImagePlus *img );
};
