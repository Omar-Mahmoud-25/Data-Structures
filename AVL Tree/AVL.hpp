#ifndef AVL_HPP
#define AVL_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class AVL
{
    template <class X>
    class Node
    {
    public:
        T data;
        int height, BF;
        Node *left, *right;
        Node(X data) : data(data), height(0), BF(0), left(nullptr), right(nullptr) {}
    };
    Node<T> *root;
    int numberOfNodes = 0;

    Node<T>* getMin(Node<T>* node);
    Node<T>* getMax(Node<T>* node);
    Node<T>* rightRotate(Node<T> *curr);
    Node<T>* leftRotate(Node<T> *curr);
    Node<T>* insert(Node<T> *curr, T value);
    Node<T>* getParent(Node<T> *curr);
    Node<T>* balance(Node<T> *node);
    void update(Node<T> *node);
    void remove(Node<T> *curr, T value);
    void remove(Node<T> *curr);
    void removeWithTwoChildren(Node<T> *curr);
    int height(Node<T>* node) const;
    void inOrderTraversal(Node<T>* node) const;
    void inReversedOrderTraversal(Node<T>* node) const;
    void preOrderTraversal(Node<T>* node) const;
    void postOrderTraversal(Node<T>* node) const;
    void visit(Node<T>* node) const;

public:
    AVL():root(nullptr){}
    ~AVL();
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