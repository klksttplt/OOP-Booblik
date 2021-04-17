#pragma once
#include <cassert>
#include <string>
#include "Array.h"


template<class Elem>
class Container {
public:
	class BadSeq;

	explicit Container(const size_t capacity = _default) :
		_size(0), _allocator(new Array<Elem>(capacity))
	{
#ifndef NDEBUG
		cout << "Created sequence of capacity " << capacity << endl;
#endif
	};
	~Container() {
#ifndef NDEBUG
		cout << "Deleted sequence" << endl;
#endif
		delete _allocator;
	};

	void lesser(HTetragon& el, Container<Elem>& res) {
		/*res = Container<Elem>();*/
		for (int i = 0; i < size(); ++i) {
			if (operator[](i) < el) {
				res.add(operator[](i));
			}
		}
	};

	void unite(HTetragon& el) {
		for (int i = 0; i < size(); ++i) {
			el + operator[](i);
		}
	};

	size_t capacity() const { return _allocator->size(); }
	size_t size() const { return _size; }
	bool empty() const { return (size() == 0); }
	bool full() const { return size() == capacity(); }

	Container& clear()
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
	Container& add(const Elem& elem) {
		return doinsert(elem, _size);
	};
	Container& insert(const Elem& elem, const  size_t index) {
		if (size() < index)
			throw BadSeq("Error! Attempt to access not existing index of the sequence");
		return doinsert(elem, index);
	};
	Container& cut() {
		return doremove(_size);
	};
	Container& remove(const size_t index) {
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

	Container& doinsert(const Elem& elem, const size_t index) {
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
		cout << "Added " << elem << " with index " << index << endl;
#endif
		return *this;
	};
	Container& doremove(const size_t index) {
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
		cout << "Removed element with index " << index << endl;
#endif
		return *this;
	};

	
	Container& operator=(const Container&);

	
	

};

template<class Elem>
ostream& operator<<(ostream& os, const Container<Elem>& s)
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
class Container<Elem>::BadSeq
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


