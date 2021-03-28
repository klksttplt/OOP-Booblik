
#include "TComplex.h"
#include "AComplex.h"
using namespace std;

int TComplex::_freeID = 0;

TComplex::TComplex(double r, double angle) :
	_r(r), _angle(angle), _id(++_freeID) {
#ifndef NDEBUG
	cout << "Created trigonometric complex number: " << *this << " with ID: " << _id << endl;
#endif
	return;
}

TComplex::TComplex(const TComplex& t) :
	_r(t.mod()), _angle(t.arg()), _id(++_freeID) {
#ifndef NDEBUG
	cout << "Copied trigonometric complex number: " << *this << " with ID: " << _id << endl;
#endif
	return;
}

TComplex::TComplex(const AComplex& a) :
	_r(a.mod()), _angle(a.arg()), _id(++_freeID) {
#ifndef NDEBUG
	cout << "Created trigonometric complex number from algebraic: " << *this << " with ID: " << _id << endl;
#endif
	return;
}
TComplex::~TComplex() {
#ifndef NDEBUG
	cout << "Deleted trigonometric complex number: " << *this << " with ID: " << _id << endl;
#endif
	return;
}

TComplex& TComplex::operator= (const TComplex& a) {
	_r = a.mod();
	_angle = a.arg();
	return *this;
}

double TComplex::re() const {
	return cos(_angle) * _r;
}
double TComplex::im() const {
	return sin(_angle) * _r;
}
TComplex& operator+= (TComplex& a, const TComplex& b)
{
	AComplex aa(a);
	AComplex bb(b);
	aa += bb;
	a = aa;
	return a;
}

TComplex& operator-= (TComplex& a, const TComplex& b)
{
	AComplex aa(a);
	AComplex bb(b);
	aa -= bb;
	a = aa;
	return a;
}
TComplex& operator*=(TComplex& a, const TComplex& b) {
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;
}
TComplex& operator/=(TComplex& a, const TComplex& b) {
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
}

const TComplex operator* (const TComplex& a, const TComplex& b) {
	TComplex c(a);
	return c *= b;
}
const TComplex operator/ (const TComplex& a, const TComplex& b) {
	TComplex c(a);
	return c /= b;
}

ostream& operator<<(ostream& os, const TComplex& a) {
	return os << a.mod() << "(cos(" << a.arg() << ")" << " + sin(" << a.arg() << ")i)";
}