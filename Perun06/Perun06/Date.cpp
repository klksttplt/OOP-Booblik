#include "Date.h"
#include <time.h>
#include <iostream>
#pragma warning(disable : 4996)

Date Date::defaultDate = Date();

string Date::monthNames[] = { "January", "February", "March", "April", "May", "June", "July", "August",
							 "September","October", "November", "December" };
bool Date::defaultSet = false;

Date::Date(int d, Month m, int y)
{
	fillDate(d, m, y);
}

Date::Date(int d, int m, int y)
{
	fillDate(d, Month(m), y);
}

Date::Date(const Date& date)
{
	fillDate(date.day(), date.month(), date.year());
}

Date::~Date()
{

}

bool Date::leapYear(int y)
{
	bool leap;
	if (y % 4) leap = false;
	else if (y % 100) leap = true;
	else if (y % 400) leap = false;
	else leap = true;
	return leap;
}
bool Date::thirty(Month month)
{
	return month == Month(4) || month == Month(6) || month == Month(9) || month == Month(11);
}

bool Date::thirtyOne(Month month)
{
	return month == Month(1) || month == Month(3) || month == Month(5) || month == Month(7) || month == Month(8) || month == Month(10) || month == Month(12);
}
//check if date is valid
void Date::checkDate(int day, Month month, int year)
{
	if (day > 0) {
		if (month == Month(2)) {
			if (!leapYear(year) && day > 28) {
				throw BadDate(day, month, year);
			}
			else if (leapYear(year) && day > 29) {
				throw BadDate(day, month, year);
			}
		}
		else if (thirty(month) && day > 30) {
			throw BadDate(day, month, year);
		}
		else if (thirtyOne(month) && day > 31) {
			throw BadDate(day, month, year);
		}
		else if (month < 0 || month > 12) {
			throw BadDate(day, month, year);
		}
	}
	else {
		throw BadDate(day, month, year);
	}
}

void Date::fillDate(int d, Date::Month m, int y) {
	/*checkDate(d, m, y);
	defaultDate._day = d;
	defaultDate._month = m;
	defaultDate._year = y;*/
	if (!defaultSet) setDefault();
	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y : defaultDate._year;
	checkDate(_day, Date::Month(_month), _year);
}

void Date::setDefault(int day, Month month, int year) {

	checkDate(day, month, year);
	defaultDate._day = day;
	defaultDate._month = month;
	defaultDate._year = year;
	defaultSet = true;
}

void Date::setDefault()
{
	struct tm* today = new tm;
	time_t timer;

	time(&timer);
	today = gmtime(&timer);

	defaultDate._day = today->tm_mday;
	defaultDate._month = ++(today->tm_mon);
	defaultDate._year = today->tm_year += 1900;
	defaultSet = true;
}



void Date::setDay(int d) {
	checkDate(d, Month(_month), _year);
	_day = d;
}
void Date::setMonth(int m) {
	checkDate(_day, Month(m), _year);
	_month = Month(m);
}
void Date::setDYear(int y) {
	checkDate(_day, Month(_month), y);
	_year = y;
}

void Date::showDefault() {
	if (!defaultSet) {
		defaultSet = true;
		setDefault();
	}
	cout << defaultDate << endl;
}

const string Date::getMonthName() const {
	return monthNames[_month - 1];
}
//for operators
void Date::endMonth() {
	//feb
	if (_month == 2)
	{
		//++
		if (_day > 29 && leapYear(_year))
		{
			_day = 1;
			_month++;
		}
		else if (_day > 28 && !leapYear(_year))
		{
			_day = 1;
			_month++;
		}
	}
	//--
	else if (_month == 3) {
		if (_day < 1)
		{
			if (leapYear(_year))
			{
				_day = 29;
				_month--;
			}
			else
			{
				_day = 28;
				_month--;
			}
		}
	}

	//not feb
		//--
	else if (_day < 1)
	{
		_month--;
		if (thirty(Month(_month)))
		{
			_day = 30;
		}
		else
		{
			_day = 31;
		}
	}
	//++
	else if ((_day > 30 && (thirty(Month(_month))) || (_day > 31 && (thirtyOne(Month(_month))))))
	{
		_month++;
		_day = 1;
	}

	if (_month < 1) {
		_month = 12;
		_year--;
	}
	if (_month > 12) {
		_month = 1;
		_year++;
	}
}

const Date& Date::operator++()
{
	++_day;
	endMonth();
	return *this;
}

const Date Date::operator++(int)
{
	Date temp = *this;
	++* this;
	return temp;
}

const Date& Date::operator--()
{
	--_day;
	endMonth();
	return *this;
}

const Date Date::operator--(int)
{
	Date temp = *this;
	--* this;
	return temp;
}

ostream& operator<<(ostream& os, const Date& d) {
	return os << d.day() << " " << d.getMonthName() << " " << d.year();
}

ostream& operator<<(ostream& os, const Date::BadDate& bd) {
	return os << bd.badMessage();
};

