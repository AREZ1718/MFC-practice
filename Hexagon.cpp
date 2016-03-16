#include "StdAfx.h"
#include "Hexagon.h"
#include "math.h"
#define PI 3.1415926535897932384626433832795

CHexagon::CHexagon(double x, double y, double A){
	m_dCenterX = x;
	m_dCenterY = y;
	m_A = A;
}
CHexagon::~CHexagon(void){
}

double CHexagon::GetA()
{
	return m_A;
}
double CHexagon::GetA1()
{
	return 0;
}
double CHexagon::GetA2()
{
	return 0;
}
double CHexagon::GetA3()
{
	return 0;
}
double CHexagon::GetAng()
{
	return 0;
}

bool CHexagon::Set(double A, double A1, double A2, double A3, double Angle)
{
	m_A = A;
	return true;

}
int CHexagon::GetType()
{
	return 0;
}

bool CHexagon::IsInside(double x, double y)
{
	bool fl = false;
	double X[6], Y[6];
	X[0] = m_dCenterX - m_A;
	Y[0] = m_dCenterY;
	X[1] = m_dCenterX - m_A * 1/2;
	Y[1] = m_dCenterY - m_A * sqrt(3.)/2;
	X[2] = m_dCenterX + m_A * 1/2;
	Y[2] = m_dCenterY - m_A * sqrt(3.)/2;
	X[3] = m_dCenterX + m_A;
	Y[3] = m_dCenterY;
	X[4] = m_dCenterX + m_A * 1/2;
	Y[4] = m_dCenterY + m_A * sqrt(3.)/2;
	X[5] = m_dCenterX - m_A * 1/2;
	Y[5] = m_dCenterY + m_A * sqrt(3.)/2;
	for (int i = 0, j = 5; i < 6; j = i++) 
    {
		if (((Y[i]<Y[j]) && (Y[i]<=y) && (y<=Y[j]) && ((Y[j] - Y[i]) * (x - X[i]) > (X[j] - X[i]) * (y - Y[i]))) || ((Y[i]>Y[j]) && (Y[j]<=y) && (y<=Y[i]) && ((Y[j] - Y[i]) * (x - X[i]) < (X[j] - X[i]) * (y - Y[i]))))
       fl = !fl;
   }
	return fl;
}

void CHexagon::Draw(CDC &dc)
{
	dc.BeginPath();
	dc.MoveTo(m_dCenterX - m_A, m_dCenterY);
	dc.LineTo(m_dCenterX - m_A * 1/2, m_dCenterY - m_A * sqrt(3.)/2);
	dc.LineTo(m_dCenterX + m_A * 1/2, m_dCenterY - m_A * sqrt(3.)/2);
	dc.LineTo(m_dCenterX + m_A, m_dCenterY);
	dc.LineTo(m_dCenterX + m_A * 1/2, m_dCenterY + m_A * sqrt(3.)/2);
	dc.LineTo(m_dCenterX - m_A * 1/2, m_dCenterY + m_A * sqrt(3.)/2);
	dc.LineTo(m_dCenterX - m_A, m_dCenterY);
	dc.EndPath();
	dc.StrokeAndFillPath();
}
void CHexagon::GetBoundBox(C2DBox *pBox)
{
	pBox->m_X1 = m_dCenterX - m_A;
	pBox->m_Y1 = m_dCenterY - m_A;
	pBox->m_X2 = m_dCenterX + m_A;
	pBox->m_Y2 = m_dCenterY + m_A;
}