#pragma once
#include "PluginBase.h"
#include "CropSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class CropSidebar;

class CropPlugin :
	public PluginBase
{
private:
	IplImage *gray, *edge; //temporary images.
	CropSidebar *sidebar;
public:
	~CropPlugin();
	CropPlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "Crop"; }
	virtual void OnOK();
	void OnMouse(wxMouseEvent &e);
	void DoPreview();
};
