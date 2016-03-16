#pragma once


// CDHex dialog

class CDHex : public CDialogEx
{
	DECLARE_DYNAMIC(CDHex)

public:
	CDHex(double dA, double dS, CWnd* pParent = NULL);   // standard constructor
	virtual ~CDHex();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dA;
	double m_dS;
	CString m_Gabs;
};
