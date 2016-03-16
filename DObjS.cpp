// DObjS.cpp : implementation file
//

#include "stdafx.h"
#include "KursovayaVar9Rezaev.h"
#include "DObjS.h"


// CDObjS dialog

IMPLEMENT_DYNAMIC(CDObjS, CDialog)

CDObjS::CDObjS(double dA, double dA1, double dA2, double dA3, double dAngle, double dS, CWnd* pParent /*=NULL*/)
	: CDialog(CDObjS::IDD, pParent)
	, m_dA(dA)
	, m_dA1(dA1)
	, m_dA2(dA2)
	, m_dA3(dA3)
	, m_dAngle(dAngle)
	, m_dS(dS)
	, m_Gabs(_T(""))
{
	m_Gabs.Format(_T("%3.f x %3.f"), dA, dA);
}

CDObjS::~CDObjS()
{
}

void CDObjS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E_A, m_dA);
	DDV_MinMaxDouble(pDX, m_dA, 0, 1000);
	DDX_Text(pDX, IDC_E_A1, m_dA1);
	DDV_MinMaxDouble(pDX, m_dA1, 0, 1000);
	DDX_Text(pDX, IDC_E_A2, m_dA2);
	DDV_MinMaxDouble(pDX, m_dA2, 0, 1000);
	DDX_Text(pDX, IDC_E_A3, m_dA3);
	DDV_MinMaxDouble(pDX, m_dA3, 0, 1000);
	DDX_Text(pDX, IDC_E_Angle, m_dAngle);
	DDV_MinMaxDouble(pDX, m_dAngle, -180, 180);
	DDX_Text(pDX, IDC_EDIT1, m_dS);
	DDX_Text(pDX, IDC_EDIT2, m_Gabs);
}


BEGIN_MESSAGE_MAP(CDObjS, CDialog)
END_MESSAGE_MAP()


// CDObjS message handlers
BOOL CDObjS::OnInitDialog() 
{ 
	CDialog::OnInitDialog();  
	return TRUE; // return TRUE unless you set 
	// the focus to a control 
}
void CDObjS::OnOK() 
{ 
	
	CDialog::OnOK(); 
}
