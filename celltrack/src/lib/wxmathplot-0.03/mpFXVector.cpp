//by ahmet.

#ifdef __GNUG__
// #pragma implementation "plot.h"
#pragma implementation "mathplot.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include <wx/window.h>
//#include <wx/wxprec.h>

// Comment out for release operation:
// (Added by J.L.Blanco, Aug 2007)
// #define MATHPLOT_DO_LOGGING

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/object.h"
#include "wx/font.h"
#include "wx/colour.h"
#include "wx/settings.h"
#include "wx/sizer.h"
#include "wx/log.h"
#include "wx/intl.h"
#include "wx/dcclient.h"
#include "wx/cursor.h"
#endif

#include "mathplot.h"
#include <wx/bmpbuttn.h>
#include <wx/module.h>
#include <wx/msgdlg.h>

#include <math.h>
#include <cstdio> // used only for debug
#include <vector>

#include "mpFXVector.h"

IMPLEMENT_CLASS(mpFXVector, mpFXYVector)

void mpFXVector::SetData( const std::vector<float> &ys, int xstart)
{
	std::vector<float> xs(ys.size());
	for (int i=0; i<ys.size(); i++)
		xs[i] = i+xstart;
	mpFXYVector::SetData( xs, ys );
}

bool mpFXVector::GetNextXY(double & x, double & y)
{
    if (m_index>=m_xs.size())
        return FALSE;
    else
    {
        x = m_xs[m_index];
        y = m_ys[m_index++];
        return m_index<=m_xs.size();
    }
}

void mpFXVector::Plot(wxDC & dc, mpWindow & w) {
	wxString name = m_name;
	if (m_xs.size())
		m_name = "";
	mpFXYVector::Plot(dc, w);
	if (m_xs.size() && !name.IsEmpty()) {
		m_name = name;
		dc.SetFont(m_font);

		wxCoord tx, ty;
		dc.GetTextExtent(m_name, &tx, &ty);

		wxCoord cx = (wxCoord) ((m_xs.back() - w.GetPosX()) * w.GetScaleX())+2;
		wxCoord cy = (wxCoord) ((w.GetPosY() - m_ys.back()) * w.GetScaleY())-ty/2;

		dc.DrawText( m_name, cx, cy);
	}
}