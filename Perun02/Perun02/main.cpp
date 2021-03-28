#include <iostream>
#include "point.h"
#include "segment.h"

using namespace std;

int main() {
	Segment a(1,2,3,4);
	Point p1(0, 0);
	Point p2(12.6, 21);
	Point p3(11, 2);
	Segment b(p1, p2);

	cout << "------------>The lenth of " << a << " is " << a.length() << endl;
	cout << "------------>The distance between segment " << b<<" and point " << p1<<  " is " << b.distance(p1) << endl;
	cout << "------------>The distance between segment " << b << " and point " << p3 << " is " << b.distance(p3) << endl;

	cout << "------------>Before:" << a << endl;
	a.startX() = 2;
	a.startY() = 14.2;
	a.endX() = 16;
	a.endY() = 56;
	cout << "------------>After:" << a << endl;
	
	cout << "------------>Segment a before:" << a << endl;
	a = b;
	cout << "------------>Segment a after (a=b)" << a << endl;

}