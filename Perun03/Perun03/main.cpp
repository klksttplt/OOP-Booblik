#include <iostream>
#include "Date.h"

using namespace std;

int main() {
	try {
		cout << "Default date:" << endl;
		Date::showDefault();
		cout << "New default:" << endl;
		Date::setDefault(25, Date::Month(2), 2002);
		Date::showDefault();
		cout << "Reset default:" << endl;
		Date::setDefault();
		Date::showDefault();
		cout << " " << endl;
		
		Date d1(12, 4, 2021);
		Date d2(28, Date::Month(2), 1987);
		cout << "Dates: d1 - " << d1 << ", d2 - " << d2 <<  endl;
		cout << "d1--, d2++" << endl;
		d1--;
		d2++;
		cout << "After:" << d1 << ", " << d2 << endl;
		Date d3(28,2,2004);
		cout << " " << endl;
		cout << "Change date:" << endl;
		d1.setDay(25);
		d1.setDYear(1892);
		cout << "d1 after: " << d1 << endl;
		cout << " " << endl;
		cout << "Leap year: d3 - " << d3 << endl;
		cout << "d3++" << endl;
		d3++;
		cout << "After: " << d3 << endl;
		cout << "d3++" << endl;
		d3++;
		cout << "After: " << d3 << endl;
		cout << "d3--" << endl;
		d3--;
		cout << "After: " << d3 << endl;
		Date d4(31, 12, 2020);
		cout << " " << endl;
		cout << "End year: d4 - " << d4 << endl;
		cout << "d4++" << endl;
		d4++;
		cout << "After: " << d4 << endl;
		cout << "d4--" << endl;
		d4--;
		cout << "After: " << d4 << endl;
		cout << " " << endl;
		cout << "Wrong date:" << endl;
		Date d5(100, 100, 100);
	
	}

	catch (Date::BadDate bd)
	{
		cerr << bd.badMessage()<<endl;
	}
	return 0;
}