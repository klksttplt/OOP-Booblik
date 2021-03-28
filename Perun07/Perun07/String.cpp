#include "String.h"


//to avoid the same code every time i want to copy one string to another
void String::copy(char* str, const char* source, size_t len)
{
	for (size_t i = 0; i < len; ++i)
		str[i] = source[i];
	str[len] = '\0';
}

String::String() :
	_len(0), _allocator(new char[1])
{
	_allocator[0] = '\0';
#ifndef NDEBUG
	cout << "Created empty string: " << *this << endl;
#endif
	return;
}

String::String(const char c) :
	_len(1), _allocator(new char[2])
{
	_allocator[0] = c;
	_allocator[1] = '\0';
#ifndef NDEBUG
	cout << "Created 1-symbol string: " << *this << endl;
#endif
	return;
}
String::String(const char* str)
{
	if (str == 0)
		throw BadString("Bad string: null string");
	_len = strlen(str);
	_allocator = new char[_len + 1];
	copy(_allocator, str, _len);
#ifndef NDEBUG
	cout << "Created string from char*: " << *this << endl;
#endif
	return;
}

String::String(const string& s) :
	_len(s.length()), _allocator(new char[s.length() + 1])
{
	copy(_allocator, s.c_str(), s.length());
#ifndef NDEBUG
	cout << "Created string from stl-string: " << *this << endl;
#endif
	return;
}

String::String(const String& s, const unsigned int multiplayer) :
	_len(s._len* multiplayer), _allocator(new char[_len + 1])
{
	char* target = _allocator;
	for (unsigned int i = 0; i < multiplayer; i++) {
		copy(target, s._allocator, s._len);
		target += s._len;
	}
#ifndef NDEBUG
	cout << "String copied " << multiplayer << " times: " << *this << endl;
#endif
	return;
}

String::~String()
{
	
#ifndef NDEBUG
	cout << "String deleted: " << *this << endl;
#endif

	delete[] _allocator;
}

const string String::stl_string() const
{
	return string(_allocator);
}

const char* String::c_str() const
{
	return _allocator;
}

char& String::operator[](size_t i) {
	if ((i < 0) || (_len <= i))
		throw BadString("Bad string: index out of range: ", i);
	return _allocator[i];
};

const char& String::operator[](const size_t i) const {
	if (_len <= i)
		throw BadString("Bad string: index out of range: ", i);
	return _allocator[i];
}

bool String::operator==(const String& s) const
{
	bool equal = _len == s._len;
	if (equal == false)return false;
	for (unsigned int i = 0; (i < _len) && equal; i++)
		equal = *(_allocator + i) == s[i];
	return equal;
}

bool String::operator==(const string& s) const {
	bool equal = _len == s.length();
	if (equal == false)return false;
	for (unsigned int i = 0; (i < _len) && equal; i++)
		equal = *(_allocator + i) == s[i];
	return equal;
}

bool String::operator!=(const String& s) const {
	return !(*this == s);
}
bool String::operator!=(const string& s) const {
	return !(*this == s);
}

String& String::operator=(const String& s)
{
	if (this == &s)
	{
		return *this;
	}
	delete[] _allocator;
	_len = s.length();
	_allocator = new char[_len + 1];
	copy(_allocator, s.c_str(), _len);
#ifndef NDEBUG
	cout << "Assigned string from string: " << *this << endl;
#endif
	return *this;
}

String& String::operator=(const string& s)
{
	if (*this == s)
	{
		return *this;
	}
	delete[] _allocator;
	_len = s.length();
	_allocator = new char[_len + 1];
	copy(_allocator, s.c_str(), _len);
#ifndef NDEBUG
	cout << "Assigned string from stl-string: " << *this << endl;
#endif
	return *this;
}

String& String::operator=(const char* str)
{
	if (str == 0)
		throw BadString("Bad string: null string");
	delete[] _allocator;
	for (_len = 0; str[_len]; _len++);
	_allocator = new char[_len + 1];
	copy(_allocator, str, _len);
#ifndef NDEBUG
	cout << "Assigned string from char*: " << *this << endl;
#endif
	return *this;
}
String& String::operator=(const char c)
{
	delete[] _allocator;
	_len = 1;
	_allocator = new char[2];
	_allocator[0] = c;
	_allocator[1] = '\0';
#ifndef NDEBUG
	cout << "Assigned string from 1-symbol string: " << *this << endl;
#endif
	return *this;
}

String& String::operator+=(const String& s) {
	size_t len = _len + s._len;
	char* temp = new char[len + 1];
	copy(temp, _allocator, _len);
	delete[] _allocator;
	_allocator = temp;
	copy(_allocator + _len, s._allocator, s._len);
	_len = len;
	return *this;
}

String String::operator+(const String& s) const
{
	String res(*this);
	return res += s;
}

String& String::operator+=(const char* ps) {
	if (ps == 0)
		throw BadString("Bad string: null str");
	size_t len = strlen(ps);
	char* temp = new char[len + _len + 1];
	copy(temp, _allocator, _len);
	delete[] _allocator;
	_allocator = temp;
	copy(_allocator + _len, ps, len);
	_len += len;
	return *this;
}

String String::operator+(const string& s) const {
	String res(*this);
	return res += s;
}

String& String::operator+=(const string& s)
{
	size_t len = _len + s.length();
	char* temp = new char[len + 1];
	copy(temp, _allocator, _len);
	delete[] _allocator;
	_allocator = temp;
	copy(_allocator + _len, s.c_str(), s.length());
	_len = len;
	return *this;
}

ostream& operator<<(ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++)
		os << s[i];
	return os;
}