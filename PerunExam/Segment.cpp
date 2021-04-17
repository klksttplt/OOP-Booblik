#include "Segment.h"
#include"Point.h"
#include <math.h>

int Segment::_freeID = 0;

Segment::Segment(const double x1, const double y1,
	const double x2, const double y2) :
	_a(x1, y1), _b(x2, y2), _myId(_freeID++)
{
#ifndef NDEBUG
	cout << "Segment " << _myId << " : " << *this << endl;
#endif
	return;
}

Segment::Segment(const Point& start, const Point& end) :
	_a(start), _b(end), _myId(_freeID++)
{
#ifndef NDEBUG
	cout << "Segment " << _myId << " : " << *this << endl;
#endif
	return;
}

Segment::Segment(const Segment& a) :
	_a(a._a), _b(a._b), _myId(_freeID++)
{
#ifndef NDEBUG
	cout << "Segment " << _myId << " copied: " << *this << endl;
#endif
	return;
}

Segment::~Segment()
{
#ifndef NDEBUG
	cout << "Segment " << _myId << " deleted" << endl;
#endif
	return;
}

Segment& Segment::operator=(const Segment& a)
{
	_a = a._a;
	_b = a._b;
	return *this;
}





double Segment::length() const {
	/*double x = endX() - startX();
	double y = endY() - startY();
	return sqrt(x * x + y * y);*/
	return distancePoints(start(), end());

}

double Segment::distance(const Point& C) const {
	//A,B - ends of segments, C - point
	double AC = distancePoints(start(), C);
	double BC = distancePoints(end(), C);
	double AB = length();
	//angle ABC=90
	if (AC >= sqrt(AB * AB + BC * BC)) {
		return BC;
	}
	//angle CAB=90
	if (BC >= sqrt(AC * AC + AB * AB)) {
		return AC;
	}
	double p = (AB + BC + AC) / 2;
	return 2 * sqrt(p * (p - AC) * (p - BC) * (p - BC)) / AB;
}

const int Segment::getID() const {
	return _myId;
}

ostream& operator<<(ostream& os, const Segment& u)
{
	os << '[' << u.start() << "" << u.end() << ']';
	return os;
}