#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP
#include <bits/stdc++.h>
#define nl '\n'
using namespace std;


template <class T>
class DoubleLinkedList{
private:
    class Node{
    public:
        T data;
        Node* next;
        Node* previous;
        Node(T data,Node* next = nullptr,Node* previous = nullptr):data(data),next(next),previous(previous){}
    };
    Node* head = nullptr;
    Node* last = nullptr;
    unsigned int size = 0;
public:
    DoubleLinkedList(){}
    ~DoubleLinkedList();
    DoubleLinkedList(DoubleLinkedList<T> &other);
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
    int length() const;
    bool empty() const;
    DoubleLinkedList& operator= (DoubleLinkedList &other);

    class Iterator{
    private:
        Node* current;
    public:
        Iterator(Node* start):current(start){}
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