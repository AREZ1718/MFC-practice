#pragma once
#include "afxwin.h"


// CDObjS dialog

class CDObjS : public CDialog
{
	DECLARE_DYNAMIC(CDObjS)

public:
	CDObjS(double dA, double dA1, double dA2, double dA3, double dAngle, double dS, CWnd* pParent = NULL);   // standard constructor
	virtual ~CDObjS();

// Dialog Data
	enum { IDD = IDD_DObjS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL CDObjS::OnInitDialog();
	void CDObjS::OnOK();
	DECLARE_MESSAGE_MAP()
public:
	double m_dA;
	double m_dA1;
	double m_dA2;
	double m_dA3;
	double m_dAngle;
	double m_dS;
	CString m_Gabs;
};
