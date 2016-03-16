#pragma once
class C2DBox
{
	
	public:
		void Draw(CDC &dc);
		C2DBox(void);
		C2DBox(double X1, double Y1, double X2, double Y2);
		virtual ~C2DBox(void);	
		double m_X1;
		double m_X2;
		double m_Y1;
		double m_Y2;
	protected:
		
};