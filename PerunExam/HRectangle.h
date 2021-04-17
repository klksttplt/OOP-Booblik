#pragma once
#include "HTetragon.h"
class HRectangle : public HTetragon
{
public:
	HRectangle(Point p, double a, double b);
	~HRectangle();

	const Point& const  apexA() { return HTetragon::apexA(); };
	const Point& const apexB() { return HTetragon::apexB(); };
	const Point& const apexC() { return HTetragon::apexC(); };
	const Point& const apexD() { return HTetragon::apexD(); };

	const double& const getW() { return _w; };
	const double& const getH() { return _h; };

	HRectangle& setA(Point p);
	HRectangle& setB(Point p);
	HRectangle& setC(Point p);
	HRectangle& setD(Point p);

	
	double biggerSide();
private:
	Point _a;
	double _w, _h;

	
	HRectangle& setW(double w) {
		_w = w;
		return *this;
	};
	HRectangle& setH(double h) {
		_h = h; 
		return *this;
	};

};
HRectangle& operator+(HRectangle&, HRectangle&);
ostream& operator<<(ostream& os, HRectangle& r);

