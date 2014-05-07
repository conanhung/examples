#include "CombinedTrackingPlugin.h"
#include "Util.h"

CombinedTrackingPlugin::CombinedTrackingPlugin( wxWindow* parent_, MyFrame *win_ )
: PluginBase(GetStaticName(), parent_, win_, true, true, true),
gray(NULL), edge(NULL), mt_map(NULL),
cs_backproject(NULL), cs_hist(NULL), cs_rotation(NULL), cs_shift(NULL), cs_planes(NULL),
lk_gray(NULL), lk_ogray(NULL), lk_pyr(NULL), lk_opyr(NULL), lk_avgLost(0),
as_gray(NULL), as_ogray(NULL), as_avgiterations(0), Earc(NULL), Earc_ready(false)
{
	sidebar =  new CombinedTrackingSidebar(parent_, this);
	sidebarw = sidebar;
	DoPreview();
}
void CombinedTrackingPlugin::ReleaseTemps()
{
	if (gray) cvReleaseImage(&gray);
	if (edge) cvReleaseImage(&edge);
	if (mt_map) cvReleaseImage(&mt_map);

	if (cs_backproject) cvReleaseImage(&cs_backproject);
	if (cs_hist) cvReleaseHist(&cs_hist);
	if (cs_planes){
		for (int p=0; p<3; p++){
			if (cs_planes[p])
				cvReleaseImage(&cs_planes[p]);
		}
		free(cs_planes); cs_planes=NULL;
	}
	if (cs_rotation) cvReleaseMat(&cs_rotation);
	if (cs_shift) cvReleaseMat(&cs_shift);

	if (lk_gray) cvReleaseImage(&lk_gray);
	if (lk_ogray) cvReleaseImage(&lk_ogray);
	if (lk_pyr) cvReleaseImage(&lk_pyr);
	if (lk_opyr) cvReleaseImage(&lk_opyr);

	if (as_gray) cvReleaseImage(&as_gray);
	if (as_ogray) cvReleaseImage(&as_ogray);
}
int CombinedTrackingPlugin::GetScope() {	return sidebar->scope->GetSelection(); }
bool CombinedTrackingPlugin::IsPreviewOn(){ return sidebar->preview->GetValue(); }
void CombinedTrackingPlugin::FetchParams()
{
	useMT=useCS=false;
	if(sidebar->initial_method->GetSelection()==1)
		useMT=true;
	else if(sidebar->initial_method->GetSelection()==2)
		useCS=true;
	useLK=sidebar->useLK->GetValue();
	useAS=sidebar->useAS->GetValue();
	useNC=sidebar->useNC->GetValue();

	const static int mt_METHOD_MAP[] = {CV_TM_SQDIFF, CV_TM_SQDIFF_NORMED, CV_TM_CCORR, CV_TM_CCORR_NORMED, CV_TM_CCOEFF, CV_TM_CCOEFF_NORMED};
	mt_method = mt_METHOD_MAP[sidebar->mt_method->GetSelection()];
	mt_winsize = cvSize(2*sidebar->mt_width->GetValue()-1, 2*sidebar->mt_height->GetValue()-1);
	mt_useFirst = sidebar->mt_useFirst->GetValue();


	for (int p=0; p<3; p++)
		cs_hsizes[p] = sidebar->cs_hsize->GetValue();
	cs_criteria = cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, sidebar->cs_max_iter->GetValue(), sidebar->cs_epsilon->GetValue());
	cs_useFirst = sidebar->cs_useFirst->GetValue();

	lk_level=sidebar->lk_level->GetValue();
	lk_winsize=cvSize(2*sidebar->lk_width->GetValue()-1, 2*sidebar->lk_height->GetValue()-1);
	lk_criteria=cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, sidebar->lk_max_iter->GetValue(), sidebar->lk_epsilon->GetValue());
	lk_fixOutliers = (sidebar->lk_fixOutliers->GetValue() ? sidebar->lk_outliers->GetValue() : 0);
	lk_intwin = sidebar->lk_intwin->GetValue();
	lk_useAvailable = useMT || useCS || sidebar->lk_useAvailable->GetValue();

	as_alpha = sidebar->as_alpha->GetValue();
	as_beta = sidebar->as_beta->GetValue();
	as_gamma = sidebar->as_gamma->GetValue();
	as_oalpha = sidebar->as_oalpha->GetValue();
	as_obeta = sidebar->as_obeta->GetValue();
	as_ogamma = sidebar->as_ogamma->GetValue();
	as_oteta = sidebar->as_oteta->GetValue();
	as_ozeta = sidebar->as_ozeta->GetValue();
	as_oomega = sidebar->as_oomega->GetValue();
	as_useAvailable = useMT || useCS || useLK || sidebar->as_useAvailable->GetValue();
	as_winsize = cvSize(2*sidebar->as_width->GetValue()-1, 2*sidebar->as_height->GetValue()-1);
	as_scheme = sidebar->as_gradient->GetValue();
	as_criteria = cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, sidebar->as_max_iter->GetValue(), sidebar->as_epsilon->GetValue());

	nc_minLength = sidebar->nc_isMinLength->GetValue() ? sidebar->nc_minLength->GetValue() : 0;
	nc_maxLength = sidebar->nc_isMaxLength->GetValue(), sidebar->nc_maxLength->GetValue();
}

