#include "Watch.h"
#include <ctime>
#pragma warning(disable : 4996)

bool Watch::badWatch(Date& d, Time& t, tm* today)
{
	if (d.year() < today->tm_year + 1900) {
		return true;
	}
	else if (d.month() - 1 > today->tm_mon) {
		return true;
	}
	else if (d.day() < today->tm_mday) {
		return true;
	}
	else if (t.hours() >= 24) {
		return true;
	}
	else if (t.hours() - 2 < today->tm_hour) {
		return true;
	}
	else if (t.minutes() < today->tm_min && t.hours() - 2 < today->tm_hour) {
		return true;
	}
	else if (t.seconds() < today->tm_sec&& t.minutes() == today->tm_min && t.hours() - 2== today->tm_hour) {
		return true;
	}
	return false;
}

void Watch::checkWatch() {
	struct tm* today = new tm;
	time_t timer;
	time(&timer);
	today = gmtime(&timer);

	if (badWatch(date(), ttime(), today)) {
		throw "Invalid watch";
	}
}
Date Watch::date() const
{
	return _date;
}

Watch::Watch(Date& d, Time& t) :
	_date(d), _time(t) {
	checkWatch();
}
Watch::~Watch()
{

}
void Watch::turnOn() {
	auto* td = new tm;
	time_t timer;
	time(&timer);
	td = gmtime(&timer);
	cout << "Starting watch for: " << date() << " : " << ttime() << endl;

	while ((td->tm_mday != date().day() && td->tm_mon+1 != date().month()&& td->tm_year + 1900 !=date().year() )|| td != ttime()) {
		time(&timer);
		td = gmtime(&timer);
		Sleep(1000);
		cout << td->tm_mday << "." << td->tm_mon + 1 << "." << td->tm_year + 1900 << "|" << td->tm_hour << ":"
			<< td->tm_min << ":" << td->tm_sec << endl;
	}
	cout << "ALARM" << endl;
}

Watch& Watch::operator=(const Watch& w)
{
	_date = w.date();
	_time = w.ttime();
	return *this;
}
Time Watch::ttime() const
{
	return _time;
}
Date& Watch::date()
{
	return _date;
}

Time& Watch::ttime()
{
	return _time;
}
