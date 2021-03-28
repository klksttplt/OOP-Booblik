#pragma once
#include "Time.h"
#include "Date.h"
#include <ctime>
#include <Windows.h>

using namespace std;

class Timer
{
private:
	Time& _interval;
	void checkInterval();

public:
	Timer(Time& interval);
	~Timer();
	Timer& operator=(const Timer&);
	void turnOn();

	Time interval() const;
	Time& interval();
};