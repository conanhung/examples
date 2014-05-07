#pragma once
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <wx/image.h>
#include <vector>

//TODO?: abstract out an object (with contour and features as members). This can
//make object handling easier, at a cost to translate back and forth between cvContour
typedef std::vector<CvPoint2D32f> FeatPoints;
typedef std::vector<std::vector<CvPoint2D32f>> FeatPointsSet;

class ImagePlus
{
public:
	IplImage *orig;
	IplImage *drawn;
	CvSeq *contours;
	std::vector<CvSeq*> contourArray;
	int numContours;
	CvMemStorage *contours_storage;
	std::vector<std::vector<CvPoint2D32f>> feats;
	bool dirty; //specifies if drawn need to be updated. no longer needed.

	ImagePlus();
	~ImagePlus();
	ImagePlus(IplImage *orig_);
	// copy constructor
	ImagePlus(const ImagePlus &copy);
	// assignment operator
	ImagePlus & operator = (const ImagePlus &copy);
	void CloneContours(const ImagePlus *copy);

	void ReleaseAll();
//	ImagePlus *prev;
//	ImagePlus *next;
	void SetOriginal(IplImage *orig_);
	CvMemStorage* CreateContoursStorageOnDemand(bool recreate=false);
	CvMemStorage* ReCreateContoursStorage();
	void RemoveAllContours();
	void RemoveContour(int index);
	void RemoveContours(int from, int to);
	void RemoveContour(CvSeq *seq);
	void AddContours(CvSeq *seq);
	void AddRoi(std::vector<wxPoint> &roi);	
	void AddContour( wxPoint* ps, int np );
	void AddContour(CvPoint *ps, int np);
	void AddContour(CvPoint2D32f *ps, int np);
	void ReplaceContour(int index, CvPoint *ps, int np);
	void ReplaceContour( int index, CvPoint2D32f* ps, int np );
	void ReplaceContour( int index, std::vector<wxPoint>& roi );
	void ReplaceContour( int index, CvSeq *seq );

	void AddFeats(int index, CvPoint2D32f* feats, int nf, bool replace=true);

	void Redraw();
	wxImage ToWxImage();
	IplImage *ToIplImage();
	void Resize(int width, int height, int method);
	void Crop(CvPoint topleft, CvSize size);
};
