#pragma once
#include "PluginBase.h"
#include "MatchTemplateSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class MatchTemplateSidebar;

class MatchTemplatePlugin :
	public PluginBase
{
private:
	MatchTemplateSidebar *sidebar;
	IplImage *map;
	CvSize winsize;
	int method;
	bool useFirst;
public:
	~MatchTemplatePlugin(){ ReleaseTemps(); }
	MatchTemplatePlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "MatchTemplate"; }
	virtual int GetScope();
	virtual bool IsPreviewOn();
	virtual void DoPreview();
	virtual void ReleaseTemps();
	virtual void OnOK();
	void FetchParams();

	void ProcessImage( ImagePlus *img, int pos );
	static void ProcessStatic
( int i, ImagePlus *img, ImagePlus *oimg, 
 int method, CvSize winsize, IplImage* &map);
};
