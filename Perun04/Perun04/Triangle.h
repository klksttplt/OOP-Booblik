#pragma once
#include "Point.h"
#include "Segment.h"

class Triangle
{
public:
	Triangle(const double x1 = 0, const double y1 = 0, const double x2 = 1, const double y2 = 0, const double x3 = 0, const double y3 = 1);
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle&);
	~Triangle();
	Triangle& operator= (const Triangle&);
	//apexes
	const Point& apexA() const { return _a; };
	const Point& apexB() const { return _b; };
	const Point& apexC() const { return _c; };
	//sides
	const Segment& sideA() const;
	const Segment& sideB() const;
	const Segment& sideC() const;
	//medians
	const Segment& medianA() const;
	const Segment& medianB() const;
	const Segment& medianC() const;
	//middles
	//i thought i should calculate middles in the constructors or in these methods
	//but then i realized that after conctructor apexes might be changed
	//and to avoid creating too many copies middles are really calculated
	//only when you want to create a median, until then they are (0,0) points
	//not the best decision but we have what we have.....
	const Point& middleA() const { return _middle_a; };
	const Point& middleB() const { return _middle_b; };
	const Point& middleC() const { return _middle_c; };
	//lengts
	double lengthA() const;
	double lengthB() const;
	double lengthC() const;
	//perimeter
	double perimeter();
	//area
	double area();

private:
	mutable Point _a, _b, _c;
	mutable Segment *_ab, *_bc, *_ca;
	mutable Point _middle_a, _middle_b, _middle_c;
	mutable Segment* _median_a, * _median_b, * _median_c;

};

ostream& operator<<(ostream&, const Triangle&);