#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP
#include <iostream>
#include "..\SingleLinkedList\SingleLinkedList.cpp"
using namespace std;

template <class T>
class Stack
{
private:
    SingleLinkedList<T> stack;
public:
    void push(T info);
    void pop();
    T top();
    int size();
    bool empty();
    void clear();
    Stack();
    ~Stack();
};

#endif