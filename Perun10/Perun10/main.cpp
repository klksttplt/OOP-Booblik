
#include <iostream>
#include "Sequence.h"
using namespace std;


int main()
{
	try {
		cout << "------->Testing:" << endl;
		cout << "------->Creating empty sequence of size 10:" << endl;
		Sequence<int> s1(10);
		cout << "------->Adding elements:" << endl;
		s1.add(0).add(1).add(2).add(3).add(4).add(5);
		cout << "------->Sequence: " <<s1 << endl;
		cout << "------->Capacity: " << s1.capacity() << endl;
		cout << "------->Size: " << s1.size() << endl;
		cout << "------->Adding elements again:" << endl;
		s1.add(6).add(7).add(8).add(9).add(10).add(11);
		cout << "------->Sequence: " << s1 << endl;
		cout << "------->Capacity: " << s1.capacity() << endl;
		cout << "------->Size: " << s1.size() << endl;
		cout << "------->Cutting:" << endl;
		s1.cut();
		s1.cut();
		s1.cut();
		cout << "------->Sequence after cutting: " << s1 << endl;
		cout << "------->Capacity: " << s1.capacity() << endl;
		cout << "------->Size: " << s1.size() << endl;

		cout << "------->Inserting 10 to index 3:" << endl;
		s1.insert(10, 3);
		cout << "------->Sequence after inserting: " << s1 << endl;
		cout << "------->Capacity: " << s1.capacity() << endl;
		cout << "------->Size: " << s1.size() << endl;
		cout << "------->Inserting 10 to the end:" << endl;
		s1.insert(10, s1.size());
		cout << "------->Sequence after inserting: " << s1 << endl;
		cout << "------->Capacity: " << s1.capacity() << endl;
		cout << "------->Size: " << s1.size() << endl;
		cout << "------->Removing first element:" << endl;
		s1.remove(1);
		cout << "------->Sequence after removing: " << s1 << endl;
		cout << "------->Capacity: " << s1.capacity() << endl;
		cout << "------->Size: " << s1.size() << endl;
		cout << "------->Sequence contains 10:" << (s1.contains(10) ? "true" : "false") <<endl;
		cout << "------->Sequence contains 100:" << (s1.contains(100)? "true":"false") << endl;
	}
	catch (Sequence<int>::BadSeq err) {
		err.diagnose();
	}
	
	return 0;
}