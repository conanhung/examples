#include "CaptureManager.h"
#include "Preferences.h"
#include "util.h"

CaptureManager::CaptureManager(void)
: book(NULL), canvas(NULL), RedrawListener(NULL), BookChangeListener(NULL), ReloadListener(NULL)
{ Reset(); }
CaptureManager::~CaptureManager(void){
	Reset();
}
void CaptureManager::Reset(){
	int i;
	if (book) {
		for (i=0; i<frameCount; i++){
			delete book[i];
		}
		delete[] book;
	}
	frameCount = 0;
	fps = 0;
	pos = 0;
	size = cvSize(0, 0);
	img.ReleaseAll();
}
void CaptureManager::SetCanvas(MyCanvas *canvas_){
	canvas = canvas_;
}
MyCanvas* CaptureManager::GetCanvas()
{
	return canvas;
}

bool CaptureManager::OpenMovie(const char* avi){
	Reset();
	MyCapture_Movie capture(avi);
	return OpenMovie_initialize(capture);
}
bool CaptureManager::OpenMovie( const wxArrayString& files )
{
	Reset();
	MyCapture_Files capture(files);
	return OpenMovie_initialize(capture);
}
#include <wx/progdlg.h>
bool CaptureManager::OpenMovie_initialize(MyCapture &capture)
{
	if (!capture.IsOK())
		return false;
	frameCount = capture.frameCount;
	fps = capture.fps ? capture.fps : Preferences::GetSavingFpsDefault();
	book = new ImagePlus*[frameCount];
	wxProgressDialog progressDlg("Loading movie...", wxString::Format("Frame 0 of %d", frameCount),frameCount, NULL, wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_REMAINING_TIME|wxPD_AUTO_HIDE);
	for (int i=0; i<frameCount; i++){
		progressDlg.Update(i+1, wxString::Format("Frame %d of %d", i+1, frameCount));
		IplImage *newframe = capture.queryFrame(i);
		IplImage *resized;
		if (i == 0){
			size = cvSize(newframe->width, newframe->height);
			book[i] = new ImagePlus(newframe);
		}
		else if(!cvSizeEquals(newframe, size)){
			resized = cvCloneImage(book[0]->orig);
			cvResize(newframe, resized);
			book[i] = new ImagePlus(resized);
			cvReleaseImage(&resized);
		}
		else
			book[i] = new ImagePlus(newframe);
	}
	if (BookChangeListener)
		BookChangeListener->OnBookChange();
	SetPos(0);
	return true;
}


