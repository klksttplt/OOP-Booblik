#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
#include <math.h>
#include <io.h>
#include <assert.h>

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3),
	_ab(nullptr), _bc(nullptr), _ca(nullptr),
	_middle_a(0,0), _middle_b(0,0), _middle_c(0,0),
	_median_a(nullptr),  _median_b(nullptr),  _median_c(nullptr)
{
	assert(area()!=0);
#ifndef NDEBUG
	cout << "Created triangle: " << *this << endl;
#endif
	return;
}
Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
	_a(a), _b(b), _c(c),
	_ab(nullptr), _bc(nullptr), _ca(nullptr),
	_middle_a(0, 0), _middle_b(0, 0), _middle_c(0, 0),
	_median_a(nullptr), _median_b(nullptr), _median_c(nullptr)
{
	assert(area() != 0);
#ifndef NDEBUG
	cout << "Created triangle: " << *this << endl;
#endif
	return;
}
Triangle::Triangle(const Triangle& t) :
	_a(t._a), _b(t._b), _c(t._c),
	_ab(nullptr), _bc(nullptr), _ca(nullptr),
	_middle_a(0, 0), _middle_b(0, 0), _middle_c(0, 0),
	_median_a(nullptr), _median_b(nullptr), _median_c(nullptr)
{
#ifndef NDEBUG
	cout << "Copied triangle: " << *this << endl;
#endif
	return;
}

Triangle::~Triangle() {
	delete _ab;
	delete _bc;
	delete _ca;
	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;
	
	delete _median_a;
	delete _median_b;
	delete _median_c;
	_median_a = nullptr;
	_median_b = nullptr;
	_median_c = nullptr;
#ifndef NDEBUG
	cout << "Deleted triangle: " << *this << endl;
#endif
	return;
}
//sides are not copied to avoid creating new points and segments
//they would be created anyway when you call for sideA/B/C() methods
Triangle& Triangle::operator=(const Triangle& t)
{
	delete _ab;
	delete _bc;
	delete _ca;
	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;
	
	delete _median_a;
	delete _median_b;
	delete _median_c;
	_median_a = nullptr;
	_median_b = nullptr;
	_median_c = nullptr;

	_a = t.apexA();
	_b = t.apexB();
	_c = t.apexC();

	_middle_a = t.middleA();
	_middle_b = t.middleB();
	_middle_c = t.middleC();
	return *this;
}


const Segment& Triangle::sideA() const {
	if (!_bc) {
		_bc = new Segment(_b, _c);
	}
	return *_bc;
}
const Segment& Triangle::sideB() const {
	if (!_ca) {
		_ca = new Segment(_a, _c);
	}
	return *_ca;
}
const Segment& Triangle::sideC() const {
	if (!_ab) {
		_ab = new Segment(_a, _b);
	}
	return *_ab;
}

double Triangle::lengthA() const {
	return sideA().length();
}
double Triangle::lengthB() const {
	return sideB().length();
}
double Triangle::lengthC() const {
	return sideC().length();
}

void calcMiddle(const Point &startP, const Point &endP, Point& mid) {
	double xm = (startP.x() + endP.x()) / 2;
	double ym = (startP.y() + endP.y()) / 2;
	mid.x() = xm;
	mid.y() = ym;
}
const Segment& Triangle::medianA() const {
	if (!_median_a) {
		calcMiddle(_b, _c, _middle_a);
		_median_a = new Segment(_a, _middle_a);
	}
	return *_median_a;
}
const Segment& Triangle::medianB() const {
	if (!_median_b) {
		calcMiddle(_a, _c, _middle_b);
		_median_b = new Segment(_b, _middle_b);
	}
	return *_median_b;
}
const Segment& Triangle::medianC() const {
	if (!_median_c) {
		calcMiddle(_a, _b, _middle_c);
		_median_c = new Segment(_c, _middle_c);
	}
	return *_median_c;
}

double Triangle::perimeter() {
	return lengthA()+lengthB()+lengthC();
}
double Triangle::area() {
	double p = 0.5 * perimeter();
	return sqrt(p * (p - lengthA()) * (p - lengthB()) * (p - lengthC()));
}
ostream& operator<<(ostream& os, const Triangle& t)
{
	return os << "Triangle: {" << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << "}";
}