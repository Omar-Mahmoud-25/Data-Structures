#ifndef SINGLELINKEDLIST_SINGLELINKEDLIST_CPP
#define SINGLELINKEDLIST_SINGLELINKEDLIST_CPP
#include "SingleLinkedList.hpp"
using namespace std;

template <class T>
SingleLinkedList<T>::~SingleLinkedList(){
    this -> clear();
}

template <class T>
void SingleLinkedList<T>::push_back(T data){
    Node<T>* newNode = new Node<T>(data);
    ++length;
    if (head == nullptr)
        return void(head = last = newNode);
    last->next = newNode;
    last = newNode;
    return;
}

template <class T>
void SingleLinkedList<T>::push_front(T data){
    ++length;
    if (head == nullptr)
        return void(head = last = new Node<T>(data));
    Node<T>* newNode = new Node<T>(data,head);
    head = newNode;
    return;
}

template <class T>
void SingleLinkedList<T>::insert_at(T data,int position){
    if (position < 0 || position > length)
        throw runtime_error("Cannot insert!");
    if (!position)
        return push_front(data);
    if (position == length)
        return push_back(data);
    ++length;
    Node<T> *newNode = new Node<T>(data),*p = head;
    while(--position)
        p = p->next;
    newNode->next = p->next;
    p -> next = newNode;
    return;
}

template <class T>
void SingleLinkedList<T>::pop_front(){
    if (head == nullptr)
        throw runtime_error("Empty List!!");
    Node<T>* newNode = head -> next;
    delete head;
    head = newNode;
    --length;
    return;
}

template <class T>
void SingleLinkedList<T>::pop_back(){
    if (head == nullptr) 
        throw runtime_error("Empty List!!");

    if (head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* last = head,*beforeLast = nullptr;
    while(last -> next != nullptr)
        beforeLast = last,last = last -> next;
    beforeLast -> next = nullptr;
    --length;
    delete last;
    return;
}

template <class T>
void SingleLinkedList<T>::remove_at(int position){
    if (position < 0 || position >= length)
        throw runtime_error("Cannot remove!");
    if (!position)
        return pop_front();
    if (position == length-1)
        return pop_back();
    --length;
    Node<T> *newNode,*p = head;
    while(--position)
        p = p->next;
    newNode = p->next;
    p->next = p->next->next;
    delete newNode;
    return;
}

template <class T>
void SingleLinkedList<T>::reverse(){
    if (head == nullptr)
        throw runtime_error("Cannot reverse an empty list!");
    if (length == 1)
        return;
    Node<T> *previous = nullptr,*curr = head,*nxt = head;
    last = head;
    while(curr)
        nxt = nxt->next,
        curr->next = previous,
        previous = curr,
        curr = nxt;
    head = previous;
    return;
}

template <class T>
void SingleLinkedList<T>::clear(){
    if (head == nullptr)
        return;
    length = 0;
    Node <T>* current = head,*node;
    while(current != nullptr)
        node = current,
        current = current->next,
        delete node;
    head = nullptr;
    last = nullptr;
    return;
}

template <class T>
int SingleLinkedList<T>::size() const{
    return length;
}

template <class T>
bool SingleLinkedList<T>::empty() const{
    return (!length);
}

template <class T>
T& SingleLinkedList<T>::front(){
    if (head == nullptr) 
        cerr << ("Empty List!!");
    return head->data;
}

template <class T>
T& SingleLinkedList<T>::back(){
    if (head == nullptr) 
        throw runtime_error("Empty List!!");
    return last->data;
}

template <class T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(SingleLinkedList<T>& other){
    this->clear();
    for (const auto &i:other)
        this->insert_back(i);
    return *this;
}

template <class T>
SingleLinkedList<T>::SingleLinkedList(SingleLinkedList& other){
    this->clear();
    for (const auto &i:other)
        this->insert_back(i);
}

template <class T>
T& SingleLinkedList<T>::Iterator::operator*() const {
    return this->current->data;
}

template <class T>
typename SingleLinkedList<T>::Iterator&
  SingleLinkedList<T>::Iterator::operator++(){
    this->current = this->current->next;
    return *this;
}

template <class T>
bool SingleLinkedList<T>::Iterator::operator!=(const Iterator& other) const{
    return (this->current != other.current);
}

#endif
