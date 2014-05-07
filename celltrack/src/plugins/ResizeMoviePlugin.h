#pragma once
#include "PluginBase.h"
#include "ResizeMovieSidebar.h"
#include "ImagePlus.h"
#include <cv.h>
#include <highgui.h>
#include "wxTextCtrl_double.h"

class ResizeMovieSidebar;

class ResizeMoviePlugin :
	public PluginBase
{
private:
	ResizeMovieSidebar *sidebar;
public:
	~ResizeMoviePlugin(){ ReleaseTemps(); }
	ResizeMoviePlugin( wxWindow* parent_, MyFrame *win_ );
	static string GetStaticName() { return "Resize"; }
	virtual void OnBookChange();
	void OnChangeWidth( );
	void OnChangeHeight( );
	void OnOK();
};
