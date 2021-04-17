#include "HSquare.h"
#pragma warning(disable : 4227)
HSquare::HSquare(Point p, double a) :
	HRectangle(p, abs(a), abs(a)), _a(p), _w(abs(a))
{
#ifndef NDEBUG
	cout << "Created square: " << endl;
#endif
	return;
}
HSquare::HSquare( HRectangle r):
	HRectangle(r.apexA(), r.biggerSide(), r.biggerSide())
{
#ifndef NDEBUG
	cout << "Created square out of rectangle: " << endl;
#endif
	return;
}
HSquare::~HSquare() {}

HSquare& HSquare::setA(Point p)
{
	double tempW = apexD().x() - p.x();
	double tempH = apexB().y() - p.y();
	double temp = min(abs(tempH), abs(tempW));
	if (min(tempH, tempW) < 0) temp *= -1;

	HRectangle::setA(p);
	HRectangle::setB(Point(p.x(), p.y() + temp));
	HRectangle::setC(Point(p.x() + temp, p.y() + temp));
	HRectangle::setD(Point(p.x()+temp, p.y()));

	setW(abs(temp));
	return *this;
}
HSquare& HSquare::setB(Point p)
{
	double tempW = apexD().x() - p.x();
	double tempH = p.y() - apexA().y();
	double temp = min(abs(tempH), abs(tempW));
	if (min(tempH, tempW) < 0) temp *= -1;

	HRectangle::setA(Point(p.x(), p.y() - temp));
	HRectangle::setB(p);
	HRectangle::setC(Point(p.x() + temp, p.y()));
	HRectangle::setD(Point(p.x() + temp, p.y() - temp));

	setW(abs(temp));
	return *this;
}
HSquare& HSquare::setC(Point p)
{
	double tempW = p.x() - apexA().x();
	double tempH = p.y() - apexA().y();
	double temp = min(abs(tempH), abs(tempW));
	if (min(tempH, tempW) < 0) temp *= -1;

	HRectangle::setA(Point(p.x()-temp, p.y() - temp));
	HRectangle::setB(Point(p.x() - temp, p.y()));
	HRectangle::setC(p);
	HRectangle::setD(Point(p.x(), p.y() - temp));

	setW(abs(temp));
	return *this;
}
HSquare& HSquare::setD(Point p)
{
	double tempW = p.x() - apexA().x();
	double tempH = apexB().y() - p.y();
	double temp = min(abs(tempH), abs(tempW));
	if (min(tempH, tempW) < 0) temp *= -1;

	HRectangle::setA(Point(p.x() - temp, p.y() ));
	HRectangle::setB(Point(p.x() - temp, p.y()+temp));
	HRectangle::setC(Point(p.x(), p.y() + temp));
	HRectangle::setD(p);

	setW(abs(temp));
	return *this;
}

ostream& operator<<(ostream& os, HSquare& t) {
	return os << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << ' ' << t.apexD() << "} with side " << t.side_b().length() <<
		 ", area=" << t.area();
}