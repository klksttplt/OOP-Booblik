#pragma once
#include <string>
#include <ostream>

using namespace std;

class Date

{

public:

	struct BadDate;

	// to avoid problem 7.2.2002 7 feb or jul 2?

	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	explicit Date(int d = 0, Month m = Month(0), int y = 0);

	explicit Date(int d, int m, int y);

	Date(const Date&);

	~Date();

	int day() const {
		return _day;
	};



	int year() const {
		return _year;
	};

	Month month() const {
		return Month(_month);
	};



	const string getMonthName() const;

	void setDay(int);

	void setMonth(int);

	void setDYear(int);

	static void setDefault(int, Month, int);

	static void setDefault();

	static void showDefault();

	const Date& operator++();

	const Date  operator++(int);

	const Date& operator--();

	const Date  operator--(int);

private:



	int _day, _month, _year;

	static bool leapYear(int y);

	static bool thirty(Month);

	static bool thirtyOne(Month);

	void endMonth();

	void fillDate(int d, Month m, int y);

	static string monthNames[12];

	static bool defaultSet;

	static Date defaultDate;

	static void checkDate(int, Month, int);

};

ostream& operator<<(ostream& os, const Date& d);

struct Date::BadDate

{

	int _day, _month, _year;

	BadDate(int d, int m, int y) :_day(d), _month(m), _year(y) {

	}

	string badMessage() const {
		return "Wrong date: " + _day + '.' + _month + '.' + _year;
	}

};
ostream& operator<<(ostream& os, const Date::BadDate& bd);