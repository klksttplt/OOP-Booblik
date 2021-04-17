#include <iostream>
#include "HRectangle.h"
#include "HSquare.h"
#include "HTetragon.h"
#include "Point.h"
#include "Container.h"
using namespace std;

int main() {
	
	cout << "---------->Task 1" << endl;
	cout << "---------->Creating rectangle:" << endl;
	Point p1(0,0);
	HRectangle r1(p1, 3, 4);
	cout << "---------->Created rectangle:" << endl;
	cout << r1 << endl;
	cout << "---------->Creating square:" << endl;
	HSquare s1(p1, 4);
	cout << "---------->Created square:" << endl;
	cout << s1 << endl;

	cout << "\n---------->Task 2" << endl;
	cout << "---------->Apexes of rectangle" << endl;
	cout << r1.apexA() << r1.apexB() << r1.apexC() << r1.apexD() << endl;
	cout << "---------->Apexes of square" << endl;
	cout << s1.apexA() << s1.apexB() << s1.apexC() << s1.apexD() << endl;
	cout << "---------->Changing apexes in rectangle:" << endl;
	cout << "---------->Other apexes of rectangle also change so rectangle remains regular:" << endl;
	cout << "---------->changing A:" << endl;
	r1.setA(Point(2, 2));
	cout << r1 << endl;
	cout << "---------->changing B:" << endl;
	r1.setB(Point(3, 4));
	cout << r1 << endl;
	cout << "---------->changing C:" << endl;
	r1.setC(Point(7, 8));
	cout << r1 << endl;
	cout << "---------->changing D:" << endl;
	r1.setD(Point(4, 2));
	cout << r1 << endl;

	cout << "---------->Changing apexes in square:" << endl;
	cout << "---------->Other apexes of square also change so square remains regular:" << endl;
	cout << "---------->changing A:" << endl;
	s1.setA(Point(-1, -1));
	cout << s1 << endl;
	cout << "---------->changing B:" << endl;
	s1.setB(Point(3, 4));
	cout << s1 << endl;
	cout << "---------->changing C:" << endl;
	s1.setC(Point(7, 8));
	cout << s1 << endl;
	cout << "---------->changing D:" << endl;
	s1.setD(Point(4, 2));
	cout << s1 << endl;
	
	cout << "\n---------->Task 3" << endl;
	cout << "---------->You can cast length() for every side" << endl;
	cout << "---------->Sides and area of rectangle:" << endl;
	cout << r1.side_a() << r1.side_b() << r1.side_c() << r1.side_d() << endl;
	cout << "area: " << r1.area() << endl;
	cout << "---------->Sides and area of square:" << endl;
	cout << s1.side_a() << s1.side_b() << s1.side_c() << s1.side_d() << endl;
	cout << "area: " << s1.area() << endl;
	
	cout << "\n---------->Task 4" << endl;
	HRectangle r2(p1,5,2);
	HRectangle r3(p1, 2, 5);
	HSquare s2(p1, 2);
	HSquare s3(p1, 1);
	cout << "r2 "<<r2 << endl;
	cout << "r3 " << r3 << endl;
	cout << "s2 " << s2 << endl;
	cout << "s3 " << s3 << endl;
	cout << "Is r2<r3 " << (r1 < r2 ? " true" : " false") << endl;
	cout << "Is r3<r2 " << (r3 < r2 ? " true" : " false") << endl;
	cout << "Is s2<r3 " << (s2 < r3 ? " true" : " false") << endl;
	cout << "Is s3<r3 " << (s3 < r3 ? " true" : " false") << endl;
	cout << "---------->Constructor of square for r2" << endl;
	HSquare s4(r2);
	cout << "s4 " << s4 << endl;

	cout << "\n---------->Task 5 - already demonstrated" << endl;

	cout << "\n---------->Task 6" << endl;
	cout << "r2+r3 " << r2 + r3 << endl;
	cout << "s2+s3 " << s2 + s3 << endl;
	cout << "s4+r3 " << s4 + r3 << endl;
	
	cout << "\n---------->Task 7" << endl;
	cout << "Creating container and adding all tetragons:" << endl;
	try {
		Container<HTetragon> c1;
		c1.add(r1).add(r2).add(r3).add(s1).add(s2).add(s3).add(s4);
		cout << c1 << endl;
		cout << "\n---------->Task 8" << endl;
		HSquare test1(Point(1, 1), 4);
		Container<HTetragon> c2;
		cout << "Tetragons less than " << test1 << " : " << endl;
		c1.lesser(test1, c2);
		cout << c2 << endl;
		cout << "\n---------->Task 9" << endl;
		cout << "Uniting c2:" << endl;
		HRectangle test2(p1, 0, 0);
		c2.unite(test2);
		cout << test2 << endl;
		
	}
	catch (const Container<HTetragon>::BadSeq& b)
	{
		b.diagnose();
	}

	
	
	
}