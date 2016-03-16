// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "KursovayaVar9Rezaev.h"
#include "ChildView.h"
#include "DObjS.h"
#include "DHex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_nCatched = -1;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SlObj, OnSlObj)
	ON_COMMAND(ID_Hexagon, OnHexagon)
	ON_COMMAND(ID_Del , OnDel)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for drawing
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CRect rect;
	GetClientRect(&rect);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dcMem, rect.Width(), rect.Height());
	CBitmap *pOldBmp = dcMem.SelectObject(&bmp);
	dcMem.FillSolidRect(0,0,rect.Width(), rect.Height(), RGB(255, 255, 255));
	
	for(int i=0; i<m_Obj.size(); i++){
		m_Obj[i]->Draw(dcMem);
	}
	dc.BitBlt(0,0, rect.Width(), rect.Height(), &dcMem, 0,0,SRCCOPY);
	dcMem.SelectObject(pOldBmp);
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC) {
	//Don’t call base class implementation
	//return CWnd::OnEraseBkgnd(pDC);
	return true;//Just return true.
}
void CChildView::OnLButtonDown(UINT nFlags, CPoint point){
	m_nCatched =FindObject(point);

	if(m_nCatched >=0 ){
		m_MousePos = point;
		SetCapture();
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point){
	m_nCatched = -1;
	ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point){
	if(m_nCatched>=0){
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y));
		CPoint Delta = point - m_MousePos;
		m_Obj[m_nCatched]->Move(Delta.x, Delta.y);
		m_MousePos = point;
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	int n = FindObject(point);
	if(n < 0){
	}
	else
	{
		if (m_Obj[n]->GetType() == 1)
		{

			CDObjS Dlg(m_Obj[n]->GetA(), m_Obj[n]->GetA1(), m_Obj[n]->GetA2(), m_Obj[n]->GetA3(), m_Obj[n]->GetAng(), m_Obj[n]->GetSquare());
			if (Dlg.DoModal())
			{
				m_Obj[n]->Set(Dlg.m_dA, Dlg.m_dA1, Dlg.m_dA2, Dlg.m_dA3, Dlg.m_dAngle);
				Invalidate();
			}
		}
		else
		{
			CDHex Dlg(m_Obj[n]->GetA(), m_Obj[n]->GetSquare());
			if (Dlg.DoModal())
			{
				m_Obj[n]->Set(Dlg.m_dA, 0, 0, 0, 0);
				Invalidate();
			}
		}
	}

	CWnd::OnLButtonDblClk(nFlags, point);
}

int CChildView::FindObject(CPoint point){
	int nObj = -1;
	for(int i=m_Obj.size()-1; i>=0; i--){
		if(m_Obj[i]->IsInside(point.x, point.y)){
			nObj = i;
			break;
		}
	}
	return nObj;
}

void CChildView::OnSlObj()
{
	CRect rect;
	GetClientRect(&rect);
	m_Obj.push_back(new CMy2DObject9(rand() % rect.Width(), rand()% rect.Height(), 10 + rand()% 20, 4, 2, 2, 0));
	Invalidate();
}
void CChildView::OnHexagon()
{
	CRect rect;
	GetClientRect(&rect);
	m_Obj.push_back(new CHexagon(rand()%rect.Width(), rand()% rect.Height(), 10 + rand()% 20));
	Invalidate();
}
void CChildView::OnDel()
{
	int n;
	double S;
	n = 0;
	for (int i = 0; i <= m_Obj.size() - 1; i++)
	{
		if (m_Obj[i]->GetType() == 1)
		{
			S = m_Obj[i]->GetSquare();
			n = i;
			break;
		}
	}
	for(int i = n; i <= m_Obj.size() - 1; i++)
	{
		if(m_Obj[i]->GetType() == 1)
		{
			if(m_Obj[i]->GetSquare() > S) S = m_Obj[i]->GetSquare();
		}
	}
	n = m_Obj.size() - 1;
	for(int i = 0; i <= n; i++)
	{
		if(m_Obj[i]->GetType() == 0)
		{
			if(m_Obj[i]->GetSquare() > S)
			{
				if(i != n)
				{
					m_Obj.erase(m_Obj.begin() + i, m_Obj.begin() + i + 1);
					n--;
					i--;
				}
				else
				{
					m_Obj.pop_back();
				}
			}
		}
	}
	Invalidate();
}

