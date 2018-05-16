#include "List.h"
#include <iostream>
using namespace std;
#include <assert.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

template <class T>
List<T>::List() :_head(new Node(T()))
{
	_head->_next = _head;
	_head->_prev = _head;
}

template <class T>
List<T>::~List()
{
	Node* cur = _head->_next;
	while (cur != _head)
	{
		_head->_next = cur->_next;
		delete cur;
		cur = _head->_next;
	}
	delete _head;
	_head = nullptr;
}

template <class T>
List<T>::List(const List<T>& l) :_head(new Node(T()))
{
	Node* cur = l._head->_next;
	while (cur != _head)
	{
		PushBack(cur->_data);
		cur = cur->_next;
	}
}

template <class T>
List<T>& List<T>::operator=(List<T> l)
{
	swap(_head, l._head);
	return *this;
}

template <class T>
void List<T>::PushBack(const T& value)
{
	Insert(_head, value);
}

template <class T>
void List<T>::PopBack()
{
	Erase(_head->_prev);
}

template <class T>
void List<T>::PushFront(const T& value)
{
	Insert(_head->_next, value);
}

template <class T>
void List<T>::PopFront()
{
	Erase(_head->_next);
}

template <class T>
void List<T>::Insert(Node* pos,const T& value)
{
	assert(pos);
	Node* new_node = new Node(value);
	Node* prev_node = pos->_prev;
	Node* next_node = pos;

	new_node->_prev = prev_node;
	prev_node->_next = new_node;
	new_node->_next = next_node;
	next_node->_prev = new_node;
}

template <class T>
void List<T>::Erase(Node* pos)
{
	assert(pos && _head->_next != _head);

	Node* prev_node = pos->_prev;
	Node* next_node = pos->_next;
	prev_node->_next = next_node;
	next_node->_prev = prev_node;
	delete pos;
}

template <class T>
void List<T>::Show()
{
	Node* cur = _head->_next;
	while (cur != _head)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}

template <class T>
bool List<T>::Empty()
{
    return _head->_next == _head;
}

template <class T>
const T& List<T>::Back() const
{
    return _head->_prev->_data;
}

template <class T>
const T& List<T>::Front() const
{
    return _head->_next->_data;
}

#if 0
int main()
{
	List<int> l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.PrintList();
    return 0;
}
#endif
