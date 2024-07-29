#ifndef SINGLELINKEDLIST_SINGLELINKEDLIST_HPP
#define SINGLELINKEDLIST_SINGLELINKEDLIST_HPP
#include <bits/stdc++.h>
#define nl '\n'
using namespace std;


template <class T>
class SingleLinkedList{
private:
    template <class X>
    class Node{
    public:
        T data;
        Node* next;
        Node(T data,Node<X>* next = nullptr):data(data),next(next){}
    };
    Node<T>* head = nullptr;
    Node<T>* last = nullptr;
    unsigned int length = 0;
public:
    SingleLinkedList(){}
    ~SingleLinkedList();
    SingleLinkedList(SingleLinkedList<T> &other);
    void push_back(T info);
    void push_front(T info);
    void pop_back();
    void pop_front();
    void insert_at(T info,int position);
    void remove_at(int position);
    void clear();
    void reverse();
    T& front();
    T& back();
    int size() const;
    bool empty() const;
    SingleLinkedList& operator= (SingleLinkedList &other);

    class Iterator{
    private:
        Node<T>* current;
    public:
        Iterator(Node<T>* start):current(start){}
        T& operator*() const;
        Iterator& operator++();
        bool operator != (const Iterator& other) const;
    };

    Iterator begin() const{
        return Iterator(head);
    }
    Iterator end() const{
        return Iterator(nullptr);
    }
};

#endif