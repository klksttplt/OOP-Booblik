#include "AComplex.h"
#include "TComplex.h"
using namespace std;

int AComplex::_freeID = 0;

AComplex::AComplex(double re, double im) :
	_re(re), _im(im), _id(++_freeID) {
#ifndef NDEBUG
	cout << "Created algebraic complex number: " << *this << " with ID: " << _id << endl;
#endif
	return;
}
AComplex::AComplex(const TComplex& t) :
	_re(t.re()), _im(t.im()), _id(++_freeID) {
#ifndef NDEBUG
	cout << "Created algebraic complex number from trigonometric: " << *this << " with ID: " << _id << endl;
#endif
	return;
}

AComplex::AComplex(const AComplex& a) :
	_re(a.re()), _im(a.im()), _id(++_freeID) {
#ifndef NDEBUG
	cout << "Copied algebraic complex number: " << *this << " with ID: " << _id << endl;
#endif
	return;
}

AComplex::~AComplex() {
#ifndef NDEBUG
	cout << "Deleted algebraic complex number: " << *this << " with ID: " << _id << endl;
#endif
	return;
}

AComplex& AComplex::operator=(const AComplex& a) {
	_re = a.re();
	_im = a.im();
	return *this;
}

double AComplex::mod() const {
	return sqrt(_re * _re + _im * _im);
}

double AComplex::arg() const
{
	return atan(_im / _re);
}

AComplex& operator+=(AComplex& a, const AComplex& b) {
	a.re() += b.re();
	a.im() += b.im();
	return a;
}





AComplex& operator-=(AComplex& a, const AComplex& b) {
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
}
const AComplex operator+(const AComplex& a, const AComplex& b)
{
	AComplex c(a);
	c += b;
	return c;
}

const AComplex  operator- (const AComplex& a, const AComplex& b) {
	AComplex c(a);
	c -= b;
	return c;
}

AComplex& operator*= (AComplex& a, const AComplex& b)
{
	double re = a.re();
	double im = a.im();
	a.re() *= b.re();
	a.re() -= im * b.im();
	a.im() *= b.re();
	a.im() += re * b.im();
	return a;
}

AComplex& operator/=(AComplex& a, const AComplex& b)
{
	double re = a.re();
	double im = a.im();
	a.re() *= b.re();
	a.re() += im * b.im();
	a.re() /= b.re() * b.re() + b.im() * b.im();
	a.im() *= b.re();
	a.im() -= re * b.im();
	a.im() /= (b.re() * b.re() + b.im() * b.im());
	return a;

}
bool operator== (const AComplex& a, const AComplex& b)
{
	return a.re() == b.re() && a.im() == b.im();
}


bool operator!=(const AComplex& a, const AComplex& b)
{
	return !(a == b);
}

ostream& operator<<(ostream& os, const AComplex& a)
{
	return os << a.re() << "+" << a.im() << "i";
}