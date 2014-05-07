#pragma once
#include <wx/textctrl.h>

class wxTextCtrl_double : public wxTextCtrl
{
public:
	wxTextCtrl_double(wxWindow* parent, wxWindowID id, const wxString& value = "", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr);
	virtual ~wxTextCtrl_double(void);
	virtual void OnChar( wxKeyEvent& e );
	virtual double GetValue();
};
