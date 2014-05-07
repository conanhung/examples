#pragma once
#include "PluginBase.h"
#include "TrackContoursSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class TrackContoursSidebar;

class TrackContoursPlugin :
	public PluginBase
{
private:
	TrackContoursSidebar *sidebar;
	IplImage *gray, *ogray; //temporary images.
	float avgiterations;
	float alpha, beta, gamma, oalpha, obeta, ogamma, oteta, ozeta, oomega;
	bool useAvailable;
	CvSize winsize;
	int scheme;
	CvTermCriteria criteria;
public:
	~TrackContoursPlugin(){ ReleaseTemps(); }
	TrackContoursPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "TrackContours"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();
	virtual void ShowProcessInfo();
	virtual void OnOK();

	void FetchParams();

	void ProcessImage( ImagePlus *img, int pos );
	static void TrackContoursPlugin::ProcessStatic
( int i, ImagePlus *img, ImagePlus *oimg, IplImage* &gray, IplImage* &ogray, CvPoint* &ps, CvPoint* &ops,
 float alpha, float beta, float gamma, 
 float oalpha, float obeta, float ogamma, float oteta, float ozeta, float oomega,
 CvSize winsize, int scheme, CvTermCriteria criteria,
 bool useAvailable, int &iterations, bool oready, bool freetemps, float* &oEarc, bool oEarc_ready = false);
};
