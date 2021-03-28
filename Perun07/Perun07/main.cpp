#include <iostream>
#include <string>
#include "String.h"

using namespace std;

int main() {
	try {
		cout << "---------->Creating strings:" << endl;
		String s1("my string s1");
		string s2("stl string s2");
		cout << s2 << endl;
		String s3('s');
		String s4("Multiple string");
		String s5(s4, 3);
		cout << "---------->Assigning:" << endl;
		s1 = s2;
		s1 = 'a';
		s1 = s5;
		s1 = "Char string";
		cout << "---------->to stl and to c:" << endl;
		s1 = "My string";
		cout << "stl_string: " << s1.stl_string() << endl;
		cout << "c_str:" << s1.c_str() << endl;
		cout << "---------->Emptying string:" << endl;
		cout<<(s1.empty()? "string is empty":"string is not empty") <<endl;
		s1.clear();
		cout << (s1.empty() ? "string is empty" : "string is not empty") << endl;
		cout << "---------->Operator[]:" << endl;
		s1 = "Before";
		s1[0] = ' ';
		s1[1] = 'A';
		s1[3] = 't';
		s1[4] = 'e';
		s1[5] = 'r';
		cout << s1 << endl;
		cout << "---------->Equal:" << endl;
		cout << s1 << " and " << s2 << (s1 == s2 ? " are equal" : " are not equal") << endl;
		cout << s1 << " and " << s2 << (s1!=s2 ? " are not equal" : " are equal") << endl;
		s1 = s2;
		cout << s1 << " and " << s2 << (s1 == s2 ? " are equal" : " are not equal") << endl;
		cout << s1 << " and " << s2 << (s1 != s2 ? " are not equal" : " are equal") << endl;
		cout << "---------->Addition:" << endl;
		cout << s1 << " + " << s3 << " = " << s1 + s3 << endl;
		cout << s1 << " + " << "abc" << " = " << s1 + "abc" << endl;
		cout << s1 << " + " << s2 << " = " << s1 + s2 << endl;
		cout << "---------->Destructors:" << endl;
	}
	catch (String::BadString bs) {
		bs.badString();
		}
	
	
}