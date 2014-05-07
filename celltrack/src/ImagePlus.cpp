#include "ImagePlus.h"

ImagePlus::ImagePlus()
: orig(NULL), drawn(NULL), contours(NULL), contours_storage(NULL), dirty(true), numContours(0)
{
}
ImagePlus::ImagePlus(IplImage *orig_) : orig(NULL), drawn(NULL), contours(NULL), contours_storage(NULL), dirty(true), numContours(0)
{
	SetOriginal(orig_);
}
ImagePlus::ImagePlus(const ImagePlus &copy) : orig(NULL), drawn(NULL), contours(NULL), contours_storage(NULL), dirty(copy.dirty), numContours(copy.numContours)
{
	if ( copy.orig )
		orig = cvCloneImage(copy.orig);
	if ( copy.drawn )
		drawn = cvCloneImage(copy.drawn);
	if ( copy.contours )
		CloneContours(&copy);
}
ImagePlus & ImagePlus::operator = (const ImagePlus &copy)
{
	ReleaseAll();
	if ( copy.orig )
		orig = cvCloneImage(copy.orig);
	if ( copy.drawn )
		drawn = cvCloneImage(copy.drawn);
	if ( copy.contours )
		CloneContours(&copy);
	dirty = copy.dirty;
	numContours = copy.numContours;
	return *this;
}
void ImagePlus::CloneContours(const ImagePlus *copy)
{
	CvSeq *c = copy->contours;
	ReCreateContoursStorage();
	if (!c)
		return;
	CvSeq *cp, *mycp;
	cp=c;
	contours = cvCloneSeq(c, contours_storage);
	mycp=contours;
	contourArray.push_back(mycp);
	while (cp->h_next) {
		cp = cp->h_next;
		mycp->h_next = cvCloneSeq(cp, contours_storage);
		mycp = mycp->h_next;
		contourArray.push_back(mycp);
	}
	feats = copy->feats;
}
ImagePlus::~ImagePlus(void)
{
	ReleaseAll();
}
void ImagePlus::ReleaseAll()
{
	if ( orig )
		cvReleaseImage(&orig);
	if ( drawn )
		cvReleaseImage(&drawn);
	RemoveAllContours();
	dirty = true;
}
void ImagePlus::SetOriginal(IplImage *orig_){
	ReleaseAll();
	orig = cvCloneImage(orig_);
	dirty = true;
}
// This should no longer be needed. The actual drawing of contours and features
// are now done in MyCanvas class.
void ImagePlus::Redraw()
{
	if ( drawn )
		cvCopyImage(orig, drawn);
	else
		drawn = cvCloneImage(orig);
	if ( contours )
	    cvDrawContours( drawn, contours, CV_RGB(255,0,0), CV_RGB(0,255,0), 1, 1, CV_AA, cvPoint(0,0) );
	dirty = false;
}
wxImage ImagePlus::ToWxImage()
{
	if ( !orig )
		return wxImage();
	if ( dirty )
		Redraw();
	return  wxImage(drawn->width, drawn->height, (unsigned char*) drawn->imageData, TRUE);
}
IplImage * ImagePlus::ToIplImage()
{
	if ( !orig )
		return NULL;
	if ( dirty )
		Redraw();
	return  drawn;
}
CvMemStorage* ImagePlus::ReCreateContoursStorage()
{
	return CreateContoursStorageOnDemand(true);
}
CvMemStorage* ImagePlus::CreateContoursStorageOnDemand(bool recreate)
{
	if ( recreate )
		RemoveAllContours();
	if (!contours_storage)
		contours_storage = cvCreateMemStorage(0);
	return contours_storage;
}
void ImagePlus::RemoveAllContours()
{
	if ( contours_storage )
		cvReleaseMemStorage(&contours_storage);
	contours = NULL;
	contourArray.clear();
	feats.clear();
}
void ImagePlus::RemoveContour( int index )
{
	CvSeq *seq = contourArray[index];
	cvClearSeq(seq);
	if (index==0)
		contours = contours->h_next;
	else {
		contourArray[index-1]->h_next = seq->h_next;
		if (seq->h_next)
			seq->h_next->h_prev = contourArray[index-1];
	}
	cvRelease((void**)&seq);
	contourArray.erase(contourArray.begin()+index);
	feats.erase(feats.begin()+index);
}
void ImagePlus::RemoveContour( CvSeq* seq )
{
	for (unsigned int i=0; i<contourArray.size(); i++){
		if (contourArray[i] == seq){
			RemoveContour(i);
			return;
		}
	}
}

