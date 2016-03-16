// ChildView.h : интерфейс класса CChildView
//

#pragma once
#include "CObj.h"
#include "Hexagon.h"
#include <vector>
// окно CChildView


class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
protected:
	std::vector<CGrpObject *> m_Obj;
	int m_nCatched;
	CPoint m_MousePos;
// Операции
protected:
	int FindObject(CPoint point);

// Переопределение
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
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

