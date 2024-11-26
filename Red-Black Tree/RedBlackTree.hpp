#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class RedBlackTree{
    template <class X>
    class Node{
    public:
        T data;
        bool black;
        Node *left, *right, *parent;
        Node(X data) :
            data(data),
            black(false),
            left(nullptr),
            right(nullptr),
            parent(nullptr) {}
        
    };
    Node<T> *root;
    int numberOfNodes = 0;

    Node<T>* rightRotate(Node<T> *curr);
    Node<T>* leftRotate(Node<T> *curr);
    void handleTwoAdjacentRedNodes(Node<T> *curr);
    void remove(Node<T> *curr, T value);
    void removeNode(Node<T> *curr);
    void handleDoubleBlack(Node<T>* curr);
    int height(Node<T>* node) const;
    void inOrderTraversal(Node<T>* node) const;
    void inReversedOrderTraversal(Node<T>* node) const;
    void preOrderTraversal(Node<T>* node) const;
    void postOrderTraversal(Node<T>* node) const;
    void visit(Node<T>* node) const;

public:
    RedBlackTree():root(nullptr){}
    ~RedBlackTree();
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