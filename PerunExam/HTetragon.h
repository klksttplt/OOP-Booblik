#pragma once
#include "Point.h"
#include "Segment.h"
#include <ostream>
class HTetragon
{
public:
	HTetragon(Point a, Point b, Point c, Point d);
	HTetragon();
	~HTetragon();

	

	const Point&  apexA() const { return _a; };
	const Point&  apexB() const { return _b; };
	const Point&  apexC() const { return _c; };
	const Point&  apexD() const { return _d; };

	const Segment&  side_a()const;
	const Segment&  side_b()const;
	const Segment&  side_c()const;
	const Segment&  side_d()const;

	HTetragon& setA(Point p);
	HTetragon& setB(Point p);
	HTetragon& setC(Point p);
	HTetragon& setD(Point p);

	double area() const ;
private:
	Point _a, _b, _c, _d;
	mutable Segment * _ab, * _bc, * _cd, * _da;

};

bool operator<(HTetragon& t1, const HTetragon& t2);
HTetragon& operator+(HTetragon&,  HTetragon& );
ostream& operator<<(ostream& os,  const HTetragon& t);

