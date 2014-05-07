#include "LKContoursPlugin.h"
#include "Util.h"

LKContoursPlugin::LKContoursPlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true, true),
gray(NULL), ogray(NULL), pyr(NULL), opyr(NULL), avgLost(0)
{
	sidebar =  new LKContoursSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void LKContoursPlugin::ReleaseTemps()
{
	if (gray) cvReleaseImage(&gray);
	if (ogray) cvReleaseImage(&ogray);
	if (pyr) cvReleaseImage(&pyr);
	if (opyr) cvReleaseImage(&opyr);
}
int LKContoursPlugin::GetScope() {	return sidebar->scope->GetSelection(); }
bool LKContoursPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void LKContoursPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img, cm->GetPos());
	cm->Redraw(false);
	ShowProcessInfo();
}
void LKContoursPlugin::OnOK()
{
	wxBeginBusyCursor();
	if (!GetScope()){
		ProcessImage(cm->book[cm->GetPos()], cm->GetPos());
		ShowProcessInfo();
	}
	else{
		FetchParams();
		CvPoint *ops=NULL;
		CvPoint2D32f *opsf=NULL, *psf=NULL,*swap_psf=NULL; 
		char *status=NULL;
		int np_total=0;
		ImagePlus *oimg=cm->book[0], *img;
		IplImage *swap;
		int flags=0;
		CreateProgressDlg();
		for (int i=1; i<cm->GetFrameCount() && UpdateProgressDlg(i); i++){
			img = cm->book[i];
			LKContoursPlugin::ProcessStatic(img, oimg, level, winsize, criteria, flags, fixOutliers, intwin, avgLost, gray,ogray,pyr,opyr,ops,psf,opsf,status,useAvailable,np_total,false,i==cm->GetFrameCount()-1);
			flags |= CV_LKFLOW_PYR_A_READY;
			CV_SWAP( ogray, gray, swap );
			CV_SWAP( opyr, pyr, swap );
			CV_SWAP( opsf, psf, swap_psf);
		}
		DestroyProgressDlg();
	}
	cm->ReloadCurrentFrameContours(true, false);
	wxEndBusyCursor();
}
void LKContoursPlugin::FetchParams(){
	level=sidebar->level->GetValue();
	winsize=cvSize(2*sidebar->width->GetValue()-1, 2*sidebar->height->GetValue()-1);
	criteria=cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, sidebar->max_iter->GetValue(), sidebar->epsilon->GetValue());
	fixOutliers = (sidebar->fixOutliers->GetValue() ? sidebar->outliers->GetValue() : 0);
	intwin = sidebar->intwin->GetValue();
	useAvailable = sidebar->useAvailable->GetValue();
}
void LKContoursPlugin::ProcessImage( ImagePlus *img, int pos ){
	if (pos==0)
		return;
	FetchParams();
	ImagePlus *oimg = cm->book[pos-1];
	CvPoint *ops=NULL;
	CvPoint2D32f *opsf=NULL, *psf=NULL; 
	char *status=NULL;
	int np_total=0;
	LKContoursPlugin::ProcessStatic(img, oimg, level, winsize, criteria, 0, fixOutliers, intwin, avgLost, gray,ogray,pyr,opyr,ops,psf,opsf,status,useAvailable,np_total,true,true);
}
void LKContoursPlugin::ShowProcessInfo()
{
	win->SetStatusText(WXFORMAT("tracked %.2f%%, interpolated %.2f%% points.", 1-avgLost, avgLost));
}
//temp images are create on demand. must be freed by user (or use free_temps=true)
void LKContoursPlugin::ProcessStatic(ImagePlus *img, ImagePlus *oimg, int level, CvSize winsize, CvTermCriteria criteria, int flags, float fixOutliers, int intwin, float &avgLost, IplImage* &gray, IplImage* &ogray, IplImage* &pyr, IplImage* &opyr, CvPoint* &ops, CvPoint2D32f* &psf, CvPoint2D32f* &opsf, char* &status, bool useAvailable, int &np_total, bool rebuild_opsf, bool free_temps){
	if (!gray)
		gray = cvCreateImage( cvSize(img->orig->width, img->orig->height), IPL_DEPTH_8U, 1 );
	if (!ogray)
		ogray = cvCreateImage( cvSize(img->orig->width, img->orig->height), IPL_DEPTH_8U, 1 );
	if (!pyr)
		pyr = cvCreateImage( cvSize(img->orig->width, img->orig->height), IPL_DEPTH_8U, 1 );
	if (!opyr)
		opyr = cvCreateImage( cvSize(img->orig->width, img->orig->height), IPL_DEPTH_8U, 1 );

	avgLost=0;
	if (useAvailable)
		img->RemoveContours(oimg->contourArray.size(), img->contourArray.size()-1);
	else
		img->RemoveAllContours();
	cvCvtColor(img->orig, gray, CV_BGR2GRAY);
	int numContours = (int) oimg->contourArray.size();
	int np_max=0;
	if (!(flags & CV_LKFLOW_PYR_A_READY)) {
		cvCvtColor(oimg->orig, ogray, CV_BGR2GRAY);
		np_total=0;
		for (int i=0; i<numContours; i++){
			int np = oimg->contourArray[i]->total;
			np_total+= (np + oimg->feats[i].size());
			np_max = MAX(np, np_max);
		}
		ops = (CvPoint*)malloc( np_max*sizeof(CvPoint) );
		opsf = (CvPoint2D32f*)malloc( np_total*sizeof(CvPoint2D32f) );
		psf = (CvPoint2D32f*)malloc( np_total*sizeof(CvPoint2D32f) );
		status = (char *)malloc(np_total*sizeof(char));
	}
	if (!np_total)
		return;

	if (!(flags & CV_LKFLOW_PYR_A_READY) || rebuild_opsf){
		for (int i=0, j=0; i<numContours; i++){
			CvSeq *seq = oimg->contourArray[i];
			int np = seq->total, nf=oimg->feats[i].size();
			cvCvtSeqToArray(seq, ops);
			for (int k=0; k<np; k++, j++)
				opsf[j] = cvPointTo32f(ops[k]);
			for(int k=0; k<nf; k++, j++)
				opsf[j] = oimg->feats[i][k];
		}
	}
	if (useAvailable){
		for (int i=0, j=0; i<numContours; i++){
			CvSeq *seq = i<(int)img->contourArray.size() ? img->contourArray[i] : NULL;
			if (!seq || seq->total != oimg->contourArray[i]->total || img->feats[i].size() != oimg->feats[i].size()){
				int np = oimg->contourArray[i]->total, nf=oimg->feats[i].size();
				memcpy(&(psf[j]), &(opsf[j]), (np+nf)*sizeof(CvPoint2D32f));
				j+=(np+nf);
			}
			else{
				int np = seq->total, nf=img->feats[i].size();
				cvCvtSeqToArray(seq, ops);
				for (int k=0; k<np; k++, j++)
					psf[j] = cvPointTo32f(ops[k]);
				for(int k=0; k<nf; k++, j++)
					psf[j] = img->feats[i][k];
			}
		}
		flags |= CV_LKFLOW_INITIAL_GUESSES;
	}
	cvCalcOpticalFlowPyrLK( ogray, gray, opyr, pyr,
		opsf, psf, np_total, winsize, level, status, NULL,
		criteria, flags );

	for (int i=0, j=0; i<numContours; i++){
		int np = oimg->contourArray[i]->total;
		int nf = oimg->feats[i].size();
		avgLost+=InterpolateTracking(opsf+j,psf+j,np,nf,status, fixOutliers, intwin);
		for (int k=0; k<np+nf; k++){
			psf[k].x = MAX(0, MIN(psf[k].x, gray->width));
			psf[k].y = MAX(0, MIN(psf[k].y, gray->height));
		}
		if (useAvailable && i<img->contourArray.size()){
			img->ReplaceContour(i,&(psf[j]), np);
		}
		else{
			img->AddContour(&(psf[j]), np);
		}
		img->AddFeats(i, &(psf[j+np]), nf);
		j+= (np+nf);
	}
	avgLost /= np_total;
	if (free_temps){
		free(ops); ops=NULL;
		free(opsf); opsf=NULL;
		free(psf); psf=NULL;
		free(status); status=NULL;
	}
}

