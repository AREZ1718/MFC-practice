// DHex.cpp : implementation file
//

#include "stdafx.h"
#include "KursovayaVar9Rezaev.h"
#include "DHex.h"
#include "afxdialogex.h"
#include "math.h"


// CDHex dialog

IMPLEMENT_DYNAMIC(CDHex, CDialogEx)

CDHex::CDHex(double dA, double dS, CWnd* pParent /*=NULL*/)
	: CDialogEx(CDHex::IDD, pParent)
	, m_dA(dA)
	, m_dS(dS)
	, m_Gabs(_T(""))
{
	m_Gabs.Format(_T("%3.f x %3.f"), 2 * dA, sqrt(3.)*dA);
}

CDHex::~CDHex()
{
}

void CDHex::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dA);
	DDX_Text(pDX, IDC_EDIT2, m_dS);
	DDX_Text(pDX, IDC_EDIT3, m_Gabs);
}


BEGIN_MESSAGE_MAP(CDHex, CDialogEx)
END_MESSAGE_MAP()


// CDHex message handlers