void ImagePlus::RemoveContours( int from, int to )
{
	from = MAX(0,from);
	to = MIN((int)contourArray.size()-1,to);
	if (from > to || from > (int)contourArray.size()-1)
		return;
	if (from ==0 && to==contourArray.size()-1)
		RemoveAllContours();
	else {
		for (int i=from; i<=to; i++)
			RemoveContour(i);
	}
}
//seq must already use our storage.
void ImagePlus::AddContours( CvSeq* seq )
{
	CvSeq *c;
	if (contours) {
		c = contours;
		while (c->h_next) c=c->h_next;
		c->h_next = seq;
		seq->h_prev = c;
	}
	else
		contours = seq;
	c = seq;
	while(c){ contourArray.push_back(c); c=c->h_next; feats.push_back(FeatPoints());}
	dirty = true;
}
// add a polygon of point vector to a contours
void ImagePlus::AddRoi( std::vector<wxPoint>& roi )
{
	if (!roi.size())
		return;
	CvSeq *seq = cvCreateSeq( CV_SEQ_ELTYPE_POINT|CV_SEQ_POLYLINE|CV_SEQ_FLAG_CLOSED, sizeof( CvContour ), sizeof( CvPoint), CreateContoursStorageOnDemand() );
	CvPoint p;
	for (unsigned int i=0; i<roi.size(); i++){
		p.x = roi[i].x;
		p.y = roi[i].y;
		cvSeqPush(seq, &p);
	}
	AddContours(seq);
}
void ImagePlus::AddContour( CvPoint* ps, int np )
{
	if (!np) return;
	CvSeq *seq = cvCreateSeq( CV_SEQ_ELTYPE_POINT|CV_SEQ_POLYLINE|CV_SEQ_FLAG_CLOSED, sizeof( CvContour ), sizeof( CvPoint), CreateContoursStorageOnDemand() );
	for (int i=0; i<np; i++){
		cvSeqPush(seq, &ps[i]);
	}
	AddContours(seq);
}
void ImagePlus::AddContour( wxPoint* ps, int np )
{
	if (!np) return;
	CvSeq *seq = cvCreateSeq( CV_SEQ_ELTYPE_POINT|CV_SEQ_POLYLINE|CV_SEQ_FLAG_CLOSED, sizeof( CvContour ), sizeof( CvPoint), CreateContoursStorageOnDemand() );
	CvPoint p;
	for (int i=0; i<np; i++){
		p.x = ps[i].x; p.y = ps[i].y;
		cvSeqPush(seq, &p);
	}
	AddContours(seq);
}
void ImagePlus::AddContour( CvPoint2D32f* ps, int np )
{
	if (!np) return;
	CvSeq *seq = cvCreateSeq( CV_SEQ_ELTYPE_POINT|CV_SEQ_POLYLINE|CV_SEQ_FLAG_CLOSED, sizeof( CvContour ), sizeof( CvPoint), CreateContoursStorageOnDemand() );
	CvPoint p;
	for (int i=0; i<np; i++){
		p = cvPointFrom32f(ps[i]);
		cvSeqPush(seq, &p);
	}
	AddContours(seq);
}
void ImagePlus::ReplaceContour( int index, CvPoint* ps, int np )
{
	if (!np){
		RemoveContour(index);
		return;
	}
	CvSeq *seq = contourArray[index];
	cvClearSeq(seq);
//	cvRelease((void**)&seq);		
//	contourArray[index] = cvCreateSeq( CV_SEQ_ELTYPE_POINT|CV_SEQ_POLYLINE|CV_SEQ_FLAG_CLOSED, sizeof( CvContour ), sizeof( CvPoint), CreateContoursStorageOnDemand() );
//	seq = contourArray[index];
	for (int i=0; i<np; i++)
		cvSeqPush(seq, &ps[i]);
}
void ImagePlus::ReplaceContour( int index, CvPoint2D32f* ps, int np )
{
	if (!np){
		RemoveContour(index);
		return;
	}
	CvSeq *seq = contourArray[index];
	cvClearSeq(seq);
	CvPoint p;
	for (int i=0; i<np; i++){
		p = cvPointFrom32f(ps[i]);
		cvSeqPush(seq, &p);
	}
}
void ImagePlus::ReplaceContour( int index, std::vector<wxPoint>& roi )
{
	if (!roi.size()){
		RemoveContour(index);
		return;
	}
	CvSeq *seq = contourArray[index];
	cvClearSeq(seq);
	CvPoint p;
	int np = (int) roi.size();
	for (int i=0; i<np; i++){
		p = cvPoint(roi[i].x, roi[i].y);
		cvSeqPush(seq, &p);
	}
}

