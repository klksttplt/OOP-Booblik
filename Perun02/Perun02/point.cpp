#include "point.h"

int Point::_freeID = 0;

Point::Point(const double x, const double y) :
	_x(x), _y(y), _pointID(_freeID++)
{
#ifndef NDEBUG
	cout << "Created point: " << *this << " with ID: " << _pointID << endl;
#endif
	return;
}

Point::Point(const Point& a) :
	_x(a._x), _y(a._y), _pointID(_freeID++)
{
#ifndef NDEBUG
	cout << "Created copy of point: " << *this << " with ID: " << _pointID << endl;
#endif
	return;
}

Point::~Point()
{
#ifndef NDEBUG
	cout << "deleted point: " << *this << " with ID: " << _pointID << endl;
#endif
	return;
}

ostream& operator<<(ostream& os, const Point& a) {
	os << '(' << a.x() << ", " << a.y() << ')';
	return os;
}

const Point operator+(const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& u, const Point& v) {
	u.x() += v.x();
	u.y() += v.y();
	return u;
}

bool operator==(const Point& u, const Point& v) {
	return (u.x() == v.x()) && (u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v) {
	return u == v ? false : true;
}

Point& Point::operator= (const Point& p)
{
	_x = p.x();
	_y = p.y();
	return *this;
}

double distancePoints(const Point& a,  const Point& b) {
	double x = b.x() - a.x();
	double y = b.y() - a.y();
	return sqrt(x * x + y * y);
}