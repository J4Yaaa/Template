#include <iostream>
using namespace std;
#include "List.h"
#include "Vector.h"
#include "List.cpp"
#include "Vector.cpp"
#include "Stack.h"
#include "Queue.h"

int main()
{
    Stack<char,Vector<int>> s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(200);
    s1.Print();
//    while(!s1.Empty())
//    {
//        cout<<s1.Top()<<endl;
//        s1.Pop();
//    }
//    Queue<int,Vector> q;
//    q.Push(1);
//    q.Push(2);
//    q.Push(3);
//    q.Push(200);
//    while(!q.Empty())
//    {
//        cout<<q.Front()<<endl;
//        q.Pop();
//    }
    return 0;
}
