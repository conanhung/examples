#pragma once
#include "MyCapture.h"
#include "MyCanvas.h"
#include <wx/image.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include "ImagePlus.h"
#include <wx/arrstr.h>
#include "PluginBase.h"

class MyCanvas;
class PluginBase;

//manages read/process/write functions from a starting folder/file capture
class CaptureManager
{
private:
	bool OpenMovie_initialize(MyCapture &capture);
public:
	ImagePlus **book;
	ImagePlus img;
	int *frameMap;
	int frameCount;
	int fps;
	int pos;
	MyCanvas *canvas;
	CvSize size;
	PluginBase *ReloadListener;
	PluginBase *RedrawListener;
	PluginBase *BookChangeListener;

public:
	CvSeq *contours;

	CaptureManager(void);
	~CaptureManager(void);
	void Reset();
	void SetCanvas(MyCanvas *canvas_);
	MyCanvas* GetCanvas();
	bool OpenMovie(const char* avi);
	bool OpenMovie(const wxArrayString &files);
	bool SaveMovie(const char* avi);
	int GetFrameCount();
	CvSize GetSize();
	int GetPos();
	bool SetPos(int newpos, bool reload=false);
	bool OnDelete();
	bool OnDeleteBefore();
	bool OnDeleteAfter();
	bool OnPrev();
	bool OnNext();
	void Redraw(bool callPlugin=true);
	void SetReloadListener(PluginBase *ReloadListener_=NULL);
	void SetRedrawListener(PluginBase *RedrawListener_=NULL);
	void SetBookChangeListener(PluginBase *BookChangeListener_=NULL);
	void ReloadCurrentFrame(bool redraw=true, bool callPlugin=true);
	void ReloadCurrentFrameContours(bool redraw=true, bool callPlugin=true);
	void PushbackCurrentFrame();
	bool SaveTrackImage(wxBitmap &bmp);
	bool SaveTrajectoryImage(wxBitmap &bmp);
	bool SaveData_setup(const char* file, FILE* &fp);
	bool SaveTrackData(const char* file);
	bool SaveTrajectoryData(const char* file);
	bool SaveSpeedData(const char* file);
	bool SaveAreaData(const char* file);
	bool SaveDeformationData(const char* file);
	bool ImportTrackData(const char* file);

	std::vector<CvPoint> GetTrajectory(int c); //get trajectory of cth object
	std::vector<float> GetSpeeds(int c, float &totalDisp, float &avgSpeed); //get speeds of cth object
	std::vector<float> GetAreas(int c, float &avgArea); //get areas of cth object
	std::vector<float> GetAreaDiff(int c, float &avgDiff);
	std::vector<float> GetDeformation(int c, float &avgDef);

	void Resize(int width, int height, int method);
	void Crop(CvPoint topleft, CvSize size);
};
