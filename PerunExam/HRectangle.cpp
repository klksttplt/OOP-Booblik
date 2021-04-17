#include "HRectangle.h"
#include <math.h>
#pragma warning(disable : 4227)
HRectangle::HRectangle(Point p, double w, double h) : 
HTetragon(p,Point(p.x(), p.y()+abs(h)), Point(p.x()+abs(w), p.y() + abs(h)), Point(p.x()+ abs(w), p.y())), _h(abs(h)),_w(abs(w)),_a(p)
{
#ifndef NDEBUG
	cout << "Created rectangle: " << endl;
#endif
	return;
}

HRectangle::~HRectangle(){}

HRectangle& HRectangle::setA(Point p)
{
	double tempW = apexD().x() - p.x();
	double tempH = apexB().y() - p.y();
	
	HTetragon::setA(p);
	HTetragon::setB(Point(p.x(),p.y()+ tempH));
	HTetragon::setC(Point(p.x()+ tempW, p.y() + tempH));
	HTetragon::setD(Point(p.x()+ tempW, p.y()));

	setW(abs(tempW));
	setH(abs(tempH));
	return *this;
}
HRectangle& HRectangle::setB(Point p)
{
	double tempW = apexD().x() - p.x();
	double tempH = p.y()- apexA().y() ;

	HTetragon::setA(Point(p.x(),p.y()-tempH));
	HTetragon::setB(p);
	HTetragon::setC(Point(p.x() + tempW, p.y()));
	HTetragon::setD(Point(p.x() + tempW, p.y() - tempH));

	setW(abs(tempW));
	setH(abs(tempH));
	return *this;
}
HRectangle& HRectangle::setC(Point p)
{
	double tempW = p.x() - apexA().x();
	double tempH = p.y() - apexA().y();

	HTetragon::setA(Point(p.x()-tempW, p.y() - tempH));
	HTetragon::setB(Point(p.x() - tempW,p.y()));
	HTetragon::setC(p);
	HTetragon::setD(Point(p.x(), p.y() - tempH));

	setW(abs(tempW));
	setH(abs(tempH));
	return *this;
}

HRectangle& HRectangle::setD(Point p)
{
	double tempW = p.x() - apexA().x();
	double tempH = apexB().y()- p.y();

	HTetragon::setA(Point(p.x() - tempW, p.y()));
	HTetragon::setB(Point(p.x() - tempW, p.y()+tempH));
	HTetragon::setC(Point(p.x(), p.y() + tempH));
	HTetragon::setD(p);

	setW(abs(tempW));
	setH(abs(tempH));
	return *this;
}

//double HRectangle::area()
//{
//	return getW() * getH();
//}

double HRectangle::biggerSide()
{
	return max(side_a().length(),side_b().length());
}
HRectangle& operator+(HRectangle& t1, HRectangle& t2)
{
	double xmin = 0;
	double ymin = 0;
	double xmax = 0;
	double ymax = 0;
	if (t1.apexA().x() < t2.apexA().x()) {
		xmin = t1.apexA().x();
	}
	else xmin = t2.apexA().x();

	if (t1.apexC().x() > t2.apexC().x()) {
		xmax = t1.apexC().x();
	}
	else xmax = t2.apexC().x();

	if (t1.apexA().y() < t2.apexA().y()) {
		ymin = t1.apexA().y();
	}
	else ymin = t2.apexA().y();

	if (t1.apexC().y() > t2.apexC().y()) {
		ymax = t1.apexC().y();
	}
	else ymax = t2.apexC().y();

	t1.setA(Point(xmin, ymin));
	t1.setB(Point(xmin, ymax));
	t1.setC(Point(xmax, ymax));
	t1.setD(Point(xmax, ymin));
	return t1;
}
ostream& operator<<(ostream& os, HRectangle& t) {
	return os << "Rectangle: {" << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << ' ' << t.apexD() << "} with width " << t.side_b().length() <<
		" and height " << t.side_a().length() << ", area=" << t.area();

}