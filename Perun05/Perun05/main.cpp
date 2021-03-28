#include <iostream>
#include "AComplex.h"
#include "TComplex.h"

using namespace std;

int main() {
	cout << "\n----->Creating algebraic numbers:" << endl;
	AComplex a1(1, 1);
	AComplex a2(3, 4);
	cout << "\n----->Creating trigonometric numbers:" << endl;
	TComplex t1(7, 3.14);
	TComplex t2(2, 0);
	cout << "\n----->Copying numbers:" << endl;
	AComplex a3(a1);
	TComplex t3(t2);
	cout << "\n----->Creating numbers from other numbers:" << endl;
	AComplex a4(t1);
	TComplex t4(a2);
	cout << "\n----->a1=a2:" << endl;
	a1 = a2;
	cout << "----->a1:" <<a1<< endl;
	cout << "\n----->t1=t2:" << endl;
	t1 = t2;
	cout << "----->t1:" << t1 << endl;
	cout << "\n----->Addition:"  << endl;
	cout << "----->a1+a2:" << a1 + a2<< endl;
	cout << "----->a1+t1:" << a1+t1<< endl;
	cout << "----->t1+a1:" << t1+a1<<endl;
	cout << "----->t1+t2:" << t1+t2<<endl;
	cout << "----->a1+2:" << a1 + 2 << endl;
	cout << "----->t1+3:" << t1 + 3 << endl;
	cout << "\n----->Substraction:"  << endl;
	cout << "----->a1-a3:" << a1 - a3 << endl;
	cout << "----->a1-t1:" << a1 - t1 << endl;
	cout << "----->t1-a1:" << t1 - a1 << endl;
	cout << "----->t1-t3:" << t1 - t3 << endl;
	cout << "----->a1-2:" << a1 - 2 << endl;
	cout << "----->t1-3:" << t1 - 3 << endl;
	cout << "\n----->Multiplication:" << endl;
	cout << "----->a1*a2:" << a1 * a2 << endl;
	cout << "----->a1*t1:" << a1 * t1 << endl;
	cout << "----->t1*a1:" << t1 * a1 << endl;
	cout << "----->t1*t2:" << t1 * t2 << endl;
	cout << "----->a1*2:" << a1 * 2 << endl;
	cout << "----->t1*3:" << t1 * 3 << endl;
	cout << "\n----->Division:"  << endl;
	cout << "----->a1/a2:" << a1 / a2 << endl;
	cout << "----->a1/t1:" << a1 / t1 << endl;
	cout << "----->t1/a1:" << t1 / a1 << endl;
	cout << "----->t1/t2:" << t1 / t2 << endl;
	cout << "----->a1/2:" << a1 / 2 << endl;
	cout << "----->t1/3:" << t1 / 3 << endl;
	cout << "\n----->t1==t2:" << ((t1 == t2) ? "true":"false") << endl;
	cout << "----->t1!=t2:" << ((t1 != t2) ? "true" : "false") << endl;
	AComplex a5(t4);
	cout << "---->t4==a5:" << ((t4 == a5) ? "true" : "false") << endl;
	cout << "---->t4!=a5:" << ((t4 != a5) ? "true" : "false") << endl;
	cout << "---->a5==a3:" << ((a5==a3) ? "true" : "false") << endl;
	cout << "---->a5!=a3:" << ((a5 != a3) ? "true" : "false") << endl;
	cout << "\n----->Other stuff:" << endl;
	a1 *= a2;
	cout << "----->a1*=a2:" << a1 << endl;
	a1 /= a2;
	cout << "----->a1/=a2:" << a1 << endl;
	t1 += t2;
	cout << "----->t1+=t2:" << t1 << endl;
	t1 -= t2;
	cout << "----->t1-=t2:" << t1 << endl;
	cout << "\n---->Deleting stuff" << endl;


}