void CombinedTrackingPlugin::DoPreview()
{
	if (!IsPreviewOn())
		return;
	cm->ReloadCurrentFrameContours(false);
	ProcessImage(&cm->img, cm->GetPos());
	cm->Redraw(false);
}
void CombinedTrackingPlugin::OnOK()
{
//	Earc_ready = true;
	PluginBase::OnOK();
	Earc_ready = false;
	if (Earc){
		free(Earc);
		Earc = NULL;
	}
}
#include <vector>
#include "MatchTemplatePlugin.h"
#include "CamShiftPlugin.h"
#include "LKContoursPlugin.h"
#include "TrackContoursPlugin.h"
#include "NormalizeContoursPlugin.h"
void CombinedTrackingPlugin::ProcessImage( ImagePlus *img, int pos ){
	if (pos==0)
		return;
	FetchParams();

	if (useMT){
		ImagePlus *oimg = cm->book[mt_useFirst ? 0 : pos-1];
		int numContours = (int) oimg->contourArray.size();
		img->CloneContours(oimg);
		for (int i=0; i<numContours; i++){
			MatchTemplatePlugin::ProcessStatic(i, img, oimg, mt_method, mt_winsize, mt_map);
		}
	}
	else if (useCS){
		CvRect orect, searchwin;
		CvPoint ocenter;
		ImagePlus *oimg = cm->book[cs_useFirst ? 0 : pos-1];
		int numContours = (int) oimg->contourArray.size();
		img->CloneContours(oimg);
		for (int i=0; i<numContours; i++)
			CamShiftPlugin::ProcessStatic(i, img, oimg, cs_hsizes, cs_criteria,
	cs_planes, cs_hist, cs_backproject, orect, ocenter, searchwin, cs_rotation, cs_shift, false);
	}

	if (useLK){
		ImagePlus *oimg = cm->book[pos-1];
		CvPoint *ops=NULL;
		CvPoint2D32f *opsf=NULL, *psf=NULL; 
		char *status=NULL;
		int np_total=0;
		LKContoursPlugin::ProcessStatic(img, oimg, lk_level, lk_winsize, lk_criteria, 0, lk_fixOutliers, lk_intwin, lk_avgLost, lk_gray,lk_ogray,lk_pyr,lk_opyr,ops,psf,opsf,status,lk_useAvailable,np_total,true,true);
	}

	if (useAS){
		ImagePlus *oimg = cm->book[pos-1];
		as_avgiterations=0;
		int numContours = (int) oimg->contourArray.size();
		if (as_useAvailable)
			img->RemoveContours(numContours, (int)img->contourArray.size()-1);
		else
			img->CloneContours(oimg);
		for (int i=0; i<numContours; i++){
			CvPoint *ps, *ops;
			int iterations=0;
			TrackContoursPlugin::ProcessStatic(i, img, oimg, as_gray, as_ogray, ps, ops, as_alpha, as_beta, as_gamma, as_oalpha, as_obeta, as_ogamma, as_oteta, as_ozeta, as_oomega, as_winsize, as_scheme, as_criteria, true, iterations,  false, true, Earc, Earc_ready);
			as_avgiterations+=iterations;
		}
		if (numContours)
			as_avgiterations/=numContours;
	}
	if (useNC){
		NormalizeContoursPlugin::ProcessStatic( img, nc_minLength, nc_maxLength );
	}
}
