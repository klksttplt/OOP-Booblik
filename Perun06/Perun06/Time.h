#pragma once

#include <iostream>

using namespace std;

class Time
{

private:

	int _hours;

	int _minutes;

	int _seconds;

	

	void normalizeTime();

public:

	explicit Time(int h = 0, int m = 0, int s = 0);

	Time(const Time&);

	~Time();

	void setCurrent();

	Time& operator=(const Time&);

	explicit operator int() const;

	explicit operator double() const;

	int hours() const;

	int minutes() const;

	int seconds() const;


	int& hours();

	int& minutes();

	int& seconds();

	const Time& operator++();

	const Time operator++(int);

	const Time& operator--();

	const Time operator--(int);

};
double operator+(const Time&, const Time&);

ostream& operator<<(ostream&, const Time&);

bool operator==(const Time& t1, const Time& t2);

bool operator!=(const Time& t1, const Time& t2);

bool operator==(const Time&, const struct tm*);

bool operator!=(const Time&, const struct tm*);

bool operator==(const struct tm*, const Time&);

bool operator!=(const struct tm*, const Time&);