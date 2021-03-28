#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {

	cout << "------>Creating triangle t1 from coordinates:" << endl;
	Triangle t1(1,1,4,2,5,1);
	cout << "------>Creating triangle t2 from points:" << endl;	Point a(7,1);
	Point b(-2, 3.5);
	Point c(0, 0);
	Triangle t2(a,b,c);
	cout << "------>Copying triangle t3 from another one:" << endl;
	Triangle t3(t1);
	cout << "------>t1=t2:" << endl;
	t1 = t2;
	cout << "------> t1 = " << t1 << endl;
	cout << "------>Creating medians:" << endl;
	cout << "------>Median to side A:" << t1.medianA()<<endl;
	cout << "------>Median to side B:" << t1.medianB() << endl;
	cout << "------>Median to side C:" << t1.medianC() << endl;
	cout << "------>Sides:"  << endl;
	cout << "------>Side A:" << t1.sideA() << endl;
	cout << "------>Side B:" << t1.sideB() << endl;
	cout << "------>Side C:" << t1.sideC() << endl;
	cout << "------>Deleting stuff:" << endl;
}