float LKContoursPlugin::GetStdDevSqDist(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, float avg, char *status, float *sqdists)
{
	int n=0;
	float stdev=0;
	float dx,dy,d;
	for(int i=0; i<np; i++){
		if (status && !status[i])
			continue;
		n++;
		if (!sqdists){
			dx=psf[i].x-opsf[i].x;
			dy=psf[i].y-opsf[i].y;
			d = sqrt(dx*dx + dy*dy);
//			d = dx*dx + dy*dy;
		}
		else
			d = sqdists[i];
		stdev += (d-avg)*(d-avg);
	}
	return sqrt ((float)( stdev / (n ? n : 1) ));

}
//Average displacement distance
float LKContoursPlugin::GetAvgSqDist(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, char *status, float *sqdists)
{
	int n=0;
	float avgsqdist=0;
	float dx,dy,d;
	for(int i=0; i<np; i++){
		if (status && !status[i])
			continue;
		n++;
		dx=psf[i].x-opsf[i].x;
		dy=psf[i].y-opsf[i].y;
		d = sqrt(dx*dx + dy*dy);
//		d = dx*dx + dy*dy;
		avgsqdist+=d;
		if (sqdists)
			sqdists[i]=d;
	}
	return avgsqdist / (n ? n : 1);
}
//Average displacement
CvPoint2D32f LKContoursPlugin::GetAvgDisp(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, char *status)
{
	int n=0;
	CvPoint2D32f avgdisp=cvPoint2D32f(0,0);
	for(int i=0; i<np; i++){
		if (status && !status[i])
			continue;
		n++;
		avgdisp.x += (psf[i].x-opsf[i].x);
		avgdisp.y += (psf[i].y-opsf[i].y);
	}
	avgdisp.x /= (n ? n : 1);
	avgdisp.y /= (n ? n : 1);
	return avgdisp;
}
#include <queue>
#include <vector>
//Estimate local/adaptive average displacements for lost points.
void LKContoursPlugin::GetRunningAvgDisp( CvPoint2D32f* opsf, CvPoint2D32f* psf, int np, char* status, int intwin, bool intwin_checkall, CvPoint2D32f* avgDisps, float fixOutliers)
{
	float dx,dy,d;
	memset(avgDisps, 0, np*sizeof(CvPoint2D32f));
//	for(int tworounds=0; tworounds< (fixOutliers==0 ? 1 : 2); tworounds++)
	for (int i=0; i<np; i++){
		if (status[i] && fixOutliers==0)
			continue;
		std::priority_queue<ScoredIndex, std::vector<ScoredIndex>, ScoredIndexPriority> neighs;
		bool need_neighs=true;
		if (status[i])
			neighs.push(ScoredIndex(0,i));
		for (int k=1; k<np/2 && need_neighs; k++){
			for (int kk=0; kk<2; kk++){
				int j=i+(kk ? 1:-1)*k;
				if (j < 0) j = (j+np)%np;
				if (j < 0) j = 0;
				if (j > np-1) j %= np;
				if (!status[j])
					continue;
				dx=opsf[j].x-opsf[i].x;
				dy=opsf[j].y-opsf[i].y;
				d = dx*dx + dy*dy;
				if(neighs.size() == intwin && (neighs.top().score>d))
					neighs.pop();
				if(neighs.size() < intwin)
					neighs.push(ScoredIndex(d,j));
				if( intwin_checkall && k>=intwin && neighs.size() >= intwin){
					need_neighs=false;
					break;
				}
			}
		}
		avgDisps[i]=cvPoint2D32f(0,0);
		int numNeighs=neighs.size();
		std::vector<ScoredIndex> ns;
		while(neighs.size()) {
			ScoredIndex si = neighs.top();
			ns.push_back(si);
			neighs.pop();
			int j = si.index;
			dx=psf[j].x-opsf[j].x;
			dy=psf[j].y-opsf[j].y;
			avgDisps[i].x += dx;
			avgDisps[i].y += dy;
		}
		if (numNeighs){
			avgDisps[i].x /= numNeighs;
			avgDisps[i].y /= numNeighs;
			//status[i]=0;
			/*
			if (status[i] && fixOutliers!=0){
				float stdevx=0, stdevy=0;
				for (int p=0; p<numNeighs; p++){
					int j = ns[p].index;
					dx=psf[j].x-opsf[j].x;
					dy=psf[j].y-opsf[j].y;
					stdevx += (dx-avgDisps[i].x)*(dx-avgDisps[i].x);
					stdevy += (dy-avgDisps[i].y)*(dy-avgDisps[i].y);
				}
				stdevx = fixOutliers*sqrt(stdevx / numNeighs);
				stdevy = fixOutliers*sqrt(stdevy / numNeighs);
				dx=psf[i].x-opsf[i].x;
				dy=psf[i].y-opsf[i].y;
				if (dx-avgDisps[i].x >stdevx || dy-avgDisps[i].y>stdevy)
					status[i]=0;
			}
			*/
		}
	}
}

