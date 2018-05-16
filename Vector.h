#pragma once
#include <stdlib.h>
template <class T>
class Vector
{
public:
	Vector();
	~Vector();
	Vector(const Vector<T>& v);
	Vector<T>& operator = (Vector<T> v);

	void Expand(size_t n);
	void PushBack(const T& value);
	void PopBack();
	void Insert(size_t pos,const T& value);
    void PushFront(const T& value);
    void PopFront();
	void Erase(size_t pos);
    bool Empty();
    const T& Back() const;
    const T& Front() const;

	void Show();

protected:
	size_t Size()const;
	size_t Capacity()const;
protected:
	T* _first;
	T* _finish;
	T* _endofstorage;
};
