#include "HTetragon.h"
#pragma warning(disable : 4227)

HTetragon::HTetragon(Point a, Point b, Point c, Point d) :
	_a(a),_b(b),_c(c),_d(d),_ab(nullptr), _bc(nullptr), _cd(nullptr), _da(nullptr)
{
#ifndef NDEBUG
	cout << "Created tetragon: " << *this<< endl;
#endif
	return;
}
HTetragon::HTetragon() : _a(Point(0, 0)), _b(Point(0, 1)), _c(Point(1, 1)), _d(Point(1, 0)) {

}
HTetragon::~HTetragon() {
	/*delete _ab;
	delete _bc;
	delete _cd;
	delete _da;*/
	_ab = nullptr;
	_bc = nullptr;
	_cd = nullptr;
	_da = nullptr;
#ifndef NDEBUG
	cout << "Deleted : " << *this << endl;
#endif
	return;
}


const Segment&  HTetragon::side_a() const
{
	
		_ab = new Segment(_a, _b);
	
	return *_ab;
} 
const Segment&  HTetragon::side_b()const 
{
	
		_bc = new Segment(_b, _c);
	
	return *_bc;
}
const Segment&  HTetragon::side_c() const
{
	
		_cd = new Segment(_c, _d);
	
	return *_cd;
}
const Segment&  HTetragon::side_d() const
{
	
		_da = new Segment(_d, _a);
	
	return *_da;
}

HTetragon& HTetragon::setA(Point p)
{
	_a = p;
	return *this;
}
HTetragon& HTetragon::setB(Point p)
{
	_b = p;
	return *this;
}
HTetragon& HTetragon::setC(Point p)
{
	_c = p;
	return *this;
}
HTetragon& HTetragon::setD(Point p)
{
	_d = p;
	return *this;
}
//cosine theorem
double HTetragon::area() const
{
	return side_a().length() * side_b().length();
	
	/*Segment d1(_a, _c);
	Segment d2(_b, _d);
	double l1 = d1.length();
	double l2 = d2.length();
	double a = side_a().length();
	double angle = (pow(l1/2, 2) + pow(l2/2, 2) - pow(a, 2)) / 2 * l1 * l2;
	double area = 0.5 * l1 * l2 * cos(angle);
	return area;*/
}




bool operator<(HTetragon& t1,const  HTetragon& t2)
{
	if (t1.area() == t2.area()) return false;
	if (t1.side_a().length() < t2.side_a().length() && t1.side_b().length() < t2.side_b().length()) {
		return true;
	}
	else if (t1.side_a().length() == t2.side_a().length() && t1.side_b().length() < t2.side_b().length()) {
		return true;
	}
	else if (t1.side_a().length() < t2.side_a().length() && t1.side_b().length() == t2.side_b().length()) {
		return true;
	}
	return false;
	
}

HTetragon& operator+(HTetragon& t1,  HTetragon& t2)
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

	t1.setA(Point(xmin,ymin));
	t1.setB(Point(xmin, ymax));
	t1.setC(Point(xmax,ymax));
	t1.setD(Point(xmax, ymin));
	return t1;
}

ostream& operator<<(ostream& os,  const HTetragon& t) {
	return os << "Tetragon: {" << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << ' ' << t.apexD() << "} with width " << t.side_b().length() <<
		" and height " << t.side_a().length() <<  ", area=" << t.area();
}