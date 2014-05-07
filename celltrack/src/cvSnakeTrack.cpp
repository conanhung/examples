//Modified from: cvsnakes.cpp
//(C)opyright 2008 Ahmet Sacan
//#include "_cv.h"
#include "cvSnakeTrack.h"

#define _CV_SNAKE_BIG 2.e+38f
#define _CV_SNAKE_IMAGE 1
#define _CV_SNAKE_GRAD  2


/*F///////////////////////////////////////////////////////////////////////////////////////
//    Name:      icvSnakeTrack8uC1R
//    Purpose:
//    Context:
//    Parameters:
//               src - source image,
//               srcStep - its step in bytes,
//               roi - size of ROI,
//               pt - pointer to snake points array
//               n - size of points array,
//               alpha - pointer to coefficient of continuity energy,
//               beta - pointer to coefficient of curvature energy,
//               gamma - pointer to coefficient of image energy,
//               coeffUsage - if CV_VALUE - alpha, beta, gamma point to single value
//                            if CV_MATAY - point to arrays
//               criteria - termination criteria.
//               scheme - image energy scheme
//                         if _CV_SNAKE_IMAGE - image intensity is energy
//                         if _CV_SNAKE_GRAD  - magnitude of gradient is energy
//    Returns:
//F*/

static CvStatus
icvSnakeTrack8uC1R( unsigned char *src,
				   int srcStep,
				   CvSize roi,
				   CvPoint * pt,
				   int n,
				   float *alpha,
				   float *beta,
				   float *gamma,
				   int coeffUsage, CvSize win, CvTermCriteria criteria, int scheme
				   , unsigned char *osrc, //original image where contours are generated.
				   CvPoint *opt,
				    //weights of the original fit
				   float *oalpha, float *obeta, float *ogamma, float *oteta, float *ozeta, float *oomega,
				   IplImage *dux, IplImage *odux, IplImage *duy, IplImage *oduy, 
				   float *oEarc_static = NULL, bool oEarc_static_ready = false,
				   int *iterations = NULL)
{
	int i, j, k;
	int neighbors = win.height * win.width;

	int centerx = win.width >> 1;
	int centery = win.height >> 1;

	float invn;
	int iteration = 0;
	int converged = 0;


	float *E;

	float _alpha=*alpha, _beta=*beta, _gamma=*gamma;

	/*#ifdef GRAD_SNAKE */
	float *gradient = NULL;
	uchar *map = NULL;
	int map_width = ((roi.width - 1) >> 3) + 1;
	int map_height = ((roi.height - 1) >> 3) + 1;
	CvSepFilter pX, pY;
#define WTILE_SIZE 8
#define TILE_SIZE (WTILE_SIZE + 2)
	short dx[TILE_SIZE*TILE_SIZE], dy[TILE_SIZE*TILE_SIZE];
	CvMat _dx = cvMat( TILE_SIZE, TILE_SIZE, CV_16SC1, dx );
	CvMat _dy = cvMat( TILE_SIZE, TILE_SIZE, CV_16SC1, dy );
	CvMat _src = cvMat( roi.height, roi.width, CV_8UC1, src );

	/* inner buffer of convolution process */
	//char ConvBuffer[400];

	/*#endif */


	/* check bad arguments */
	if( src == NULL )
		return CV_NULLPTR_ERR;
	if( osrc == NULL )
		return CV_NULLPTR_ERR;
	if( (roi.height <= 0) || (roi.width <= 0) )
		return CV_BADSIZE_ERR;
	if( srcStep < roi.width )
		return CV_BADSIZE_ERR;
	if( pt == NULL )
		return CV_NULLPTR_ERR;
	if( n < 3 )
		return CV_BADSIZE_ERR;
	if( alpha == NULL )
		return CV_NULLPTR_ERR;
	if( beta == NULL )
		return CV_NULLPTR_ERR;
	if( gamma == NULL )
		return CV_NULLPTR_ERR;
	if( oalpha == NULL )
		return CV_NULLPTR_ERR;
	if( obeta == NULL )
		return CV_NULLPTR_ERR;
	if( ogamma == NULL )
		return CV_NULLPTR_ERR;
	if( oteta == NULL )
		return CV_NULLPTR_ERR;
	if( ozeta == NULL )
		return CV_NULLPTR_ERR;
	if( coeffUsage != CV_VALUE && coeffUsage != CV_ARRAY )
		return CV_BADFLAG_ERR;
	if( (win.height <= 0) || (!(win.height & 1)))
		return CV_BADSIZE_ERR;
	if( (win.width <= 0) || (!(win.width & 1)))
		return CV_BADSIZE_ERR;

	invn = 1 / ((float) n);

	if( scheme == _CV_SNAKE_GRAD )
	{
		pX.init_deriv( TILE_SIZE+2, CV_8UC1, CV_16SC1, 1, 0, 3 );
		pY.init_deriv( TILE_SIZE+2, CV_8UC1, CV_16SC1, 0, 1, 3 );

		gradient = (float *) cvAlloc( roi.height * roi.width * sizeof( float ));
		memset((void*)gradient, 0, roi.height*roi.width*sizeof(float));
		if( !gradient )
			return CV_OUTOFMEM_ERR;
		map = (uchar *) cvAlloc( map_width * map_height );
		if( !map )
		{
			cvFree( &gradient );
			return CV_OUTOFMEM_ERR;
		}
		/* clear map - no gradient computed */
		memset( (void *) map, 0, map_width * map_height );
	}
	E = (float *) cvAlloc( neighbors * sizeof( float ));

	//------------------------- Original Image Parameters ----------------
	float _oalpha=*oalpha, _obeta=*obeta, _ogamma=*ogamma, _oteta=*oteta, _ozeta=*ozeta, _oomega=*oomega;
	CvMat _osrc = cvMat( roi.height, roi.width, CV_8UC1, osrc );
	int roisize=roi.width*roi.width;
#define INIT_ENERGY_TERM(X)	\
	float *X     = (float *) cvAlloc( neighbors * sizeof( float )); \
	float *o##X  = (float *) cvAlloc( n * sizeof( float )); \
	float *os##X = (float *) cvAlloc( n * sizeof( float )); \
	memset(X, 0, neighbors * sizeof(float)); \
	memset(o##X, 0, n * sizeof(float)); \
	memset(os##X, 0, n * sizeof(float));
INIT_ENERGY_TERM(Econt)
INIT_ENERGY_TERM(Ecurv)
INIT_ENERGY_TERM(Eimg)
INIT_ENERGY_TERM(Eint)
INIT_ENERGY_TERM(Earc)
INIT_ENERGY_TERM(Edux)
INIT_ENERGY_TERM(Eduy)
	//------------------------ //End Original Image Parameters
	CvMat *_srcp;
	unsigned char *srcp;
	CvPoint *ppt;
	IplImage *pdux, *pduy;
	for (int isoriginit=0; isoriginit<2; isoriginit++){
		if (!isoriginit){
			ppt=opt;
			_srcp=&_osrc;
			srcp=osrc;
			pdux = odux;
			pduy = oduy;
		}
		else{
			ppt=pt;
			_srcp=&_src;
			srcp=src;
			converged=0;
			iteration=0;
			if( scheme == _CV_SNAKE_GRAD )
				memset( (void *) map, 0, map_width * map_height );
			pdux = dux;
			pduy = duy;
		}


		while( !converged )
		{
			float ave_d = 0;
			int moved = 0;

			converged = 0;
			iteration++;
			/* compute average distance */
			for( i = 1; i < n; i++ )
			{
				int diffx = ppt[i - 1].x - ppt[i].x;
				int diffy = ppt[i - 1].y - ppt[i].y;

				ave_d += cvSqrt( (float) (diffx * diffx + diffy * diffy) );
			}
			ave_d += cvSqrt( (float) ((ppt[0].x - ppt[n - 1].x) *
				(ppt[0].x - ppt[n - 1].x) +
				(ppt[0].y - ppt[n - 1].y) * (ppt[0].y - ppt[n - 1].y)));

			ave_d *= invn;
			/* average distance computed */
			for( i = 0; i < n; i++ )
			{
				float Emin = _CV_SNAKE_BIG;
				float maxEcont = 0, minEcont = _CV_SNAKE_BIG;
				float maxEcurv = 0, minEcurv = _CV_SNAKE_BIG;
				float maxEimg  = 0, minEimg  = _CV_SNAKE_BIG;
				float maxEint  = 0, minEint  = _CV_SNAKE_BIG;
				float maxEarc  = 0, minEarc  = _CV_SNAKE_BIG;
				float maxEdux  = 0, minEdux  = _CV_SNAKE_BIG;
				float maxEduy  = 0, minEduy  = _CV_SNAKE_BIG;

				int offsetx = 0;
				int offsety = 0;
				float tmp, energy;
				int diffx, diffy;

				// compute bounds
				int left = MIN( ppt[i].x, win.width >> 1 );
				int right = MIN( roi.width - 1 - ppt[i].x, win.width >> 1 );
				int upper = MIN( ppt[i].y, win.height >> 1 );
				int bottom = MIN( roi.height - 1 - ppt[i].y, win.height >> 1 );

				// Calculate Econt
				if (!(alpha==0 || oalpha==0)){
					for( j = -upper; j <= bottom; j++ )
					{
						for( k = -left; k <= right; k++ )
						{
							if( i == 0 )
							{
								diffx = ppt[n - 1].x - (ppt[i].x + k);
								diffy = ppt[n - 1].y - (ppt[i].y + j);
							}
							else
							{
								diffx = ppt[i - 1].x - (ppt[i].x + k);
								diffy = ppt[i - 1].y - (ppt[i].y + j);
							}
							Econt[(j + centery) * win.width + k + centerx] = energy =
								(float) fabs( ave_d -
								cvSqrt( (float) (diffx * diffx + diffy * diffy) ));

							maxEcont = MAX( maxEcont, energy );
							minEcont = MIN( minEcont, energy );
						}
					}
					if(isoriginit){
						tmp = maxEcont - minEcont;
						tmp = (tmp == 0) ? 0 : (1 / tmp);
						for( k = 0; k < neighbors; k++ )
							Econt[k] = (Econt[k] - minEcont) * tmp;
						osEcont[i] = (oEcont[i] - minEcont)*tmp;
					}
				}
				//  Calculate Ecurv
				if (!(beta==0 || obeta==0)) {
					for( j = -upper; j <= bottom; j++ )
					{
						for( k = -left; k <= right; k++ )
						{
							int tx, ty;
							if( i == 0 )
							{
								tx = ppt[n - 1].x - 2 * (ppt[i].x + k) + ppt[i + 1].x;
								ty = ppt[n - 1].y - 2 * (ppt[i].y + j) + ppt[i + 1].y;
							}
							else if( i == n - 1 )
							{
								tx = ppt[i - 1].x - 2 * (ppt[i].x + k) + ppt[0].x;
								ty = ppt[i - 1].y - 2 * (ppt[i].y + j) + ppt[0].y;
							}
							else
							{
								tx = ppt[i - 1].x - 2 * (ppt[i].x + k) + ppt[i + 1].x;
								ty = ppt[i - 1].y - 2 * (ppt[i].y + j) + ppt[i + 1].y;
							}
							Ecurv[(j + centery) * win.width + k + centerx] = energy =
								(float) (tx * tx + ty * ty);
							maxEcurv = MAX( maxEcurv, energy );
							minEcurv = MIN( minEcurv, energy );
						}
					}
					if(isoriginit){
						tmp = maxEcurv - minEcurv;
						tmp = (tmp == 0) ? 0 : (1 / tmp);
						for( k = 0; k < neighbors; k++ )
							Ecurv[k] = (Ecurv[k] - minEcurv) * tmp;
						osEcurv[i] = (oEcurv[i] - minEcurv)*tmp;
					}
				}
				// Calculate Eimg
				if (!(gamma==0 || ogamma==0)) {
					for( j = -upper; j <= bottom; j++ )
					{
						for( k = -left; k <= right; k++ )
						{
							if( scheme == _CV_SNAKE_GRAD )
							{
								// look at map and check status 
								int x = (ppt[i].x + k)/WTILE_SIZE;
								int y = (ppt[i].y + j)/WTILE_SIZE;

								if( map[y * map_width + x] == 0 )
								{
									int l, m;

									// evaluate block location
									int upshift = y ? 1 : 0;
									int leftshift = x ? 1 : 0;
									int bottomshift = MIN( 1, roi.height - (y + 1)*WTILE_SIZE );
									int rightshift = MIN( 1, roi.width - (x + 1)*WTILE_SIZE );
									CvRect g_roi = { x*WTILE_SIZE - leftshift, y*WTILE_SIZE - upshift,
										leftshift + WTILE_SIZE + rightshift, upshift + WTILE_SIZE + bottomshift };
									CvMat _src1;
									cvGetSubArr( _srcp, &_src1, g_roi );

									pX.process( &_src1, &_dx );
									pY.process( &_src1, &_dy );

									for( l = 0; l < WTILE_SIZE + bottomshift; l++ )
									{
										for( m = 0; m < WTILE_SIZE + rightshift; m++ )
										{
											gradient[(y*WTILE_SIZE + l) * roi.width + x*WTILE_SIZE + m] =
												(float) (dx[(l + upshift) * TILE_SIZE + m + leftshift] *
												dx[(l + upshift) * TILE_SIZE + m + leftshift] +
												dy[(l + upshift) * TILE_SIZE + m + leftshift] *
												dy[(l + upshift) * TILE_SIZE + m + leftshift]);
										}
									}
									map[y * map_width + x] = 1;
								}
								Eimg[(j + centery) * win.width + k + centerx] = energy =
									gradient[(ppt[i].y + j) * roi.width + ppt[i].x + k];


							}
							else
								Eimg[(j + centery) * win.width + k + centerx] = energy =
									srcp[(ppt[i].y + j) * srcStep + ppt[i].x + k];
							maxEimg = MAX( maxEimg, energy );
							minEimg = MIN( minEimg, energy );
						}
					}
					if(isoriginit){
						tmp = (maxEimg - minEimg);
						tmp = (tmp == 0) ? 0 : (1 / tmp);
						for( k = 0; k < neighbors; k++ )
							Eimg[k] = (minEimg - Eimg[k]) * tmp;
						osEimg[i] = (minEimg - oEimg[i])*tmp;
					}
				}
				//  Calculate Eint
				if (oteta!=0) {
					for( j = -upper; j <= bottom; j++ )
					{
						for( k = -left; k <= right; k++ )
						{
							Eint[(j + centery) * win.width + k + centerx] = energy =
								srcp[(ppt[i].y + j) * srcStep + ppt[i].x + k];
							maxEint = MAX( maxEint, energy );
							minEint = MIN( minEint, energy );
						}
					}
					if (isoriginit){
						tmp = maxEint - minEint;
						tmp = (tmp == 0) ? 0 : (1 / tmp);
						for( k = 0; k < neighbors; k++ )
							Eint[k] = (Eint[k] - minEint) * tmp;
						osEint[i] = (oEint[i] - minEint)*tmp;
					}
				}
				//  Calculate Earc
				if (ozeta!=0) {
					for( j = -upper; j <= bottom; j++ )
					{
						for( k = -left; k <= right; k++ )
						{
							int diff2x,diff2y;

							if( i == 0 )
							{
								diffx = opt[n - 1].x - (ppt[i].x + k);
								diffy = opt[n - 1].y - (ppt[i].y + j);
							}
							else
							{
								diffx = opt[i - 1].x - (ppt[i].x + k);
								diffy = opt[i - 1].y - (ppt[i].y + j);
							}
							if( i == n-1 )
							{
								diff2x = opt[0].x - (ppt[i].x + k);
								diff2y = opt[0].y - (ppt[i].y + j);
							}
							else
							{
								diff2x = opt[i + 1].x - (ppt[i].x + k);
								diff2y = opt[i + 1].y - (ppt[i].y + j);
							}
							Earc[(j + centery) * win.width + k + centerx] = energy =
								cvSqrt( (float) (diffx * diffx + diffy * diffy) ) + cvSqrt( (float) (diff2x * diff2x + diff2y * diff2y) );

							maxEarc = MAX( maxEarc, energy );
							minEarc = MIN( minEarc, energy );
						}
					}
					if (isoriginit){
						tmp = maxEarc - minEarc;
						tmp = (tmp == 0) ? 0 : (1 / tmp);
						for( k = 0; k < neighbors; k++ )
							Earc[k] = (Earc[k] - minEarc) * tmp;
						osEarc[i] = (oEarc[i] - minEarc)*tmp;
					}
				}
				//  Calculate Edu-x/y gradients
				if (oomega!=0) {
					for( j = -upper; j <= bottom; j++ )
					{
						for( k = -left; k <= right; k++ )
						{
							float energyy;
							Edux[(j + centery) * win.width + k + centerx] = energy = (float)pdux->imageData[(ppt[i].y + j) * pdux->widthStep + ppt[i].x + k];
							Eduy[(j + centery) * win.width + k + centerx] = energyy = (float)pduy->imageData[(ppt[i].y + j) * pduy->widthStep + ppt[i].x + k];
							maxEdux = MAX( maxEdux, energy );
							minEdux = MIN( minEdux, energy );
							maxEduy = MAX( maxEduy, energyy );
							minEduy = MIN( minEduy, energyy );
						}
					}
					if (isoriginit){
						tmp = maxEdux - minEdux;
						tmp = (tmp == 0) ? 0 : (1 / tmp);
						for( k = 0; k < neighbors; k++ )
							Edux[k] = (Edux[k] - minEdux) * tmp;
						osEdux[i] = (oEdux[i] - minEdux)*tmp;
						tmp = maxEduy - minEduy;
						tmp = (tmp == 0) ? 0 : (1 / tmp);
						for( k = 0; k < neighbors; k++ )
							Eduy[k] = (Eduy[k] - minEduy) * tmp;
						osEduy[i] = (oEduy[i] - minEduy)*tmp;
					}
				}
				//---------------------- //end E calculations.

				int loci=centery*win.width+centerx;
				if (!isoriginit){
					//Initialize Original image parameters
					oEcont[i] = Econt[loci];
					oEcurv[i] = Ecurv[loci];
					oEimg[i] = Eimg[loci];
					oEint[i] = Eint[loci];
					if (oEarc_static){
						if (oEarc_static_ready)
							oEarc[i] = oEarc_static[i];
						else
							oEarc[i] = oEarc_static[i] = Earc[loci];
					}
					else
						oEarc[i] = Earc[loci];
					oEdux[i] = Edux[loci];
					oEduy[i] = Eduy[loci];
				}
				else{
					/* locate coefficients */
					if( coeffUsage != CV_VALUE)
					{
						_alpha = alpha[i];
						_beta = beta[i];
						_gamma = gamma[i];
						_oalpha = oalpha[i];
						_obeta = obeta[i];
						_ogamma = ogamma[i];
						_oteta = oteta[i];
						_ozeta = ozeta[i];
						_oomega = oomega[i];
					}

					/* Find Minimize point in the neighbors */
					for( k = 0; k < neighbors; k++ )
					{
						E[k] = _alpha * Econt[k] + _beta * Ecurv[k] + _gamma * Eimg[k]
						+ _oalpha*fabs(Econt[k]-osEcont[i])
						+ _obeta*fabs(Ecurv[k]-osEcurv[i])
						+ _ogamma*fabs(Eimg[k]-osEimg[i])
						+ _oteta*fabs(Eint[k]-osEint[i])
						+ _ozeta*fabs(Earc[k]-osEarc[i])
						+ _oomega*(fabs(Edux[k]-osEdux[i])+fabs(Eduy[k]-osEduy[i]))
						;
					}
//					Emin = _CV_SNAKE_BIG;
					Emin = E[loci];
					for( j = -upper; j <= bottom; j++ )
					{
						for( k = -left; k <= right; k++ )
						{

							if( E[(j + centery) * win.width + k + centerx] < Emin )// || (E[(j + centery) * win.width + k + centerx] == Emin && rand()%2))
							{
								Emin = E[(j + centery) * win.width + k + centerx];
								offsetx = k;
								offsety = j;
							}
						}
					}

					if( offsetx || offsety )
					{
						ppt[i].x += offsetx;
						ppt[i].y += offsety;
						moved++;
					}
				}//originit
				/*
				//Debugging: display gradient image
				float maxgrad=0;
				float mingrad=_CV_SNAKE_BIG;
				for(j=0; j<roi.width; j++){
					for(k=0; k<roi.height; k++){
						float grad=gradient[k*roi.width+j];
						if(grad<mingrad)
							mingrad=grad;
						if(grad>maxgrad)
							maxgrad=grad;
					}
				}
				IplImage *gray = cvCreateImage( cvSize(roi.width, roi.height), IPL_DEPTH_8U, 1 );
				tmp = (maxEimg - minEimg);
				tmp = (tmp == 0) ? 0 : (1 / tmp);
				for(j=0; j<roi.width; j++){
					for(k=0; k<roi.height; k++){
						float grad=gradient[k*roi.width+j];
						cvSetReal2D(gray,k,j,((grad-mingrad)*tmp*255));
					}
				}
				cvNamedWindow("tmp");
				cvShowImage("tmp",gray);
				cvReleaseImage(&gray);
				cvWaitKey(100);
				*/

			}//for n
			converged = (moved == 0);
			if( (criteria.type & CV_TERMCRIT_ITER) && (iteration >= criteria.max_iter) )
				converged = 1;
			if( (criteria.type & CV_TERMCRIT_EPS) && (moved <= criteria.epsilon) )
				converged = 1;
		}//while !converged
	}//for isoriginit
	cvFree( &E );
	cvFree( &Econt );
	cvFree( &oEcont );
	cvFree( &osEcont );
	cvFree( &Ecurv );
	cvFree( &oEcurv );
	cvFree( &osEcurv );
	cvFree( &Eimg );
	cvFree( &oEimg );
	cvFree( &osEimg );
	cvFree( &Eint );
	cvFree( &oEint );
	cvFree( &osEint );
	cvFree( &Earc );
	cvFree( &oEarc );
	cvFree( &osEarc );
	cvFree( &Edux );
	cvFree( &oEdux );
	cvFree( &osEdux );
	cvFree( &Eduy );
	cvFree( &oEduy );
	cvFree( &osEduy );


	if( scheme == _CV_SNAKE_GRAD )
	{
		cvFree( &gradient );
		cvFree( &map );
	}
	if(iterations) *iterations = iteration;
	return CV_OK;
}

#include <stdio.h>
void
cvSnakeImageTrack( const IplImage* src, CvPoint* points, int length,
		  float *alpha, float *beta, float *gamma,
		  const IplImage* orig,
		  CvPoint *opoints,
		  float *oalpha, float *obeta, float *ogamma, float *oteta, float *ozeta, float *oomega,
		  int coeffUsage, CvSize win,
		  CvTermCriteria criteria, int calcGradient,
		   float *oEarc_static, bool oEarc_static_ready,
		  int *iterations)
{

	CV_FUNCNAME( "cvSnakeImageTrack" );

	__BEGIN__;

	uchar *data;
	CvSize size;
	int step;

	if( src->nChannels != 1 )
		CV_ERROR( CV_BadNumChannels, "input image has more than one channel" );

	if( src->depth != IPL_DEPTH_8U )
		CV_ERROR( CV_BadDepth, cvUnsupportedFormat );

	cvGetRawData( src, &data, &step, &size );
	uchar *odata;
	cvGetRawData( orig, &odata, &step, &size );

	IplImage *dux = NULL;
    IplImage *duy = NULL;
	IplImage *odux= NULL;
    IplImage *oduy= NULL;
	if(oomega!=0){
		dux = cvCreateImage(size, IPL_DEPTH_32F, 1 );
		duy = cvCreateImage(size, IPL_DEPTH_32F, 1 );
		odux = cvCreateImage(size, IPL_DEPTH_32F, 1 );
		oduy = cvCreateImage(size, IPL_DEPTH_32F, 1 );
		cvSobel(src, dux, 2, 0, 5);
		cvSobel(src, duy, 0, 2, 5);
		cvSobel(orig, odux, 2, 0, 5);
		cvSobel(orig, oduy, 0, 2, 5);
	//	cvNamedWindow("t");
	//	cvShowImage("t",dux);
	//	cvShowImage("t",odux);
	}

	CvStatus status = ( icvSnakeTrack8uC1R( data, step, size, points, length,
		alpha, beta, gamma, coeffUsage, win, criteria,
		calcGradient ? _CV_SNAKE_GRAD : _CV_SNAKE_IMAGE,
		odata, opoints, oalpha, obeta, ogamma, oteta, ozeta, oomega,
		dux, duy, odux, oduy,
		oEarc_static, oEarc_static_ready,
		iterations));
	if(oomega!=0){
		cvReleaseImage(&dux);
		cvReleaseImage(&duy);
		cvReleaseImage(&odux);
		cvReleaseImage(&oduy);
	}
	if (status != CV_OK) {
		char buff[64];
		sprintf(buff, "icvSnakeTrack8uC1R returned with error code %d", status);
		CV_ERROR(CV_StsBackTrace, buff);
	}
	__END__;
}

/* end of file */
