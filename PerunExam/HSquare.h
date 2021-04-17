#pragma once
#include "HRectangle.h"
class HSquare: public HRectangle
{
public:
	HSquare(Point p, double a);
	HSquare(HRectangle r);
	~HSquare();

	const Point&   apexA() { return HRectangle::apexA(); };
	const Point&  apexB() { return HRectangle::apexB(); };
	const Point&  apexC() { return HRectangle::apexC(); };
	const Point&  apexD() { return HRectangle::apexD(); };

	const double& const getW() { return _w; };

	HSquare& setA(Point p);
	HSquare& setB(Point p);
	HSquare& setC(Point p);
	HSquare& setD(Point p);

private:
	Point _a;
	double _w;

	HSquare& setW(double w) {
		_w = w;
		return *this;
	}
};
ostream& operator<<(ostream& os, HSquare& s);

