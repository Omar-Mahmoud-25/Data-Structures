#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.hpp"
using namespace std;
#endif
template <typename T>
Stack<T>::Stack(){}

template <typename T>
Stack<T>::~Stack(){this->clear();}

template <typename T>
void Stack<T>::push(T info){
    return stack.push_front(info);
}

template <typename T>
void Stack<T>::pop(){
    return stack.pop_front();
}

template <typename T>
T Stack<T>::top(){
    return stack.front();
}

template <typename T>
int Stack<T>::size(){
    return stack.size();
}

template <typename T>
bool Stack<T>::empty(){
    return stack.empty();
}

template <typename T>
void Stack<T>::clear(){
    return stack.clear();
}