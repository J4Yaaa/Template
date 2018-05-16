#include "Vector.h"
#include <iostream>
using namespace std;
#include <assert.h>
#include <string>

template <class T>
Vector<T>::Vector() :_first(NULL), _finish(NULL), _endofstorage(NULL)
{}

template <class T>
Vector<T>::~Vector()
{
	delete[] _first;
	_first = _finish = _endofstorage = NULL;
}

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size_t size = v.Size();
	_first = new T[Capacity()];
	size_t i = 0;
	for (; i < size; ++i)
	{
		_first[i] = v._first[i];
	}
	_finish = _first + size;
	_endofstorage = _first + v.Capacity();
}

template <class T>
Vector<T>& Vector<T>::operator = (Vector<T> v)
{
	swap(_first, v._first);
	swap(_finish, v._finish);
	swap(_endofstorage, v._endofstorage);
	return *this;
}

template <class T>
void Vector<T>::PushBack(const T& value)
{
	Insert(Size(), value);
}

template <class T>
void Vector<T>::PopBack()
{
	Erase(Size() - 1);
}

template <class T>
void Vector<T>::PushFront(const T& value)
{
    Insert(_first,value);
}

template <class T>
void Vector<T>::PopFront()
{
    Erase(0);
}

template <class T>
void Vector<T>::Expand(size_t n)
{
	if (n == 0)
	{
		_first = new T[3];
		_finish = _first;
		_endofstorage = _first + 3;
	}
	else
	{
		T* new_first = new T[n];
		size_t i = 0;
		size_t size = Size();
		for (; i < size; ++i)
		{
			new_first[i] = _first[i];
		}
        swap(_first,new_first);
		_finish = _first + size;
		_endofstorage = _first + n;
	}
}

template <class T>
void Vector<T>::Insert(size_t pos,const T& value)
{
	size_t size = Size();
	size_t capacity = Capacity();
	assert(pos >= 0 && pos <= size);
	if (size + 1 > capacity)
	{
		Expand(capacity * 2);
	}
	int i = size - 1;
	for (; i >= (int)pos; --i)
	{
		_first[i + 1] = _first[i];
	}
	_first[pos] = value;
	++_finish;
}

template <class T>
void Vector<T>::Erase(size_t pos)
{
	if (_first == _finish)
	{
		return;
	}
	size_t size = Size();
	/* size_t capacity = Capacity(); */
	assert(pos >= 0 && pos < size);
	size_t i = pos;
	for (; i < size - 1; ++i)
	{
		_first[i] = _first[i + 1];
	}
	--_finish;
}

template <class T>
size_t Vector<T>::Size()const
{
	return _finish - _first;
}

template <class T>
size_t Vector<T>::Capacity()const
{
	return _endofstorage - _first;
}

template <class T>
void Vector<T>::Show()
{
	size_t i = 0;
	size_t size = Size();
	/* size_t capacity = Capacity(); */
	for (; i < size; ++i)
	{
		cout << _first[i] << " ";
	}
	cout << endl;
}

template <class T>
bool Vector<T>::Empty()
{
    return _first == _finish;
}

template <class T>
const T& Vector<T>::Back() const
{
    return *(_finish-1);
}

template <class T>
const T& Vector<T>::Front() const
{
    return *_first;
}

#if 0
int main()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.Show();

	Vector<string> v2;
	v2.PushBack("aaaaaaaaaaaaaaaaaaaaaaaa");
	v2.PushBack("bbbbbbbbbbbbbbbbbbbbbbb");
	v2.PushBack("cccccccccccccccccccccccccccc");
	v2.PushBack("ddddddddddddddddddddddddddddddddddddddd");
	v2.Show();
	return 0;
}
#endif