bool CaptureManager::SaveMovie(const char* avi){
	bool resize = false;
	CvSize newsize = size;
	if ( Preferences::GetSavingSizeOverride() && !cvSizeEquals(Preferences::GetSavingSize(), size) ){
		resize = true;
		newsize = Preferences::GetSavingSize();
	}
	CvVideoWriter* writer = cvCreateVideoWriter(avi,
		Preferences::GetSavingCodec(),
		Preferences::GetSavingFpsOverride() || !fps ? Preferences::GetSavingFpsDefault() : fps,
		newsize, 1);
	IplImage *resized;
	if (resize)
		resized = cvCreateImage(newsize,8,3);
	IplImage *frame_flip = cvCreateImage(newsize,8,3);
	wxProgressDialog progressDlg("Saving movie...", wxString::Format("Frame 0 of %d", frameCount),frameCount, NULL, wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_REMAINING_TIME|wxPD_AUTO_HIDE);
	for (int i=0; i<frameCount; i++) {
		progressDlg.Update(i+1, wxString::Format("Frame %d of %d", i+1, frameCount));
		if (resize)
			cvResize(book[i]->ToIplImage(), resized);
		else
			resized = book[i]->ToIplImage();
		cvConvertImage( resized, frame_flip, CV_CVTIMG_SWAP_RB );
		cvWriteFrame(writer, frame_flip);
	}
	cvReleaseVideoWriter(&writer);
	cvReleaseImage(&frame_flip);
	if (resize)
		cvReleaseImage(&resized);
	return true;
}
int CaptureManager::GetFrameCount(){
	return frameCount;
}
CvSize CaptureManager::GetSize(){
	return size;
}
int CaptureManager::GetPos(){
	return pos;
}
void CaptureManager::ReloadCurrentFrame(bool redraw, bool callPlugin){
	if (callPlugin && ReloadListener)
		ReloadListener->OnReload();
	img = *book[pos];
	if (redraw)
		Redraw(callPlugin);
}
void CaptureManager::ReloadCurrentFrameContours(bool redraw, bool callPlugin){
	if (callPlugin && ReloadListener)
		ReloadListener->OnReload();
	img.CloneContours(book[pos]);
	if (redraw)
		Redraw(callPlugin);
}
void CaptureManager::PushbackCurrentFrame(){
	*(book[pos]) = img;
}
bool CaptureManager::SetPos(int newpos, bool reload){
	if (newpos<0 || newpos>=frameCount || (newpos==pos && img.orig && !reload))
		return false;
	pos = newpos;
	ReloadCurrentFrame();
	return true;
}
bool CaptureManager::OnDeleteBefore()
{
	if (!pos)
		return false;
	for (int i=0; i<pos; i++)
		delete book[i];
	for (int i=0; i<frameCount-pos; i++)
		book[i] = book[i+pos];
	frameCount-=pos;
	SetPos(0,true);
	if (BookChangeListener)
		BookChangeListener->OnBookChange();
	return true;
}
bool CaptureManager::OnDeleteAfter()
{
	for (int i=pos+1; i<frameCount; i++)
		delete book[i];
	frameCount=pos+1;
	if (BookChangeListener)
		BookChangeListener->OnBookChange();
	return true;
}
bool CaptureManager::OnDelete()
{
	if (!frameCount)
		return false;
	if (frameCount == 1){
		wxLogError("Cannot delete the last and only frame.");
		return false;
	}
	ImagePlus *todelete=book[pos];
	int i;
	for (i=pos; i<frameCount-1; i++)
		book[i]=book[i+1];
	book[i] = NULL;
	frameCount--;
	if (BookChangeListener)
		BookChangeListener->OnBookChange();
	SetPos(pos==frameCount ? frameCount-1 : pos, true);
	delete todelete;
	return true;
}
bool CaptureManager::OnPrev(){
	return SetPos(pos-1);
}
bool CaptureManager::OnNext(){
	return SetPos(pos+1);
}
void CaptureManager::Redraw(bool callPlugin){
	if (!canvas)
		return;
//	canvas->SetImage(img.ToWxImage());
	if (callPlugin && RedrawListener)
		RedrawListener->OnRedraw();
	canvas->SetImage(img);
}
void CaptureManager::SetRedrawListener( PluginBase* RedrawListener_ )
{
	if (RedrawListener && RedrawListener_)
		wxLogError("canvas already had a redraw listener.");
	RedrawListener = RedrawListener_;
}
void CaptureManager::SetReloadListener( PluginBase* ReloadListener_ )
{
	if (ReloadListener && ReloadListener_)
		wxLogError("canvas already had a Reload listener.");
	ReloadListener = ReloadListener_;
}
void CaptureManager::SetBookChangeListener( PluginBase* BookChangeListener_ )
{
	if (BookChangeListener && BookChangeListener_)
		wxLogError("canvas already had a BookChange listener.");
	BookChangeListener = BookChangeListener_;
}


