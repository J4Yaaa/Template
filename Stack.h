#pragma once
#include "List.h"
#include "Vector.h"

template <class T,class Container> //缺省参数
class Stack
{
public:
    void Push(const T& x)
    {
        _con.PushBack(x);
    }

    void Pop()
    {
        _con.PopBack();
    }

    const T& Top()
    {
        return _con.Back();
    }

    bool Empty()
    {
        return _con.Empty();
    }

    size_t Size()
    {
        return _con.Size();
    }

    void Print()
    {
        _con.Show();
    }
protected:
    Container _con;
};

//template <class T,template<class> class Container = Vector>
//class Stack
//{
//public:
//    void Push(const T& x)
//    {
//        _con.PushBack(x);
//    }
//
//    void Pop()
//    {
//        _con.PopBack();
//    }
//
//    const T& Top()
//    {
//        return _con.Back();
//    }
//
//    bool Empty()
//    {
//        return _con.Empty();
//    }
//
//    size_t Size()
//    {
//        return _con.Size();
//    }
//
//    void Print()
//    {
//        _con.Show();
//    }
//protected:
//    Container<T> _con;
//};
