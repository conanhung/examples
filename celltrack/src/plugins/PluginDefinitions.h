#pragma once
#include "CustomEvents.h"

#define DEFINE_PLUGIN_SIDEBAR(NAME)	\
	private: \
	NAME##Plugin *plugin; \
	wxCheckBox *preview_; \
	public: \
		NAME##Sidebar( ) : NAME##Sidebar_( NULL ){} \
		NAME##Sidebar( wxWindow* parent ) : NAME##Sidebar_( parent ){} \
		NAME##Sidebar( wxWindow* parent, NAME##Plugin *plugin_ ); \
	void OnChange();\
	void OnChange( wxSpinEvent& event ){ OnChange(); } \
	void OnChange( wxCommandEvent& event ){ OnChange(); } \
	void OnChange( wxNotebookEvent& event ){ OnChange(); } \
	void OnChange( wxChoicebookEvent& event ){ OnChange(); } \
	void OnChangePreview( wxCommandEvent& event ); \
	void OnOK( wxCommandEvent& event ); \
	void OnCancel( wxCommandEvent& event ); \
	void OnApply( wxCommandEvent& event ); \
	friend class NAME##Plugin; \
	friend class MyFrame; 



#define DECLARE_PLUGIN_SIDEBAR(NAME)	\
	NAME##Sidebar::NAME##Sidebar( wxWindow* parent, NAME##Plugin *plugin_ ) \
	: NAME##Sidebar_( parent ), plugin(plugin_), preview_(NULL) { \
		wxWindow *w=FindWindowByLabel("Show preview",this); \
		if(w) preview_=(wxCheckBox*)w; } \
	void NAME##Sidebar::OnChange() { plugin->DoPreview(); } \
	void NAME##Sidebar::OnOK( wxCommandEvent& event ) \
	{ plugin->OnOK(); ProcessEvent(wxCommandEvent(EVT_PLUGIN_END)); } \
	void NAME##Sidebar::OnCancel( wxCommandEvent& event ) \
	{ plugin->OnCancel(); ProcessEvent(wxCommandEvent(EVT_PLUGIN_END)); } \
	void NAME##Sidebar::OnApply( wxCommandEvent& event ) \
	{ plugin->OnApply(); } \
	void NAME##Sidebar::OnChangePreview( wxCommandEvent& event ) { \
		if (!preview_) return; \
		if (preview_->GetValue()) \
			OnChange(); \
		else \
			plugin->OnEndPreview(); \
	}
