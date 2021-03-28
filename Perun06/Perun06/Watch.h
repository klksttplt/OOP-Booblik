#pragma once

#include "Time.h"
#include "Date.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

class Watch
{
private:
	Date& _date;
	Time& _time;
	bool badWatch(Date& d, Time& t, tm* today);
	void checkWatch();
public:
	Watch(Date&, Time&);
	~Watch();
	void turnOn();
	Watch& operator=(const Watch&);

	Date date() const;
	Date& date();
	Time ttime() const;
	Time& ttime();

};


