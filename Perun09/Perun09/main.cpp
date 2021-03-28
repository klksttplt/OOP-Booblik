#include <iostream>
#include "Array.h"
#include <assert.h>
#include "String.h"

using namespace std;


int main() {
	cout << "-----> Testing array with int" << endl;
	Array<5, int> a1 = Array<5, int>();
	for (int i = 0; i < a1.length(); i++) {
		a1[i] = i;
	}
	cout << "----->Int array: " << a1 << endl;
	cout << "-----> Testing array with my String" << endl;
	Array<5, String> a2 = Array<5, String>();
	for (int i = 0; i < a2.length(); i++) {
		a2[i] = 'a' + i;
	}
	cout << "----->String array: " << a2 << endl;

	try {
		cout << "-----> Testing bad index" << endl;
		cout << a1[6];
	}
	catch (Array<5, int>::BadArray& error) {
		error.diagnose();
	}

	cout << "-----> Testing different types" << endl;
	cout << "-----> Double to int" << endl;
	a1[0] = 0.5;
	cout << a1 << endl;
	cout << "-----> Double to String" << endl;
	a2[0] = 12;
	cout << a2 << endl;

	Array<5, int> a3 = Array<5, int>();
	for (int i = 0; i < a3.length(); i++) {
		a3[i] = i * 2;
	}

	cout << "-----> Assigning" << endl;
	cout << "-----> a1=a3 before:" << endl;
	cout << a1 << endl;
	cout << a3 << endl;
	cout << "-----> a1=a3 after:" << endl;
	a1 = a3;
	cout << a1 << endl;
	cout << a3 << endl;
	cout << "-----> Destructors" << endl;
	return 0;
}