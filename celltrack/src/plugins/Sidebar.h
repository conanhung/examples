#ifndef __ImproveContoursSidebar__
#define __ImproveContoursSidebar__


#include "Gui.h"
#include <wx/msgdlg.h>
#include "ImproveContoursPlugin.h"

class ImproveContoursPlugin;

/** Implementing ImproveContoursSidebar_ */
class ImproveContoursSidebar : public ImproveContoursSidebar_
{
private:
	ImproveContoursPlugin *plugin;
public:
	/** Constructor */
	ImproveContoursSidebar( ) : ImproveContoursSidebar_( NULL ){}
	ImproveContoursSidebar( wxWindow* parent ) : ImproveContoursSidebar_( parent ){}
	ImproveContoursSidebar( wxWindow* parent, ImproveContoursPlugin *plugin_ )
		: ImproveContoursSidebar_( parent ), plugin(plugin_) {
	}
	void OnChange();
	void OnChange( wxSpinEvent& event ){ OnChange(); }
	void OnChange( wxCommandEvent& event ){ OnChange(); }
	void OnChangePreview( wxCommandEvent& event );
	void OnOK( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );
	bool IsPreviewOn();
	int GetThresh1(){
		return thresh1->GetValue();
	}
	int GetThresh2(){
		return thresh2->GetValue();
	}
	int GetAperture(){
		long val;
		aperture->GetStringSelection().ToLong(&val);
		return (int) val;
	}
	int GetDilations(){
		return dilations->GetValue();
	}
	int GetScope(){
		return scope->GetSelection();
	}
	bool GetClean(){
		return clean->GetValue();
	}
	DECLARE_DYNAMIC_CLASS(ImproveContoursSidebar)
};


#endif // __ImproveContoursSidebar__
