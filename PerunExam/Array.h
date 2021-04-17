#pragma once

#include <iostream>
#include <string>
using namespace std;

template <class Elem>
class Array
{
private:
    const size_t _size;
    Elem* _allocator;
    Array(const Array&);
    Array& operator=(const Array&);
public:
    class BadArray;

    explicit Array(size_t size);
    ~Array();

    Elem& operator[](const size_t index);
    const Elem& operator[](const size_t index) const;

    size_t size() const;
};

template <class Elem>
ostream& operator<<(ostream& os, const Array<Elem>& array)
{
    os << "[ ";
    for (size_t i = 0; i < array.size(); ++i)
    {
        os << array[i] << ", ";
    }
    os << " ]";
    return os;
}


template <class Elem>
class Array<Elem>::BadArray
{
private:
    string _reason;
    size_t _index;
public:
    explicit BadArray(const string& reason = "", const size_t index = 0) :
        _reason(reason), _index(index)
    {}
    ~BadArray() {
#ifndef NDEBUG
        cout << "Deleted bad array" << endl;
#endif
    }
    void diagnose() const
    {
        cout << "Reason: " << _reason << endl << "Index: " << _index << endl;
    }
};

template <class Elem>
Array<Elem>::Array(size_t size) :
    _size(size), _allocator(new Elem[size])
{
#ifndef NDEBUG
    cout << "Created array of size: " << _size << endl;
#endif
}

template <class Elem>
Array<Elem>::~Array()
{
#ifndef NDEBUG
    cout << "Deleted array" << endl;
#endif
    delete[] _allocator;
}

template <class Elem>
Elem& Array <Elem>::operator[](const size_t index)
{
    if (index < 0 || index >= _size) {
        throw BadArray("Index out of bounds: ", index);
    }
    return _allocator[index];
}

template <class Elem>
const Elem& Array <Elem>::operator[](const size_t index) const
{
    if (index < 0 || index >= _size) {
        throw BadArray("Index out of bounds: ", index);
    }
    return _allocator[index];
}

template<class Elem>
size_t Array<Elem>::size() const {
    return _size;
}