#pragma once
#include "List.h"
#include "Vector.h"

/*template<class T,class Container = List<T>> //默认参数
{
protected:
    Container _con;
}*/

template<class T,template<class> class Container = List>
class Queue
{
public:
    void Push(const T& x)
    {
        _con.PushBack(x);
    }

    void Pop()
    {
        _con.PopFront();
    }

    const T& Front()const
    {
        return _con.Front();
    }

    bool Empty()
    {
        return _con.Empty();
    }

    size_t Size()
    {
        return Size();
    }
protected:
    Container<T> _con;
};
