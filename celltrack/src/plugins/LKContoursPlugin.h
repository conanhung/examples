#pragma once
#include "PluginBase.h"
#include "LKContoursSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class LKContoursSidebar;

class LKContoursPlugin :
	public PluginBase
{
private:
	LKContoursSidebar *sidebar;
	IplImage *gray, *ogray, *pyr, *opyr; //temporary images.
	float avgLost;
	int level;
	CvSize winsize;
	CvTermCriteria criteria;
	float fixOutliers;
	bool useAvailable;
	int intwin;
public:
	LKContoursPlugin( wxWindow* parent_, MyFrame *win_ );
	~LKContoursPlugin(){ ReleaseTemps(); }
	static string GetStaticName() { return "LKContours"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();
	virtual void ShowProcessInfo();
	virtual void OnOK();

	void FetchParams();
	void ProcessImage( ImagePlus *img, int pos );
	static void LKContoursPlugin::ProcessStatic(ImagePlus *img, ImagePlus *oimg, int level, CvSize winsize, CvTermCriteria criteria, int flags, float fixOutliers, int intwin, float &avgLost, IplImage* &gray, IplImage* &ogray, IplImage* &pyr, IplImage* &opyr, CvPoint* &ops, CvPoint2D32f* &psf, CvPoint2D32f* &opsf, char* &status, bool useAvailable, int &np_total, bool rebuild_opsf, bool free_temps);

	static float GetStdDevSqDist(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, float avg, char *status=NULL, float *sqdists=NULL);
	static float GetAvgSqDist(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, char *status=NULL, float *sqdists=NULL);
	static CvPoint2D32f GetAvgDisp(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, char *status=NULL);
	static void GetRunningAvgDisp(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, char *status, int intwin, bool intwin_checkall, CvPoint2D32f *avgDisps, float fixOutliers);
	static int InterpolateTracking(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, int nf, char *status=NULL, float fixOutliers=3, int intwin=5); //intwin: local interpolation window



};
