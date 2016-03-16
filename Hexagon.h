#pragma once
#include "CGrpObject.h"
class CHexagon : public CGrpObject{

public:
	CHexagon(double x, double y, double A);
	~CHexagon(void);

public:
	double GetA();
	double GetA1();
	double GetA2();
	double GetA3();
	double GetAng();
	int GetType();
	bool Set(double A, double A1, double A2, double A3, double Angle);	 
	void Draw(CDC &dc);
	bool IsInside(double x, double y);
	void GetBoundBox(C2DBox *pBox);
protected:
	double m_A;
	
};