#include "MyPoint.h"
std::vector<float> CaptureManager::GetSpeeds(int c, float &totalDisp, float &avgSpeed){
	std::vector<CvPoint> traj = GetTrajectory(c);
	std::vector<float> s(frameCount-1, 0.0);
	totalDisp = 0;
	int goodSteps = 0;
	for (int i=0; i<frameCount-1; i++){
		if (!(MyPoint(-1,-1)==traj[i] || MyPoint(-1,-1)==traj[i+1])) {
			goodSteps++;
			totalDisp += (s[i] = MyPoint(traj[i]).Euclidean(MyPoint(traj[i+1])));
		}
	}
	avgSpeed = (goodSteps ? totalDisp/goodSteps : 0);
	return s;
}
std::vector<float> CaptureManager::GetAreas(int c, float &avgArea){
	std::vector<float> a(frameCount, 0.0);
	int goodSteps = 0;
	float totalArea = 0.0;
	for (int i=0; i<frameCount; i++){
		if (book[i]->contourArray.size() > c){
			goodSteps++;
			totalArea += (a[i]=fabs(cvContourArea(book[i]->contourArray[c])));
		}
	}
	avgArea = (goodSteps ? totalArea/goodSteps : 0);
	return a;
}
std::vector<float> CaptureManager::GetAreaDiff(int c, float &avgDiff){
	std::vector<float> a = GetAreas(c,avgDiff);
	std::vector<float> diff(frameCount-1, 0.0);
	float totalDiff = 0;
	int goodSteps = 0;
	for (int i=0; i<frameCount-1; i++){
		if (book[i]->contourArray.size() > c){
			goodSteps++;
			totalDiff += (diff[i] = a[i+1]-a[i]);
		}
	}
	avgDiff = (goodSteps ? totalDiff/goodSteps : 0);
	return diff;
}
#include "FindContoursPlugin.h"
std::vector<float> CaptureManager::GetDeformation(int c, float &avgDef){
	std::vector<CvPoint> traj = GetTrajectory(c);
	std::vector<float> areas = GetAreas(c,avgDef);
	std::vector<float> defs(frameCount-1, 0.0);
	float totalDef = 0;
	int goodSteps = 0;
	CvSeq *h_next;
	ImagePlus *img_ = new ImagePlus(img);
	IplImage *gray = cvCreateImage(cvGetSize(img.orig), IPL_DEPTH_8U, 1);
	IplImage *edge = cvCreateImage(cvGetSize(img.orig), IPL_DEPTH_8U, 1);
	for (int i=0; i<frameCount-1; i++){
		if (!(MyPoint(-1,-1)==traj[i] || MyPoint(-1,-1)==traj[i+1])) {
			wxPoint *ps = ContourToPointArray(book[i]->contourArray[c], MyPoint(traj[i+1])-MyPoint(traj[i]).ToWxPoint());
			img_->RemoveAllContours();
			img_->AddContour(ps,book[i]->contourArray[c]->total);
			delete[] ps;

			CvSeq *seq = book[i+1]->contourArray[c];
			CvSeq *oseq = img_->contourArray[0];
			//Draw both contours on the temporary image
			cvZero(img_->orig);
			h_next = seq->h_next; seq->h_next = NULL;
			cvDrawContours(img_->orig, seq, CV_RGB(255,255,255), CV_RGB(0,0,0), 1, CV_FILLED, CV_AA, cvPoint(0,0));
			seq->h_next = h_next;
			cvDrawContours(img_->orig, oseq, CV_RGB(255,255,200), CV_RGB(0,0,0), 1, CV_FILLED, CV_AA, cvPoint(0,0));

			//detect contours on the drawn image:
			FindContoursPlugin::ProcessImage_static(img_,gray,edge,150,50,3,1);
			float unionArea = 0;
			for (int j=0; j<img_->contourArray.size(); j++){
				unionArea += fabs(cvContourArea(img_->contourArray[j]));
			}

			goodSteps++;
			totalDef += (defs[i] = 2*unionArea - areas[i] - areas[i+1]);
		}
	}
	cvReleaseImage(&gray);
	cvReleaseImage(&edge);
	delete img_;
	avgDef = (goodSteps ? totalDef/goodSteps : 0);
	return defs;
}
std::vector<CvPoint> CaptureManager::GetTrajectory(int c){
	std::vector<CvPoint> traj(frameCount);
	for (int i=0; i<frameCount; i++){
		if (book[i]->contourArray.size() <= c)
			traj[i]=cvPoint(-1,-1);
		else{
			CvMoments m;
			double m00,m10,m01;
			cvMoments(book[i]->contourArray[c], &m);
			m00 = cvGetSpatialMoment(&m,0,0);
			m01 = cvGetSpatialMoment(&m,0,1);
			m10 = cvGetSpatialMoment(&m,1,0);
			traj[i] = cvPoint(cvRound(m.m10/m.m00), cvRound(m.m01/m.m00));
		}
	}
	return traj;
}


