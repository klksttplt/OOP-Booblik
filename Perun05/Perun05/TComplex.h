#pragma once
#include <iostream>

class AComplex;

class TComplex
{
public:
	TComplex(double r = 0, double angle = 0);
	TComplex(const AComplex&);
	TComplex(const TComplex&);
	
	~TComplex();

	TComplex& operator= (const TComplex&);

	double& mod() { return _r; };
	double& arg() { return _angle; };

	const double& mod() const { return _r; };
	const double& arg() const { return _angle; };

	double re() const;
	double im() const;

private:
	double _r, _angle;
	static int _freeID;
	int _id;

};
TComplex& operator+=(TComplex& , const TComplex& );
TComplex& operator-=(TComplex& , const TComplex& );
TComplex& operator*=(TComplex& , const TComplex& );
TComplex& operator/=(TComplex& , const TComplex& );

const TComplex operator* (const TComplex&, const TComplex&);
const TComplex operator/ (const TComplex&, const TComplex&);

std::ostream& operator<<(std::ostream&, const TComplex&);