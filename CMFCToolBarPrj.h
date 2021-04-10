
// CMFCToolBarPrj.h : main header file for the CMFCToolBarPrj application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCMFCToolBarPrjApp:
// See CMFCToolBarPrj.cpp for the implementation of this class
//

class CCMFCToolBarPrjApp : public CWinAppEx
{
public:
	CCMFCToolBarPrjApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCMFCToolBarPrjApp theApp;
