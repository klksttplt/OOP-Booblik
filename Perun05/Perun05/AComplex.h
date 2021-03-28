#pragma once
#include <iostream>

class TComplex;

class AComplex
{
public:
	AComplex(double re = 0, double im = 0);
	AComplex(const TComplex&);
	AComplex(const AComplex&);
	~AComplex();

	AComplex& operator= (const AComplex&);

	double& re() { return _re; };
	double& im() { return _im; };

	const double& re() const { return _re; };
	const double& im() const { return _im; };

	double mod() const;
	double arg() const;


private:
	double _re, _im;
	int _id;
	static int _freeID;
};

AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator*=(AComplex&, const AComplex&);
AComplex& operator/=(AComplex&, const AComplex&);

const AComplex  operator+ (const AComplex&, const AComplex&);
const AComplex  operator- (const AComplex&, const AComplex&);

bool operator== (const AComplex&, const AComplex&);
bool operator!= (const AComplex&, const AComplex&);



std::ostream& operator<<(std::ostream&, const AComplex&);
