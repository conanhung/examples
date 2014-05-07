#include "wxTextCtrl_double.h"
wxTextCtrl_double::wxTextCtrl_double( wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name )
: wxTextCtrl(parent, id, value, pos, size, style, validator, name)
{
	Connect( wxEVT_CHAR, wxKeyEventHandler( wxTextCtrl_double::OnChar ), NULL, this );
}

wxTextCtrl_double::~wxTextCtrl_double()
{
	Disconnect( wxEVT_CHAR, wxKeyEventHandler( wxTextCtrl_double::OnChar ), NULL, this );
}
#include <ctype.h>
void wxTextCtrl_double::OnChar( wxKeyEvent& e )
{
	int k=e.GetKeyCode();
	if (k<0 || k>255 || !isprint(k) || e.ControlDown() || e.AltDown()
		|| (k>='0' && k<='9')
		|| (k=='.' && wxTextCtrl::GetValue().Find('.')==wxNOT_FOUND) )
		e.Skip();
}
double wxTextCtrl_double::GetValue()
{
	double d;
	wxTextCtrl::GetValue().ToDouble(&d);
	return d;
}
