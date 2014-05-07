#include "CamShiftPlugin.h"
#include "Util.h"

CamShiftPlugin::CamShiftPlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true,true),
backproject(NULL), hist(NULL), rotation(NULL), shift(NULL), planes(NULL)
{
	sidebar =  new CamShiftSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void CamShiftPlugin::ReleaseTemps()
{
	if (backproject) cvReleaseImage(&backproject);
	if (hist) cvReleaseHist(&hist);
	if (planes){
		for (int p=0; p<3; p++){
			if (planes[p])
				cvReleaseImage(&planes[p]);
		}
		free(planes); planes = NULL;
	}
	if (rotation) cvReleaseMat(&rotation);
	if (shift) cvReleaseMat(&shift);
}
int CamShiftPlugin::GetScope() {	return sidebar->scope->GetSelection() ? 1 : 0; }
bool CamShiftPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void CamShiftPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img, cm->GetPos());
	cm->Redraw(false);
}
void CamShiftPlugin::FetchParams()
{
	for (int p=0; p<3; p++)
		hsizes[p] = sidebar->hsize->GetValue();
	criteria = cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, sidebar->max_iter->GetValue(), sidebar->epsilon->GetValue());
	useFirst = sidebar->useFirst->GetValue();
}

void CamShiftPlugin::ProcessImage( ImagePlus* img, int pos )
{
	if (pos==0)
		return;
	FetchParams();
	ImagePlus *oimg = cm->book[useFirst ? 0 : pos-1];
	CvRect orect, searchwin;
	CvPoint ocenter;

	img->CloneContours(oimg);
	int numContours = (int) oimg->contourArray.size();
	for (int i=0; i<numContours; i++){
		ProcessStatic(i, img, oimg, hsizes, criteria,
planes, hist, backproject, orect, ocenter, searchwin, rotation, shift, false);
	}
}
void CamShiftPlugin::OnOK()
{
	wxBeginBusyCursor();
	if (!GetScope())
		ProcessImage(cm->book[cm->GetPos()], cm->GetPos());
	else{
		FetchParams();
		ImagePlus *oimg;
		CvRect orect, searchwin;
		CvPoint ocenter;
		oimg = cm->book[0];
		int numContours = (int) oimg->contourArray.size();
		for (int i=1; i<cm->GetFrameCount(); i++)
			cm->book[i]->CloneContours(oimg);
		int frameCount = cm->GetFrameCount();
		CreateProgressDlg(numContours*frameCount);
		bool cont=true;
		for (int j=0; j<numContours && cont; j++){
			for (int i=1; i<frameCount && (cont=progressDlg->Update(j*frameCount+i, wxString::Format("Cell %d of %d, Frame %d of %d", j+1,numContours, i+1, frameCount))); i++){
				ProcessStatic(j, cm->book[i], cm->book[useFirst ? 0 : i-1], hsizes, criteria,
		planes, hist, backproject, orect, ocenter, searchwin, rotation, shift, i>1);
			}
		}
		DestroyProgressDlg();
	}
	cm->ReloadCurrentFrameContours(true, false);
	wxEndBusyCursor();
}
void CamShiftPlugin::ProcessStatic
( int i, ImagePlus *img, ImagePlus *oimg, int *hsizes, CvTermCriteria criteria,
IplImage** &planes, CvHistogram* &hist, IplImage* &backproject, CvRect &orect, CvPoint &ocenter, CvRect &searchwin, CvMat* &rotation, CvMat* &shift, bool oready){
	if (hist && hist->mat.dim[0].size!=hsizes[0])
		cvReleaseHist(&hist);
	if( !hist )
        hist = cvCreateHist( 3, hsizes, CV_HIST_ARRAY, NULL, 0);
    if( !backproject )
		backproject = cvCreateImage( cvGetSize(img->orig), IPL_DEPTH_8U, 1 );
	if( !planes ){
	    planes = (IplImage**) malloc(3 * sizeof(IplImage*));
        for (int p=0; p<3; p++)
			planes[p] = cvCreateImage( cvGetSize(img->orig), 8, 1 );
	}
	if (!rotation)
		rotation = cvCreateMat(2,3,CV_32FC1);
	if (!shift)
		shift = cvCreateMat(2,1,CV_32FC1);

	if (!oready){
		orect = cvBoundingRect(oimg->contourArray[i],1);
		cvCvtPixToPlane( oimg->orig, planes[0], planes[1], planes[2], 0 );
        for (int p=0; p<3; p++)
            cvSetImageROI(planes[p],orect);
        cvCalcHist( planes, hist, 0, NULL );
		cvNormalizeHist(hist, 255);
        for (int p=0; p<3; p++)
            cvResetImageROI(planes[p]);
		searchwin = orect; //cvRect(0,0,img->orig->width, img->orig->height);
		ocenter = cvPoint(orect.x+orect.width/2, orect.y+orect.height/2);
	}
	//The following checks shouldn't be needed.
	RestrictRect(searchwin, cvRect(0,0,backproject->width,backproject->height));

	cvCvtPixToPlane( img->orig, planes[0], planes[1], planes[2], 0 );
    cvCalcBackProject( planes, backproject, hist );
	CvBox2D track_box;
	CvConnectedComp track_comp;
    cvCamShift( backproject, searchwin,
                criteria,
                &track_comp, &track_box );
	searchwin = track_comp.rect;
	cvmSet(shift,0,0,track_box.center.x - ocenter.x);
	cvmSet(shift,1,0,track_box.center.y - ocenter.y);
//	shift->data.fl[0] = track_box.center.x - ocenter.x;
//	shift->data.fl[1] = track_box.center.y - ocenter.y;
	cv2DRotationMatrix(track_box.center, track_box.angle, 1.0, rotation);
	cvTransform(oimg->contourArray[i],img->contourArray[i],rotation,shift);
//	CvMat *ofm = FeatPointsToMat(oimg->feats[i]);
//	Cvmat *fm  = FeatPointsToMat(img->feats[i]);
//	cvTransform(ofm,img->contourArray[i],rotation,shift);
	TransformFeatPoints(oimg->feats[i], img->feats[i], rotation, shift);
}
