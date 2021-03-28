#pragma once

#include <string>
#include <ostream>
#include <iostream>

using namespace std;
class String {
private:
	size_t _len; 
	char* _allocator;
	void copy(char* target, const char* source, size_t len);
public:
	
	class BadString;

	String(); 
	
	
	explicit String(const char*); 
	explicit String(const char);
	explicit String(const string&);
	
	String(const String& s, const unsigned int multiplayer = 1);
	~String(); 
	
	const string stl_string() const;
	const char* c_str() const;
	
	size_t length() const { return _len; }
	bool empty() const { return _len == 0; }
	void clear() { *this = String(); }
	
	char& operator[](const size_t);
	const char& operator[](const size_t) const;
	
	bool operator==(const String&) const;
	bool operator==(const string&) const;
	
	bool operator!=(const String&) const;
	bool operator!=(const string&) const;
	
	String& operator=(const String&);
	String& operator=(const string&);
	String& operator=(const char*);
	String& operator=(const char);
	
	String operator+(const String&) const;
	String operator+(const string&) const;
	String& operator+=(const String&);
	String& operator+=(const string&);
	String& operator+=(const char*);
};

ostream& operator<<(ostream&, const String&);

class String::BadString
{
private:
	string _error;
	size_t _num;
public:
	BadString(string err = "", size_t num = 0) :
		_error(err), _num(num)
	{

	};
	~BadString() {};
	void badString() const
	{
		cerr << _error;
		if (_num != 0)
			cerr << ' ' << _num;
		cerr << endl;
	}
};