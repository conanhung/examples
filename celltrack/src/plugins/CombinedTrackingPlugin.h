#pragma once
#include "PluginBase.h"
#include "CombinedTrackingSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class CombinedTrackingSidebar;

class CombinedTrackingPlugin :
	public PluginBase
{
private:
	bool useMT, useCS, useLK, useAS, useNC;


	CombinedTrackingSidebar *sidebar;
	IplImage *gray, *edge;

	//Match-Template parameters
	IplImage *mt_map;
	CvSize mt_winsize;
	int mt_method;
	bool mt_useFirst;

	//CAM-Shift parameters
	IplImage *cs_backproject, **cs_planes;
	CvHistogram *cs_hist;
	CvTermCriteria cs_criteria;
	int cs_hsizes[3];
	CvMat* cs_rotation, *cs_shift;
	bool cs_useFirst;

	//Optical Flow Parameters
	IplImage *lk_gray, *lk_ogray, *lk_pyr, *lk_opyr;
	float lk_avgLost;
	int lk_level;
	CvSize lk_winsize;
	CvTermCriteria lk_criteria;
	float lk_fixOutliers;
	bool lk_useAvailable;
	int lk_intwin;

	//Active Snake Parameters
	IplImage *as_gray, *as_ogray;
	float as_avgiterations;
	float as_alpha, as_beta, as_gamma, as_oalpha, as_obeta, as_ogamma, as_oteta, as_ozeta, as_oomega;
	bool as_useAvailable;
	CvSize as_winsize;
	int as_scheme;
	CvTermCriteria as_criteria;
	float *Earc;
	bool Earc_ready;

	//Normalize Contours
	int nc_minLength, nc_maxLength;

public:
	~CombinedTrackingPlugin(){ ReleaseTemps(); }
	CombinedTrackingPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "CombinedTracking"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();
	void FetchParams();

	void OnOK();
	void ProcessImage( ImagePlus *img, int pos );
};
