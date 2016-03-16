#include "StdAfx.h"
#include "C2DBox.h"

C2DBox::C2DBox(void)
{
	m_X1 = 0;
	m_X2 = 0;
	m_Y1 = 0;
	m_Y2 = 0;
}
C2DBox::C2DBox(double X1, double Y1, double X2, double Y2)
{
	m_X1 = X1;
	m_X2 = X2;
	m_Y1 = Y1;
	m_Y2 = Y2;
}
C2DBox::~C2DBox(void)
{
}