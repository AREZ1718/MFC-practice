#pragma once

#include "C2DBox.h"

class CGrpObject{
	public:
		CGrpObject(void);
		void Move(double dx, double dy);
		

		virtual void Draw(CDC &dc) = 0;
		virtual bool IsInside(double x, double y) = 0;
		virtual ~CGrpObject(void);		
		virtual double GetA() = 0;
		virtual double GetA1() = 0;
		virtual double GetA2() = 0;
		virtual double GetA3() = 0;
		virtual double GetAng() = 0;
		virtual int GetType() = 0;
		virtual bool Set(double A, double A1, double A2, double A3, double Angle) = 0;
		virtual void GetBoundBox(C2DBox *pBox) = 0;
		virtual double GetSquare();
		virtual bool IsIntersect(CGrpObject *pObj);
	protected:
		double m_dCenterX;
		double m_dCenterY;
};
