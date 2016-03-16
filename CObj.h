#pragma once
#include "CGrpObject.h"
class CMy2DObject9 : public CGrpObject{

public:
	CMy2DObject9(double x, double y, double A, double A1, double A2, double A3, double dAngle);
	~CMy2DObject9(void);

public:
	double GetA();
	double GetA1();
	double GetA2();
	double GetA3();
	double GetAng();
	bool Set(double A, double A1, double A2, double A3, double Angle);	 
	void Draw(CDC &dc);
	bool IsInside(double x, double y);
	void Move(double dx, double dy);
	int GetType();
	void GetBoundBox(C2DBox *pBox);
protected:
	double m_A;
	double m_A1;
	double m_A2;
	double m_A3;
	double m_dAngle;
	
};