#include <stdio.h>
bool CaptureManager::SaveData_setup(const char* file, FILE* &fp){
	if (!book[0]->contourArray.size()){
		wxLogError("No objects in the first frame. Detect/draw boundaries in the first frame and apply tracking first.");
		return false;
	}
	if (!(fp = fopen(file,"w"))){
		wxLogError("Unable to open file %s", file);
		return false;
	}
	return true;
}

bool CaptureManager::SaveTrackData(const char* file) {
	FILE *fp;
	if(!SaveData_setup(file,fp)) return false;

	int numContours=book[0]->contourArray.size();
	fprintf(fp, "#width: %d, height: %d, frameCount: %d, fps: %d\n", size.width, size.height, frameCount, numContours, fps);
	fprintf(fp, "#cellCount: %d\n", numContours);
	for (int c=0; c<numContours; c++){
		CvSeq *oseq = book[0]->contourArray[c];
		int np = oseq->total;
		fprintf(fp, "#Cell: %d, pointCount: %d\n", c+1, np);
		for (int j=0; j<frameCount; j++){
			for (int i=0; i<np; i++){
				if(book[j]->contourArray.size() <= c || book[j]->contourArray[c]->total <= i)
					fprintf(fp,"-1 -1 ");
				else{
					CvPoint *p = (CvPoint*) cvGetSeqElem(book[j]->contourArray[c], i);
					fprintf(fp, "%d\t%d\t", p->x, p->y);
				}
			}
			fprintf(fp,"\n");
		}
	}
	fclose(fp);
	return true;
}
bool CaptureManager::ImportTrackData(const char* file) {
	FILE *fp = fopen(file,"r");
	if (!fp){
		wxLogError("Unable to open file %s", file);
		return false;
	}

	//check if there's already some detected cells.
	bool hasCells = false;
	for( int i=0; i<frameCount; i++ ){
		if (book[i]->contourArray.size()){
			hasCells = true;
			break;
		}
	}
	if (hasCells){
		int reply = wxMessageBox("There are already detected cells. Do you want to remove existing cells before importing tracking data?", "Remove existing cells?", wxYES_NO | wxCANCEL, NULL);
		if (reply == wxCANCEL)
			return false;
		else if(reply == wxYES){
			for( int i=0; i<frameCount; i++ )
				book[i]->RemoveAllContours();
		}
	}
	//TODO: give notice if the movie info of the track-data does not match with current movie.
	int NumCells;
	int Width, Height, FrameCount, FSP;
	if( fscanf(fp, "#width: %d, height: %d, frameCount: %d, fps: %d\n#cellCount: %d\n", &Width, &Height, &FrameCount, &FSP, &NumCells) !=5 ) {
		wxLogError("Unable to parse file header %s", file);	return false;
	}
	for (int c=0; c<NumCells; c++){
		int cellid,np;
		if( fscanf(fp, "#Cell: %d, pointCount: %d\n", &cellid, &np) !=2 ) {
			wxLogError("Unable to parse file %s for cell %d header %s", file, c+1);	return false;
		}
		for (int j=0; j<frameCount && j<FrameCount; j++) {
			std::vector<wxPoint> roi(np);
			for (int i=0; i<np; i++){
				if( fscanf(fp, "%d %d", &roi[i].x, &roi[i].y) !=2 ) {
					wxLogError("Unable to parse file %s for cell %d coordinates", file, c+1);	return false;
				}
			}
			book[j]->AddRoi(roi);
		}
	}
	fclose(fp);
	this->ReloadCurrentFrameContours();
	return true;
}

