#pragma once
#include "PluginBase.h"
#include "ResizeSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class ResizeSidebar;

class ResizePlugin :
	public PluginBase
{
private:
	ResizeSidebar *sidebar;
public:
	~ResizePlugin(){ ReleaseTemps(); }
	ResizePlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "Resize"; }
	virtual void OnBookChange();
	void OnChangeWidth( );
	void OnChangeHeight( );
	void OnOK();
};
