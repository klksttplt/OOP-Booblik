#include "Screen.h"
#include <iostream>
#pragma warning(disable : 4018)

using namespace std;

const int Screen::maxHeight = 40;
const int Screen::maxWidth = 40;
const char Screen::_filler = '.';

Screen::Screen(int w, int h, char* s) :
	_width(w > maxWidth ? maxWidth : w), _height(h > maxHeight ? maxHeight : h),
	_wContent(new char[_width * _height + 1]), _cursor(0) {
	int scrSize = _height * _width;
	int lens = s == 0 ? 0 : strlen(s);
	lens = lens > scrSize ? scrSize : lens;
	_wContent[scrSize] = '\0';
	int k = 0;
	if (s != 0)
	{
		while (k < lens)
			_wContent[k++] = *s++;

	}
	while (k < scrSize)
		_wContent[k++] = _filler;
}

Screen::~Screen()
{
	delete[] _wContent;
}

const Screen& Screen::home() const
{
	_cursor = 0;
	return *this;
}
Screen& Screen::home()
{
	_cursor = 0;
	return *this;
}

const Screen& Screen::move() const
{
	if ((++_cursor) >= _width * _height)
		_cursor = 0;
	return *this;
}
Screen& Screen::move()
{
	if ((++_cursor) >= _width * _height)
		_cursor = 0;
	return *this;
}

const Screen& Screen::back() const
{
	if (--_cursor < 0)
		_cursor = 0;
	return *this;
}
Screen& Screen::back()
{
	if (--_cursor < 0)
		_cursor = 0;
	return *this;
}

const Screen& Screen::show() const
{
	size_t cursor = _cursor;
	cout << "cursor=" << _cursor << endl; home();
	for (size_t i = 0; i < _height; i++) {
		for (size_t j = 0; j < _width; j++) {
			cout << get(); move();
		}
		cout << endl;
	}
	_cursor = cursor;
	return *this;
}
Screen& Screen::show()
{
	size_t cursor = _cursor; cout << "cursor=" << _cursor << endl; home();
	for (size_t i = 0; i < _height; i++) {
		for (size_t j = 0; j < _width; j++) {
			cout << get(); move();
		}
		cout << endl;
	}
	_cursor = cursor;
	return *this;
}

const Screen& Screen::move(const int x, const int y) const
{

	if ((x < 0) || (y < 0) || (x >= _width) || (y >= _height))
		_cursor = 0;
	else
		_cursor = _width * y + x;
	return *this;
}
Screen& Screen::move(const int x, const int y)
{
	if ((x < 0) || (y < 0) || (x >= _width) || (y >= _height))
		_cursor = 0;
	else
		_cursor = _width * y + x;
	return *this;
}

Screen& Screen::clear()
{
	for (int i = 0; i < _height * _width; i++)
		*(_wContent + i) = _filler;
	_cursor = 0;
	return *this;
}

const Screen& Screen::showCurrent() const
{
	cout << get() << endl;
	return *this;
}

char Screen::get() const
{
	return _wContent[_cursor];
}

Screen& Screen::set(char a)
{
	_wContent[_cursor] = a;
	return *this;
}

ostream& operator<<(ostream& os, const Screen& s)
{
	s.show();
	return os;
}

void doActionConst(const Screen& s, ConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		(s.*act)();
	}
}

void doActionNonConst(Screen& s, NonConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		(s.*act)();
	}
}