void ImagePlus::ReplaceContour( int index, CvSeq* inseq )
{
	int np = inseq->total;
	if (!np){
		RemoveContour(index);
		return;
	}
	CvSeq *seq = contourArray[index];
	cvClearSeq(seq);
	for (int i=0; i<np; i++){
		cvSeqPush(seq, (CvPoint*) cvGetSeqElem(inseq, i));
	}
}

void ImagePlus::AddFeats( int index, CvPoint2D32f* feats_, int nf, bool replace )
{
	FeatPoints *fs = &feats[index];
	if (replace)
		fs->clear();
	for (int i=0; i<nf; i++)
		fs->push_back(feats_[i]);
}

void ImagePlus::Resize(int width, int height, int method){
	if (width==orig->width && height==orig->height)
		return;
	CvPoint2D32f scale = cvPoint2D32f(width/(float)orig->width, height/(float)orig->height);
	CvSize newsize = cvSize(width,height);
	IplImage *img = cvCreateImage(newsize, IPL_DEPTH_8U, 3);
	cvResize(orig, img);
	cvReleaseImage(&orig);
	cvReleaseImage(&drawn);
	orig = img;
	drawn = cvCloneImage(img);
	for (int i=0; i<contourArray.size(); i++){
		CvSeq *seq = contourArray[i];
		for (int j=0; j<seq->total; j++){
			CvPoint *p = (CvPoint*) cvGetSeqElem(seq, j);
			p->x = (int)(p->x * scale.x);
			p->y = (int)(p->y * scale.y);
		}
		for (int j=0; j<feats[i].size(); j++)
			feats[i][j] = cvPoint2D32f(feats[i][j].x * scale.x, feats[i][j].y * scale.y);
	}
	dirty = true;
}
#include "Util.h"
void ImagePlus::Crop(CvPoint topleft, CvSize newsize){
	IplImage *img = cvCreateImage(newsize, IPL_DEPTH_8U, 3);
	CvRect rect = cvRect(topleft.x, topleft.y, newsize.width, newsize.height);
	cvSetImageROI(orig, rect);
	cvCopy(orig, img);
	cvReleaseImage(&orig);
	cvReleaseImage(&drawn);
	orig = img;
	drawn = cvCloneImage(img);
	for (int i=contourArray.size()-1; i>=0; i--){
		CvSeq *seq = contourArray[i];
		bool toberemoved = false;
		for (int j=0; j<seq->total; j++){
			CvPoint *p = (CvPoint*) cvGetSeqElem(seq, j);
			p->x -= topleft.x;
			p->y -= topleft.y;
			if (!IsPointInRect(*p, cvRect(0,0,newsize.width,newsize.height))){
				toberemoved = true;
				break;
			}
		}
		if(!toberemoved){
			for (int j=0; j<feats[i].size(); j++){
				feats[i][j] = cvPoint2D32f(feats[i][j].x -topleft.x, feats[i][j].y -topleft.y);
				if (!IsPointInRect(cvPointFrom32f(feats[i][j]), cvRect(0,0,newsize.width,newsize.height))){
					toberemoved = true;
					break;
				}
			}
		}
		if (toberemoved)
			RemoveContour(i);
	}
	dirty = true;
}
