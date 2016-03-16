// ChildView.h : ��������� ������ CChildView
//

#pragma once
#include "CObj.h"
#include "Hexagon.h"
#include <vector>
// ���� CChildView


class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
protected:
	std::vector<CGrpObject *> m_Obj;
	int m_nCatched;
	CPoint m_MousePos;
// ��������
protected:
	int FindObject(CPoint point);

// ���������������
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSlObj();
	afx_msg void OnHexagon();
	afx_msg void OnDel();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

