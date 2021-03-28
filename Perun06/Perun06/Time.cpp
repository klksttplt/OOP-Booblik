
#include "Time.h"
#pragma warning(disable : 4996)


Time::Time(int h, int m, int s) :
	_hours(h), _minutes(m), _seconds(s)
{
	normalizeTime();
}

Time::~Time() {

}

Time::Time(const Time& t) :
	_seconds(t.seconds()), _minutes(t.minutes()), _hours(t.hours())
{

}

void Time::normalizeTime()
{
	_hours += ((_minutes + (_seconds / 60)) / 60);
	_minutes = (_minutes + (_seconds / 60)) % 60;
	_seconds %= 60;
	if (_seconds < 0)
	{
		--_minutes;
		_seconds = 59;
		if (_minutes < 0)
		{
			--_hours;
			_minutes = 59;
		}
	}

}

void Time::setCurrent() {
	struct tm* today = new tm;
	time_t timer;

	time(&timer);
	today = gmtime(&timer);

	_hours = today->tm_hour+2;
	_minutes = today->tm_min;
	_seconds = today->tm_sec;
}


Time& Time::operator=(const Time& t)
{
	_seconds = t.seconds();
	_minutes = t.minutes();
	_hours = t.hours();
	return *this;
}

Time::operator int() const
{
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const
{
	double mins = _minutes + 59. / _seconds;
	double hrs = _hours + 59. / mins;
	return hrs;
}

int Time::hours() const
{
	return _hours;
}

int Time::minutes() const
{
	return _minutes;
}

int Time::seconds() const
{
	return _seconds;
}

int& Time::hours()
{
	normalizeTime();
	return _hours;
}

int& Time::minutes()
{
	normalizeTime();
	return _minutes;
}

int& Time::seconds()
{
	normalizeTime();
	return _seconds;
}

const Time& Time::operator++()
{
	++_seconds;
	normalizeTime();
	return *this;
}

const Time Time::operator++(int)
{
	Time temp = *this;
	++* this;
	return temp;
}

const Time& Time::operator--()
{
	--_seconds;
	normalizeTime();
	return *this;
}

const Time Time::operator--(int)
{
	Time temp = *this;
	--* this;
	return temp;
}

double operator+(const Time& t1, const Time& t2)
{
	Time res = Time();
	res.seconds() = t1.seconds() + t2.seconds();
	res.minutes() = t1.minutes() + t2.minutes();
	res.hours() = t1.hours() + t2.hours();
	return static_cast<double> (res);
}

ostream& operator<<(ostream& out, const Time& t)
{
	return out <<t.hours() << ":" << t.minutes() << ":" << t.seconds();
}

bool operator==(const Time& t1, const Time& t2)
{
	return t1.seconds() == t2.seconds() && t1.minutes() == t2.minutes() && t1.hours() == t2.hours();
}

bool operator!=(const Time& t1, const Time& t2)
{
	return !(t1 == t2);
}

bool operator==(const Time& t1, const struct tm* t2)
{
	return t1.hours() == t2->tm_hour + 2 && t1.minutes() == t2->tm_min && t1.seconds() == t2->tm_sec;
}

bool operator!=(const Time& t1, const struct tm* t2)
{
	return !(t1 == t2);
}

bool operator==(const struct tm* t2, const Time& t1)
{
	return t1 == t2;
}

bool operator!=(const struct tm* t2, const Time& t1)
{
	return !(t1 == t2);
}