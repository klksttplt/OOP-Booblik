#pragma once
#include <cassert>
#include <string>
#include "Array.h"


template<class Elem>
class Sequence {
public:
	class BadSeq;

	explicit Sequence(const size_t capacity = _default) :
		_size(0), _allocator(new Array<Elem>(capacity))
	{
#ifndef NDEBUG
		cout << "Created sequence of capacity " << capacity << endl;
#endif
	};
	~Sequence() {
#ifndef NDEBUG
		cout << "Deleted sequence" << endl;
#endif
		delete _allocator;
	};

	size_t capacity() const { return _allocator->size(); }
	size_t size() const { return _size; }
	bool empty() const { return (size() == 0); }
	bool full() const { return size() == capacity(); }

	Sequence& clear()
	{
#ifndef NDEBUG
		cout << "Cleared the sequence" << endl;
#endif 
		_size = 0;
		return *this;
	}

	const Elem& operator[](const size_t index) const {
		if (empty())
			throw BadSeq("Error! You tried to manipulate the empty sequence");
		if (index > _size)
			throw BadSeq("Try to access a non existing element of the sequence");
		return (*_allocator)[index];
	};
	Elem& operator[](const  size_t index) {
		if (empty())
			throw BadSeq("Error! You tried to manipulate the empty sequence");
		if (index > _size)
			throw BadSeq("Try to access a non existing element of the sequence");
		return (*_allocator)[index];
	};
	Sequence& add(const Elem& elem) {
		return doinsert(elem, _size);
	};
	Sequence& insert(const Elem& elem, const  size_t index) {
		if (size() < index)
			throw BadSeq("Error! Attempt to access not existing index of the sequence");
		return doinsert(elem, index);
	};
	Sequence& cut() {
		return doremove(_size);
	};
	Sequence& remove(const size_t index) {
		if ((_size < index) || (index == 0))
			throw BadSeq("Error! Attempt to delete a non existing element of the sequence");
		return doremove(index);
	};
	bool contains(const Elem& elem) {
		for (size_t i = 0; i < _size; i++)
		{
			if (elem == (*_allocator)[i])
				return true;
		}
		return false;
	};

private:
	size_t _size;
	static const size_t _default = 0;
	Array<Elem>* _allocator;

	void reduce(const size_t times = 2) {
		Array<Elem>* newArray = new Array <Elem>(capacity() / times + 1);
		for (size_t i = 0; i < _size; ++i)
			(*newArray)[i] = operator[](i);
		delete _allocator;
		_allocator = newArray;
#ifndef NDEBUG
		cout << "Reduced sequence to the capacity of " << capacity() << endl;
#endif
	};
	void enlarge(const size_t times = 2) {
		Array<Elem>* newArray = new Array<Elem>(capacity() * times + 1);
		for (size_t i = 0; i < _size; ++i)
			(*newArray)[i] = operator[](i);
		delete _allocator;
		_allocator = newArray;
#ifndef NDEBUG
		cout << "Enlarged sequence to the capacity of " << capacity() << endl;
#endif
	};

	Sequence& doinsert(const Elem& elem, const size_t index) {
		assert(index <= _size);
		if (_size <= capacity() / 4)
			reduce();
		if (_size + 1 > capacity())
			enlarge();
		++_size;
		for (size_t i = _size - 1; i > index; --i)
			operator[](i) = operator[](i - 1);
		operator[](index) = elem;
#ifndef NDEBUG
		cout << "Added " << elem << " with index " << index <<endl;
#endif
		return *this;
	};
	Sequence& doremove(const size_t index) {
		assert(index <= _size);
		if (empty()) {
			throw BadSeq("Error! Attempt to manipulate an empty sequence");

		}
		if (_size <= capacity() / 4) {
			reduce();

		}
		--_size;
		for (size_t i = index; (i <= _size) && (i > 0); ++i) {
			operator[](i - 1) = operator[](i);
		}
#ifndef NDEBUG
		cout << "Removed element with index " << index<< endl;
#endif
		return *this;
	};

	Sequence(const Sequence&);
	Sequence& operator=(const Sequence&);
};

template<class Elem>
ostream& operator<<(ostream& os, const Sequence<Elem>& s)
{
	os << "{";
	if (!s.empty())
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			os << s[i] << (i != s.size() - 1 ? ", " : "");
		}
	}
	return os << "}";
}

template<class Elem>
class Sequence<Elem>::BadSeq
{
private:
	string _reason;
public:
	BadSeq(const string reason = "") : _reason(reason)
	{}

	~BadSeq() {}

	void diagnose() const
	{
		cerr << _reason << endl;
	}
};


