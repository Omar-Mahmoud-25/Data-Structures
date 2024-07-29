#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_CPP
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_CPP
#include <bits/stdc++.h>
#include "DoubleLinkedList.hpp"
#define nl '\n'
using namespace std;

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    this -> clear();
}

template <class T>
void DoubleLinkedList<T>::push_back(T data){
    Node<T>* newNode = new Node<T>(data);
    ++size;
    if (head == nullptr)
        return void(head = last = newNode);
    last -> next = newNode;
    newNode -> previous = last;
    last = newNode;
    return;
}

template <class T>
void DoubleLinkedList<T>::push_front(T data){
    ++size;
    if (head == nullptr)
        return void(head = new Node<T>(data));
    Node<T>* newNode = new Node<T>(data,head);
    head -> previous=newNode;
    head = newNode;
    return;
}

template <class T>
void DoubleLinkedList<T>::insert_at(T data,int position){
    if (position < 0 || position > size)
        throw runtime_error("Cannot insert!");
    if (!position)
        return push_front(data);
    if (position == size)
        return push_back(data);
    ++size;
    Node<T> *newNode = new Node<T>(data),*p = head;
    while(--position)
        p = p->next;
    newNode -> next = p -> next;
    newNode -> previous = p;
    p -> next -> previous = newNode;
    p -> next = newNode;
    return;
}

template <class T>
void DoubleLinkedList<T>::pop_front(){
    if (head == nullptr)
        throw runtime_error("Empty List!!");
    Node<T>* newNode = head -> next;
    delete head;
    head = newNode;
    --size;
    return;
}

template <class T>
void DoubleLinkedList<T>::pop_back(){
    if (head == nullptr) 
        throw runtime_error("Empty List!!");
    if (head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* newNode = last;
    last = last->previous;
    delete newNode;
    return;
}

template <class T>
void DoubleLinkedList<T>::remove_at(int position){
    if (position < 0 || position >= size)
        throw runtime_error("Cannot remove!");
    if (!position)
        return pop_front();
    if (position == size-1)
        return pop_back();
    --size;
    Node<T> *newNode,*p = head;
    while(--position)
        p = p->next;
    newNode = p->next;
    p->next = newNode->next;
    newNode -> next -> previous = p;
    delete newNode;
    return;
}

template <class T>
void DoubleLinkedList<T>::reverse(){
    if (head == nullptr)
        throw runtime_error("Cannot reverse an empty list!");
    if (size == 1)
        return;
    Node<T> *prv = nullptr,*current = head,*nxt = head;
    last = head;
    while(current)
        nxt = nxt->next,
        current->next = prv,
        prv = current,
        current = nxt;
    head = prv;
    return;
}

template <class T>
void DoubleLinkedList<T>::clear(){
    if (head == nullptr)
        return;
    size = 0;
    Node <T>* it = head,*node;
    while(it != nullptr)
        node = it,
        it = it->next,
        delete node;
    head = nullptr;
    last = nullptr;
    return;
}

template <class T>
int DoubleLinkedList<T>::length() const{
    return size;
}

template <class T>
bool DoubleLinkedList<T>::empty() const{
    return (!size);
}

template <class T>
T& DoubleLinkedList<T>::front(){
    return head->data;
}

template <class T>
T& DoubleLinkedList<T>::back(){
    return last->data;
}

template <class T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(DoubleLinkedList<T>& other){
    this->clear();
    for (const auto &i:other)
        this->insert_back(i);
    return *this;
}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList& other){
    this->clear();
    for (const auto &i:other)
        this->insert_back(i);
}

template <class T>
T& DoubleLinkedList<T>::Iterator::operator*() const {
    return this->current->data;
}

template <class T>
typename DoubleLinkedList<T>::Iterator&
  DoubleLinkedList<T>::Iterator::operator++(){
    this->current = this->current->next;
    return *this;
}

template <class T>
bool DoubleLinkedList<T>::Iterator::operator!=(const Iterator& other) const{
    return (this->current != other.current);
}

#endif