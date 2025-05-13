#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <bits/stdc++.h>
#include "Queue.hpp"
using namespace std;
#endif

template <class T>
Queue<T>::Queue(){}

template <class T>
Queue<T>::~Queue(){this->clear();}

template <class T>
void Queue<T>::enqueue(T data){
    return queue.push_back(data);
}

template <class T>
void Queue<T>::dequeue(){
    return queue.pop_front();
}

template <class T>
bool Queue<T>::empty(){
    return queue.empty();
}

template <class T>
int Queue<T>::size(){
    return queue.size();
}

template <class T>
T Queue<T>::front(){
    return queue.front();
}

template <class T>
void Queue<T>::clear(){
    queue.clear();
}