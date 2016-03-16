#include "StdAfx.h"
#include "CGrpObject.h"
#include "math.h"

CGrpObject::CGrpObject(void)
{
	m_dCenterX = 0;
	m_dCenterY = 0;
}
CGrpObject::~CGrpObject(void)
{
}
void CGrpObject::Move(double dx, double dy)
{
	m_dCenterX += dx;
	m_dCenterY += dy;
}
double CGrpObject::GetSquare()
{
	C2DBox Box;
	int count = 0, n = 1000;
	GetBoundBox(&Box);
	for(int i = 0; i < n; i++)
	{
		if(IsInside(Box.m_X1 + rand() % int( abs(Box.m_X1 - Box.m_X2)), Box.m_Y1 + rand() % int( abs(Box.m_Y1 - Box.m_Y2)))) count++;
	}
	return abs(Box.m_X1 - Box.m_X2) * abs(Box.m_Y1 - Box.m_Y2)* count / n;
}

bool CGrpObject::IsIntersect(CGrpObject *pObj)
{
	bool a, b;
	C2DBox Box;
	int count = 0, n = 1000;
	GetBoundBox(&Box);

	for(int i = 0; i < n; i++)
	{
		a = IsInside(Box.m_X1 + rand() % int(abs(Box.m_X1 - Box.m_X2)), Box.m_Y1  + rand() % int(abs(Box.m_Y1 - Box.m_Y2)));
		b = pObj -> IsInside(Box.m_X1 + rand() % int(abs(Box.m_X1 - Box.m_X2)), Box.m_Y1  + rand() % int(abs(Box.m_Y1 - Box.m_Y2)));
		if(a && b) return true;
	}
	return false;
}