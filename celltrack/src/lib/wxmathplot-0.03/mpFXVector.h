#ifndef __MPFXVECTOR_H__
#define __MPFXVECTOR_H__
#include "mathplot.h"

class WXDLLEXPORT mpFXVector;

//-----------------------------------------------------------------------------
// mpFXVector - Ahmet Sacan
//-----------------------------------------------------------------------------

/** Similar to mpFXYVector, except that X is integers starting from 1 (default)
*/
class WXDLLEXPORT mpFXVector : public mpFXYVector
{
public:
	mpFXVector(wxString name = wxEmptyString, int flags = mpALIGN_NE)
		: mpFXYVector(name, flags) {}

    void SetData( const std::vector<float> &ys, int xstart=1);

	//the mpFXYVector's implementation has a little bug causing the last point not drawn
	bool GetNextXY(double & x, double & y);
	void Plot(wxDC & dc, mpWindow & w);

protected:

    DECLARE_CLASS(mpFXYVector)
};


#endif
