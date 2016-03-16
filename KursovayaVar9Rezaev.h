// KursovayaVar9Rezaev.h : main header file for the KursovayaVar9Rezaev application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CKursovayaVar9RezaevApp:
// See KursovayaVar9Rezaev.cpp for the implementation of this class
//

class CKursovayaVar9RezaevApp : public CWinApp
{
public:
	CKursovayaVar9RezaevApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKursovayaVar9RezaevApp theApp;