bool CaptureManager::SaveTrajectoryData(const char* file) {
	FILE *fp;
	if(!SaveData_setup(file,fp)) return false;

	int numContours=book[0]->contourArray.size();
	fprintf(fp, "#width: %d, height: %d, frameCount: %d, fps: %d\n", size.width, size.height, frameCount, numContours, fps);
	fprintf(fp, "#cellCount: %d\n", numContours);
	for (int c=0; c<numContours; c++){
		CvSeq *oseq = book[0]->contourArray[c];
		int np = oseq->total;
		fprintf(fp, "#Cell: %d, pointCount: %d\n", c+1, np);
		std::vector<CvPoint> traj = GetTrajectory(c);
		for (int i=0; i<traj.size(); i++){
			fprintf(fp, "%d\t%d\n", traj[i].x, traj[i].y);
		}
	}
	fclose(fp);
	return true;
}
bool CaptureManager::SaveSpeedData(const char* file) {
	FILE *fp;
	if(!SaveData_setup(file,fp)) return false;

	int numContours=book[0]->contourArray.size();
	fprintf(fp, "#width: %d, height: %d, frameCount: %d, fps: %d\n", size.width, size.height, frameCount, numContours, fps);
	fprintf(fp, "#cellCount: %d\n", numContours);
	for (int c=0; c<numContours; c++){
		CvSeq *oseq = book[0]->contourArray[c];
		int np = oseq->total;
		float totalDisp, avgSpeed;
		std::vector<float> speeds = GetSpeeds(c, totalDisp, avgSpeed);

		fprintf(fp, "#Cell: %d, pointCount: %d, totalDistance: %f, avgSped: %f\n", c+1, np, totalDisp, avgSpeed);
		for (int i=0; i<speeds.size(); i++){
			fprintf(fp, "%f\n", speeds[i]);
		}
	}
	fclose(fp);
	return true;
}
bool CaptureManager::SaveAreaData(const char* file) {
	FILE *fp;
	if(!SaveData_setup(file,fp)) return false;

	int numContours=book[0]->contourArray.size();
	fprintf(fp, "#width: %d, height: %d, frameCount: %d, fps: %d\n", size.width, size.height, frameCount, numContours, fps);
	fprintf(fp, "#cellCount: %d\n", numContours);
	for (int c=0; c<numContours; c++){
		CvSeq *oseq = book[0]->contourArray[c];
		int np = oseq->total;
		float avgArea;
		std::vector<float> areas = GetAreas(c, avgArea);

		fprintf(fp, "#Cell: %d, pointCount: %d, avgArea: %f\n", c+1, np, avgArea);
		for (int i=0; i<areas.size(); i++){
			fprintf(fp, "%f\n", areas[i]);
		}
	}
	fclose(fp);
	return true;
}
bool CaptureManager::SaveDeformationData(const char* file) {
	FILE *fp;
	if(!SaveData_setup(file,fp)) return false;

	int numContours=book[0]->contourArray.size();
	fprintf(fp, "#width: %d, height: %d, frameCount: %d, fps: %d\n", size.width, size.height, frameCount, numContours, fps);
	fprintf(fp, "#cellCount: %d\n", numContours);
	for (int c=0; c<numContours; c++){
		CvSeq *oseq = book[0]->contourArray[c];
		int np = oseq->total;
		float avgDef;
		std::vector<float> defs = GetDeformation(c, avgDef);

		fprintf(fp, "#Cell: %d, pointCount: %d, avgDeformation: %f\n", c+1, np, avgDef);
		for (int i=0; i<defs.size(); i++){
			fprintf(fp, "%f\n", defs[i]);
		}
	}
	fclose(fp);
	return true;
}

