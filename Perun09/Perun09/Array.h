#pragma once

#include <iostream>
using namespace std;

template<size_t n, class Elem>

class Array {
private:
	Elem* _alloc;
	size_t _length;

public:
	class BadArray;

	explicit Array() : _length(n) {
		_alloc = new Elem[_length]();
		#ifndef NDEBUG
		cout << "Created array of size: " <<_length<<" "<<*this<< endl;
		#endif
	}

	Array(const Array& from) : _length(from.length()) {
		delete[] _alloc;
		_alloc = nullptr;
		_alloc = new Elem[_length]();
		for (size_t i = 0; i < _length; i++) {
			_alloc[i] = from[i];
		}
		#ifndef NDEBUG
		cout << "Copied array: " <<* this << endl;
		#endif
	}

	~Array() {
		delete[] _alloc;
		_alloc = nullptr;
		#ifndef NDEBUG
		cout << "Deleted array" << endl;
		#endif
	}


	const Elem& operator[](const size_t index) const {

		if (index < _length) {
			return _alloc[index];
		}
		else {
			throw BadArray("Index out of bounds: ", index);
		}
	}

	Elem& operator[](const size_t index) {
		if (index < _length) {
			return _alloc[index];
		}
		else {
			throw BadArray("Index out of bounds ", index);
		}
	}

	Array& operator=(const Array& ar) {
		delete[] _alloc;
		_alloc = nullptr;
		_alloc = new Elem[ar.length()]();
		for (size_t i = 0; i < ar.length(); i++) {
			_alloc[i] = ar[i];
		}
		return *this;
	}

	const size_t length() const {
		return _length;
	}

};

template<size_t n, class Elem>

class Array<n, Elem>::BadArray {
private:
	string _reason;
	size_t _index;
public:

	explicit BadArray(string reason = "", const size_t index = 0) {
		_reason = reason;
		_index = index;
#ifndef NDEBUG
		cout << "Bad array" << endl;
#endif
	}

	~BadArray() {
#ifndef NDEBUG
		cout << "Deleted bad array" << endl;
#endif
	}

	void diagnose() const {
		cout << "Reason: " << _reason << endl << "Index: " << _index << endl;
	}

};

template<size_t n, class Elem>
ostream& operator<<(ostream& os, const Array<n, Elem>& array) {
	os << "[";
	for (size_t i = 0; i < array.length(); i++) {
		os << array[i] << ", ";
	}
	return os << "]";
};