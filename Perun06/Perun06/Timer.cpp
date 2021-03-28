#include "Timer.h"
#pragma warning(disable : 4996)
Timer::Timer( Time& interval) :
	_interval(interval)
{
	checkInterval();
}

Timer::~Timer()
{

}

Timer& Timer::operator=(const Timer& tr)
{
	_interval = tr.interval();
	return *this;
}

#pragma warning(disable : 4996)
void Timer::checkInterval()
{
	if (static_cast<int>(_interval) <0) {
		throw "Invalid interval";
	}
}


Time Timer::interval() const
{
	return _interval;
}

Time& Timer::interval()
{
	return _interval;
}

void Timer::turnOn()
{
	
	Time interval = _interval;
	cout << "Starting timer for "<<interval << endl;
	do {
		Sleep(1000);
		cout << static_cast<int>(interval) << endl;
		--interval;
	} while (static_cast<int>(interval));
	cout << "ALARM" << endl;
}