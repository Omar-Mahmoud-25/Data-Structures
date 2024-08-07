#ifndef BST_HPP
#define BST_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class BST
{
private:
    template <class X>
    class Node{
    public:
        X data;
        Node *left = nullptr,*right = nullptr,*parent = nullptr;
        Node(X data):data(data){}
    };
    Node<T>* root = nullptr;
    int numberOfNodes = 0;
    Node<T>* getMin(Node<T> *node);
    Node<T>* getMax(Node<T> *max);
    Node<T>* getParent(Node<T>* curr);
    void remove(Node<T>* node);
    void removeWithTwoChildren(Node <T>* node);
    int height(Node<T>* node) const;
    void inOrderTraversal(Node<T>* node) const;
    void inReversedOrderTraversal(Node<T>* node) const;
    void preOrderTraversal(Node<T>* node) const;
    void postOrderTraversal(Node<T>* node) const;
    void visit(Node<T>* node) const;
public:
    BST();
    ~BST();
    void insert(T val);
    void remove(T val);
    bool find(T val) const;
    void clear();
    int size() const;
    int height() const;
    void inOrderTraversal() const;
    void inReversedOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    void breadthFirstTraversal() const;
};

#endif