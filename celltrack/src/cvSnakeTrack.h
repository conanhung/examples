#include <cv.h>
#include <cxcore.h>
#include <cvaux.h>
#include <highgui.h>

#ifndef cvUnsupportedFormat  //if so, cxmisc.h is not included..
#define cvUnsupportedFormat "Unsupported format"
/* IPP-compatible return codes */
typedef enum CvStatus
{         
    CV_BADMEMBLOCK_ERR          = -113,
    CV_INPLACE_NOT_SUPPORTED_ERR= -112,
    CV_UNMATCHED_ROI_ERR        = -111,
    CV_NOTFOUND_ERR             = -110,
    CV_BADCONVERGENCE_ERR       = -109,

    CV_BADDEPTH_ERR             = -107,
    CV_BADROI_ERR               = -106,
    CV_BADHEADER_ERR            = -105,
    CV_UNMATCHED_FORMATS_ERR    = -104,
    CV_UNSUPPORTED_COI_ERR      = -103,
    CV_UNSUPPORTED_CHANNELS_ERR = -102,
    CV_UNSUPPORTED_DEPTH_ERR    = -101,
    CV_UNSUPPORTED_FORMAT_ERR   = -100,

    CV_BADARG_ERR      = -49,  //ipp comp
    CV_NOTDEFINED_ERR  = -48,  //ipp comp

    CV_BADCHANNELS_ERR = -47,  //ipp comp
    CV_BADRANGE_ERR    = -44,  //ipp comp
    CV_BADSTEP_ERR     = -29,  //ipp comp

    CV_BADFLAG_ERR     =  -12,
    CV_DIV_BY_ZERO_ERR =  -11, //ipp comp
    CV_BADCOEF_ERR     =  -10,

    CV_BADFACTOR_ERR   =  -7,
    CV_BADPOINT_ERR    =  -6,
    CV_BADSCALE_ERR    =  -4,
    CV_OUTOFMEM_ERR    =  -3,
    CV_NULLPTR_ERR     =  -2,
    CV_BADSIZE_ERR     =  -1,
    CV_NO_ERR          =   0,
    CV_OK              =   CV_NO_ERR
}
CvStatus;
#endif

CVAPI(void)
cvSnakeImageTrack( const IplImage* src, CvPoint* points, int length,
		  float *alpha, float *beta, float *gamma,
		  const IplImage* orig,
		  CvPoint *opoints,
		  float *oalpha, float *obeta, float *ogamma, float *oteta, float *ozeta, float *oomega,
		  int coeffUsage, CvSize win,
		  CvTermCriteria criteria, int calcGradient CV_DEFAULT(1),
	   float *oEarc_static = NULL, bool oEarc_static_ready = false,
		int *iterations = NULL);

