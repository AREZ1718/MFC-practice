#include "StdAfx.h"
#include "CObj.h"
#include "math.h"

#define PI 3.1415926535897932384626433832795

CMy2DObject9::CMy2DObject9(double x, double y, double A, double A1, double A2, double A3, double dAngle){
	m_dCenterX = x;
	m_dCenterY = y;
	m_A = A;
	m_A1 = A1;
	m_A2 = A2;
	m_A3 = A3;
	m_dAngle = dAngle;
}
CMy2DObject9::~CMy2DObject9(void){
}

double CMy2DObject9::GetA()
{
	return m_A;
}
double CMy2DObject9::GetA1()
{
	return m_A1;
}
double CMy2DObject9::GetA2()
{
	return m_A2;
}
double CMy2DObject9::GetA3()
{
	return m_A3;
}
double CMy2DObject9::GetAng()
{
	return m_dAngle;
}

bool CMy2DObject9::Set(double A, double A1, double A2, double A3, double Angle)
{
	if((A/2 < A1) || (A < A3) || (A < A2)  || (A2 * (sqrt(2.)/2) / cos(PI/4 - acos(2/sqrt(5.))) + A1 + 6 * A/200 > (sqrt(5.)/2) * A)|| (A3 + A1 > (sqrt(5.)/2) * A)|| (A2 + A3 > A))
	{
		return false;
	}
	else
	{
		m_A = A;
		m_A1 = A1;
		m_A2 = A2;
		m_A3 = A3;
		m_dAngle = Angle;
		return true;
	}
}

void CMy2DObject9::Draw(CDC &dc)
{
	CPoint p1, p2, p3;
	double dAngle;
	dAngle = m_dAngle * PI / 180.0;
	p1.x = m_dCenterX + (m_A / 2) * cos(dAngle);
	p1.y = m_dCenterY + (m_A / 2) * sin(dAngle);
	p2.x = m_dCenterX - (m_A / 2 - m_A2) * cos(dAngle) + (m_A / 2 - m_A2) * sin(dAngle);
	p2.y = m_dCenterY - (m_A / 2 - m_A2) * sin(dAngle) - (m_A / 2 - m_A2) * cos(dAngle);
    p3.x = m_dCenterX - (m_A / 2) * cos(dAngle) - (m_A / 2) * sin(dAngle);
	p3.y = m_dCenterY - (m_A / 2) * sin(dAngle) + (m_A / 2) * cos(dAngle);
	
	dc.BeginPath();
	dc.MoveTo(p1.x + m_A1 * sin(dAngle),p1.y - m_A1 * cos(dAngle));
	dc.AngleArc(p1.x, p1.y, m_A1, 90 - m_dAngle, 180);
	dc.LineTo(p1.x - m_A/2 * sin(dAngle),p1.y + m_A/2 * cos(dAngle));
	dc.LineTo(p3.x + m_A3 * cos(dAngle), p3.y + m_A3 * sin(dAngle));
	dc.AngleArc(p3.x, p3.y, m_A3, 0 - m_dAngle, 90);
	dc.LineTo(p2.x - m_A2 * cos(dAngle), p2.y - m_A2 * sin(dAngle));
	dc.LineTo(p2.x + m_A2 * sin(dAngle), p2.y - m_A2 * cos(dAngle));
	dc.LineTo(p1.x + m_A/2 * sin(dAngle), p1.y - m_A/2 * cos(dAngle));
	dc.LineTo(p1.x + m_A1 * sin(dAngle), p1.y - m_A1 * cos(dAngle));
	dc.EndPath();
	dc.StrokeAndFillPath();
}

bool CMy2DObject9::IsInside(double x, double y)
{
	double dAngle;
	CPoint p1, p2, p3, testp;
	dAngle = m_dAngle * PI / 180.0;
	p1.x = m_dCenterX + m_A/2;
	p1.y = m_dCenterY;
	p2.x = m_dCenterX - m_A/2;
	p2.y = m_dCenterY - m_A/2;
	p3.x = m_dCenterX - m_A/2;
	p3.y = m_dCenterY + m_A/2;
	testp.x = cos(dAngle)*(x - m_dCenterX) + sin(dAngle) * (y - m_dCenterY) + m_dCenterX;
	testp.y = - sin(dAngle)*(x - m_dCenterX) + cos(dAngle) * (y - m_dCenterY) + m_dCenterY;
	if((abs(testp.x - m_dCenterX) > m_A / 2) || (abs(testp.y - m_dCenterY) > m_A / 2)) return false;
	if((testp.x - p1.x) * (testp.x - p1.x) + (testp.y - p1.y) * (testp.y - p1.y) < m_A1 * m_A1) return false;
	if((testp.x - p2.x - m_A2)/m_A2 - (p2.y - testp.y)/m_A2 < 0) return false;
	if((testp.x - p3.x) * (testp.x - p3.x) + (testp.y - p3.y) * (testp.y - p3.y) < m_A3 * m_A3) return false;
	return true;
}
int CMy2DObject9::GetType(){
	return 1;
}
void CMy2DObject9::GetBoundBox(C2DBox *pBox)
{
	pBox->m_X1 = m_dCenterX - m_A / 2;
	pBox->m_Y1 = m_dCenterY - m_A / 2;
	pBox->m_X2 = m_dCenterX + m_A / 2;
	pBox->m_Y2 = m_dCenterY + m_A / 2;
}