#include <wx/bitmap.h>
#include <wx/dc.h>
bool CaptureManager::SaveTrackImage(wxBitmap &bmp) {
	if (!book[0]->contourArray.size()){
		wxLogError("No objects in the first frame. Detect/draw boundaries in the first frame and apply tracking first.");
		return false;
	}
	wxRealPoint scale(6,6);
	bmp.Create(scale.x*size.width,scale.y*size.height);
	wxMemoryDC dc(bmp);
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	for (int c=0; c<book[0]->contourArray.size(); c++){
		CvSeq *oseq = book[0]->contourArray[c];
		MyCanvas::DrawContour_static(&dc, oseq,wxPoint(0,0),scale);
		for (int i=0; i<oseq->total; i++){
			CvPoint *lastLoc = (CvPoint*) cvGetSeqElem(oseq, i);
			dc.SetPen(wxPen(wxColour(Preferences::GetColorContourCornerColor())));
			dc.SetBrush(*wxTRANSPARENT_BRUSH);
			for (int j=1; j<frameCount; j++){
				if(book[j]->contourArray.size() <= c || book[j]->contourArray[c]->total <= i)
					continue;
				CvPoint *p = (CvPoint*) cvGetSeqElem(book[j]->contourArray[c], i);
				dc.DrawLine(scale.x*lastLoc->x,scale.y*lastLoc->y, scale.x*p->x,scale.y*p->y);
				lastLoc = p;
			}
			dc.DrawCircle(MyPoint((CvPoint*)cvGetSeqElem(book[0]->contourArray[c],i))*scale, Preferences::GetColorContourCornerWidth());
			dc.SetBrush(*wxRED_BRUSH);
			dc.SetPen(wxPen(*wxRED));
			for (int j=1; j<frameCount; j++){
				if(book[j]->contourArray.size() <= c || book[j]->contourArray[c]->total <= i)
					continue;
				CvPoint *p = (CvPoint*) cvGetSeqElem(book[j]->contourArray[c], i);
				dc.DrawCircle(MyPoint(*p)*scale, Preferences::GetColorContourCornerWidth());
			}
		}
		if(c < book[frameCount-1]->contourArray.size())
			MyCanvas::DrawContour_static(&dc, book[frameCount-1]->contourArray[c],wxPoint(0,0),scale, true, wxRED);
	}
	return true;
}
bool CaptureManager::SaveTrajectoryImage(wxBitmap &bmp) {
	if (!book[0]->contourArray.size()){
		wxLogError("No objects in the first frame. Detect/draw boundaries in the first frame and apply tracking first.");
		return false;
	}
	wxRealPoint scale(6,6);
	CvPoint lastLoc;
	bmp.Create(scale.x*size.width,scale.y*size.height);
	wxMemoryDC dc(bmp);
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	for (int c=0; c<book[0]->contourArray.size(); c++){
		std::vector<CvPoint> traj = GetTrajectory(c);
		lastLoc = traj[0];
		MyCanvas::DrawContour_static(&dc, book[0]->contourArray[c],wxPoint(0,0),scale);
		dc.SetBrush(*wxTRANSPARENT_BRUSH);
		for (int i=1; i<traj.size(); i++){
			if(traj[i].x<0)
				continue;
			if (i>0){
				dc.SetPen(wxPen(wxColour(Preferences::GetColorContourBorderColor()), Preferences::GetColorContourBorderWidth()));
				dc.DrawLine(scale.x*lastLoc.x,scale.y*lastLoc.y, scale.x*traj[i].x,scale.y*traj[i].y);
			}
			lastLoc = traj[i];
		}
		dc.SetBrush(wxBrush(wxColour(Preferences::GetColorContourCornerColor())));
		dc.SetPen(wxPen(wxColour(Preferences::GetColorContourCornerColor())));
		for (int i=0; i<traj.size(); i++){
			if(traj[i].x<0)
				continue;
			dc.DrawCircle(MyPoint(traj[i])*scale, 2*Preferences::GetColorContourCornerWidth());
		}
		dc.SetBrush(*wxRED_BRUSH);
		dc.SetPen(wxPen(*wxRED));
		if(traj[frameCount-1].x>=0){
			dc.DrawCircle(MyPoint(traj[frameCount-1])*scale, 2*Preferences::GetColorContourCornerWidth());
			MyCanvas::DrawContour_static(&dc, book[frameCount-1]->contourArray[c],wxPoint(0,0),scale, true, wxRED);
		}
	}
	return true;
}
void CaptureManager::Resize(int width, int height, int method){
	if (MyPoint(width,height) == MyPoint(size))
		return;
	size = cvSize(width,height);
	for (int i=0; i<frameCount; i++){
		book[i]->Resize(width, height, method);
	}
	ReloadCurrentFrame();
}
void CaptureManager::Crop(CvPoint topleft, CvSize size_){
	if (size.width == 0)
		return;
	for (int i=0; i<frameCount; i++){
		book[i]->Crop(topleft, size_);
	}
	size = cvSize(size_.width, size_.height);
	ReloadCurrentFrame();
}