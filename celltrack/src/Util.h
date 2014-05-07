#ifndef UTIL_H
#define UTIL_H

#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "MyPoint.h"
#include <vector>
#include <wx/msw/winundef.h>

#define forto(i,n) for(i=0; i<n; i++)
#define fromto(i,j,n) for(i=j; i<n; i++)
#define ExitIf(e) {if(e){(void)fprintf(stderr, "---ERROR---\nfile: %s \nline: %d \nexpr: %s\n\n",__FILE__,__LINE__, (#e)); exit(1);}}

#include <wx/config.h>
bool Config_ReadBool( const wxConfigBase *config, const wxString &key, bool defaultValue );

#include <wx/wx.h>
long wxString2long( const wxString &s );

#include <cxcore.h>
#define cvImageSize(x)	cvSize(x->width, x->height)
bool cvSizeEquals(const CvSize &p, const CvSize &q);
bool cvSizeEquals(const IplImage *p, const IplImage *q);
bool cvSizeEquals(const IplImage *p, const CvSize &q);

#include <wx/menu.h>
#include <wx/list.h>
void EnableMenu( wxMenu* menu, const bool enable=true );
#define EnableMenuItem(menu, itemid, enable)		menu->FindItem(itemid)->Enable(enable)

//creates a wxPoint[] from a cvContour. It's user's responsibility to delete the returned array.
wxPoint* ContourToPointArray(CvSeq *seq, const wxPoint &shift=wxPoint(0,0), const wxRealPoint &scale=wxRealPoint(1.0,1.0));

// Get the number of contours in a CvContour list
int GetContourCount(CvSeq *seq);

#define TOGGLE_LISTBOX_SELECTION(listbox, index)	\
	if(listbox->IsSelected(index)) \
		listbox->Deselect(index); \
	else \
		listbox->Select(index);

long wxStringToLong(const wxString &s);

#define WXFORMAT	wxString::Format

class ScoredIndex{
public:
	float score;
	int index;
	ScoredIndex(float score_, int index_): score(score_), index(index_) {}
};
class ScoredIndexPriority {
public:
	int operator()( const ScoredIndex& a, const ScoredIndex& b){
		return a.score < b.score;
	}
};
#include <wx/gdicmn.h>
wxRealPoint GetImageScaling(int width, int height, int towidth, int toheight);

void myShowImage(IplImage *img, char *window=NULL);
void myShowSignedImage(char *window, IplImage *img);
int myWaitKey();
bool IsPointInRect(const CvPoint &p, const CvRect bounds);
void RestrictRect(CvRect &rect, const CvRect bounds);
void RestrictRectLoc(CvRect &rect, const CvRect bounds);
void RestrictRectShift(CvPoint &shift, CvRect &newRect, const CvRect &rect, const CvRect &bounds);
void ShiftContour(const CvSeq *src, CvSeq *dst, const CvPoint &shift);
void ShiftContour(CvSeq *seq, const CvPoint &shift);

CvMat *FeatPointsToMat(const std::vector<CvPoint2D32f> &feats);
void TransformFeatPoints(const std::vector<CvPoint2D32f> &src, std::vector<CvPoint2D32f> &dst, CvMat *rotation, CvMat *shift);
void ShiftFeatPoints(const std::vector<CvPoint2D32f> &src, std::vector<CvPoint2D32f> &dst, const CvPoint2D32f &shift);

template<class T> class CvImageWrapper
{
  private:
  IplImage* imgp;
  public:
  CvImageWrapper(IplImage* img=0) {imgp=img;}
  ~CvImageWrapper(){imgp=0;}
  void operator=(IplImage* img) {imgp=img;}
  inline T* operator[](const int rowIndx) {
    return ((T *)(imgp->imageData + rowIndx*imgp->widthStep));}
};

typedef struct{
  unsigned char b,g,r;
} RgbPixel;

typedef struct{
  float b,g,r;
} RgbPixelFloat;

typedef CvImageWrapper<RgbPixel>       RgbImage;
typedef CvImageWrapper<RgbPixelFloat>  RgbImageFloat;
typedef CvImageWrapper<RgbPixelFloat>  RgbImageFloat;
typedef CvImageWrapper<unsigned char>  BwImage;
typedef CvImageWrapper<RgbPixelFloat>  RgbImageFloat;
typedef CvImageWrapper<float>          BwImageFloat;
#endif