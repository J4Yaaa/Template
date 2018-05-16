#pragma once

template <class T>
struct ListNode
{
	T _data;
	ListNode* _next;
	ListNode* _prev;
	ListNode(T x) :_data(x), _next(nullptr), _prev(nullptr)
	{}
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	List();
	~List();
	List(const List<T>& l);
	List<T>& operator=(List<T> l);

	void PushBack(const T& value);
	void PopBack();
	void PushFront(const T& value);
	void PopFront();
	void Insert(Node* pos,const T& value);
	void Erase(Node* pos);
    bool Empty();
    const T& Back() const;
    const T& Front() const;

	void Show();
protected:
	Node* _head;
};
