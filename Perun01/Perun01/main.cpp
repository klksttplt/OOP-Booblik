#include <iostream>
#include "point.h"

using namespace std;

int main() {
	Point a(2,3);
	Point b(5, 4);
	Point c(7, 7);
	Point d(b);
	cout << "the amount of points is " << Point::amount() << endl;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " += " << b;
	a += b;
	cout << " then " << a << ", " << b << endl;
	cout << "a equal to c: " << (a == c) << endl;
	cout << "a equal to b: "  << (a == b) << endl;
	cout << "a not equal to c: " << (a != c) << endl;
	cout << "a not equal to b: " << (a != b) << endl;
	cout << "ID of Point a: " << a.getID() << endl;
	return 0;
}