//fix outliers using standard deviation of shift.
//interpolate lost points using mean-shift of those not lost
//return: number of interpolations.
// (example use in LKContoursPlugin)
int LKContoursPlugin::InterpolateTracking(CvPoint2D32f *opsf, CvPoint2D32f *psf, int np, int nf, char *status, float fixOutliers, int intwin)
{
	int i,numLost=0,npnf=np+nf;
	bool statusowned=false;
	if (status)	for (i=0; i<npnf; i++){
		if(!status[i])
			numLost++;
	}
	if (!numLost && !fixOutliers)
		return 0;
	if (!status){
		status = (char *)malloc(npnf*sizeof(char));
		memset(status, 1, npnf*sizeof(char));
		statusowned=true;
	}

	if (fixOutliers) {
		//Calculate outliers using displacement distance.
		float *sqdists = (float *)malloc(npnf * sizeof(float)); //displacement distances
		float avgsqdist = GetAvgSqDist(opsf,psf,npnf,status,sqdists);
		float stdev3 = fixOutliers * GetStdDevSqDist(opsf,psf,npnf,avgsqdist,status,sqdists);
		for(int i=0; i<npnf; i++){
			if (!status[i])
				continue;
			if (fabs(sqdists[i] - avgsqdist) > stdev3)
				status[i]=0;
		}
		free (sqdists); sqdists=NULL;
	}

	numLost=0;
	if (intwin){
		CvPoint2D32f *avgdisps = (CvPoint2D32f *)malloc(npnf * sizeof(CvPoint2D32f));
		GetRunningAvgDisp(opsf,psf,npnf,status,intwin,nf!=0,avgdisps,fixOutliers);
		for(i=0; i<npnf; i++){
			if (!status[i]){
				psf[i].x = opsf[i].x + avgdisps[i].x;
				psf[i].y = opsf[i].y + avgdisps[i].y;
				status[i]=1;
				numLost++;
			}
		}
		free(avgdisps); avgdisps=NULL;
	}
	else{
		//Fill-in missing values using average displacement in x/y directions.
		CvPoint2D32f avgdisp = GetAvgDisp(opsf,psf,npnf,status);
		for(i=0; i<npnf; i++){
			if (!status[i]){
				psf[i].x = opsf[i].x + avgdisp.x;
				psf[i].y = opsf[i].y + avgdisp.y;
				status[i]=1;
				numLost++;
			}
		}
	}
	if(statusowned){
		free(status); status=NULL;
	}
	return numLost;
}