#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Timer.h"
#include "Watch.h"

using namespace std;

int main() {

	Date d;//today
	Time t;//current time
	cout << "Current day and time:" << d << ":" << t << endl;
	d.setDefault();
	t.setCurrent();
	//enter your interval for timer and time for watch here
	Time watch(22, 00, 01);//time for watch
	Time interval = Time(0, 0, 3);//interval for timer
	
	try {
		cout << "TIMER:" << endl;
		Timer* tr = new Timer(interval);
		tr->turnOn();
		delete tr;
		tr = nullptr;
		
		cout << "WATCH:" << endl;
		Watch* w = new Watch(d,watch);
		w->turnOn();
		delete w;
		w = nullptr;
	}
	catch (char const* err) {
		cout << err << endl;
	}
	return 0;
}