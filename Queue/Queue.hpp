#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include "..\SingleLinkedList\SingleLinkedList.cpp"
using namespace std;

template <class T>
class Queue{
private:
    SingleLinkedList<T> queue;
public:
    Queue();
    ~Queue();
    void enqueue(T data);
    void dequeue();
    bool empty();
    int size();
    T front();
    void clear();
};

#endif