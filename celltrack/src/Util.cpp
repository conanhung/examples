#include "util.h"
#include "string.h"

bool Config_ReadBool( const wxConfigBase *config, const wxString &key, bool defaultValue ) {
	config->Read(key, &defaultValue);
	return defaultValue;
}
long wxString2long( const wxString &s )
{
	long l;
	s.ToLong(&l);
	return l;
}

bool cvSizeEquals( const CvSize& p, const CvSize& q )
{
	return p.width == q.width && p.height == q.height;
}
bool cvSizeEquals( const IplImage* p, const IplImage* q )
{
	return p->width==q->width && p->height==q->height;
}
bool cvSizeEquals( const IplImage* p, const CvSize& q )
{
	return p->width==q.width && p->height==q.height;
}



void EnableMenu( wxMenu* menu, const bool enable )
{
	wxMenuItemList::Node* iter = menu->GetMenuItems().GetFirst();
	while (iter){
		if (iter->GetData()->IsSeparator())
			continue;
		iter->GetData()->Enable(enable);
		iter = iter->GetNext();
	}
}

wxPoint* ContourToPointArray( CvSeq* seq, const wxPoint& shift, const wxRealPoint& scale )
{
	if (!seq || !seq->total)
		return NULL;
	wxPoint *ps = new wxPoint[seq->total];
	CvPoint *p;
	for (int i=0; i<seq->total; i++) {
		p = (CvPoint*) cvGetSeqElem(seq, i);
		ps[i].x = p->x*scale.x + shift.x;
		ps[i].y = p->y*scale.y + shift.y;
	}
	return ps;
}

int GetContourCount(CvSeq *seq)
{
	int i = 0;
	while (seq) {i++; seq=seq->h_next;}
	return i;
}

long wxStringToLong( const wxString& s )
{
	long val;
	s.ToLong(&val);
	return val;
}
wxRealPoint GetImageScaling(int width, int height, int towidth, int toheight){
	wxRealPoint scale;
	wxSize newsize(0,0);
	if ( towidth * height > toheight * width ){
		newsize.SetHeight(wxMax(toheight,1));
		newsize.SetWidth(newsize.GetHeight() * width / height);
	}
	else if ( towidth * height < toheight * width ){
		newsize.SetWidth(wxMax(towidth,1));
		newsize.SetHeight(newsize.GetWidth() * height / width);
	}
	if (newsize.GetHeight() && newsize.GetWidth())
		scale = wxRealPoint(newsize.GetWidth()/(float)width, newsize.GetHeight()/(float)height);
	else
		scale = wxRealPoint(1.0,1.0);
	return scale;
}
void myShowSignedImage(char *window, IplImage *img){
    IplImage *temp=NULL;
    temp = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1 );
    cvConvertScaleAbs(img, temp, 1, 0);
    cvShowImage(window, temp);
    cvReleaseImage(&temp);
}
void myShowImage(IplImage *img,char *window){
	if (!window){
		cvNamedWindow("temp", 1);
		cvShowImage("temp", img);
	}
	else
		cvShowImage(window, img);
	cvWaitKey(0);
	if (!window)
		cvDestroyWindow("temp");
}
int myWaitKey(){
    int c;
    if((c=cvWaitKey(0))==27) exit(2);
    return c;
}
bool IsPointInRect(const CvPoint &p, const CvRect bounds){
	return p.x >= bounds.x && p.y >= bounds.y && p.x < bounds.width && p.y < bounds.height;
}
void RestrictRect(CvRect &rect, const CvRect bounds){
	CvPoint boundEnd = cvPoint(bounds.x + bounds.width, bounds.y+bounds.height);
	rect.x = MAX(bounds.x,MIN(boundEnd.x, rect.x));
	rect.y = MAX(bounds.y,MIN(boundEnd.y, rect.y));
	rect.width = MAX(0,MIN(bounds.width-rect.x, rect.width));
	rect.height = MAX(0,MIN(bounds.height-rect.y, rect.height));
}
void RestrictRectLoc(CvRect &rect, const CvRect bounds){
	CvPoint boundEnd = cvPoint(bounds.x + bounds.width, bounds.y+bounds.height);
	rect.x = MIN(rect.x, bounds.x+bounds.width - rect.width);
	rect.y = MIN(rect.y, bounds.y+bounds.height - rect.height);
	rect.x = MAX(bounds.x,MIN(boundEnd.x, rect.x));
	rect.y = MAX(bounds.y,MIN(boundEnd.y, rect.y));
}
void RestrictRectShift(CvPoint &shift, CvRect &newRect, const CvRect &rect, const CvRect &bounds){
			newRect = rect;
			newRect.x += shift.x;
			newRect.y += shift.y;
			RestrictRectLoc(newRect, bounds);
			shift.x = newRect.x - rect.x;
			shift.y = newRect.y - rect.y;
}

void ShiftContour(CvSeq *seq, const CvPoint &shift){
	ShiftContour(seq,seq,shift);
}
void ShiftContour(const CvSeq *src, CvSeq *dst, const CvPoint &shift){
	int np = src->total;
	if (!np)
		return;
	for (int i=0; i<np; i++){
		CvPoint *p = (CvPoint*) cvGetSeqElem(src, i);
		CvPoint *q = (CvPoint*) cvGetSeqElem(dst, i);
		q->x = p->x + shift.x;
		q->y = p->y + shift.y;
	}
}
CvMat *FeatPointsToMat(const std::vector<CvPoint2D32f> &feats){
	if (!feats.size())
		return NULL;
	CvMat *m = cvCreateMat(feats.size(),2,CV_32FC1);
	for (int i=0; i<feats.size(); i++){
		m->data.fl[2*i] = feats[i].x;
		m->data.fl[2*i+1] = feats[i].y;
	}
	return m;
}
void TransformFeatPoints(const std::vector<CvPoint2D32f> &src, std::vector<CvPoint2D32f> &dst, CvMat *rotation, CvMat *shift){
	float *rdata = rotation->data.fl;
	float *sdata = shift->data.fl;
	float x;
	for (int i=0; i<src.size(); i++){
		x = src[i].x;
		dst[i].x = x * rdata[0] + src[i].y * rdata[1] + rdata[2] + sdata[0];
		dst[i].y = x * rdata[3] + src[i].y * rdata[4] + rdata[5] + sdata[1];
	}
}
void ShiftFeatPoints(const std::vector<CvPoint2D32f> &src, std::vector<CvPoint2D32f> &dst, const CvPoint2D32f &shift){
	float x;
	for (int i=0; i<src.size(); i++){
		dst[i].x = src[i].x + shift.x;
		dst[i].y = src[i].y + shift.y;
	}
}