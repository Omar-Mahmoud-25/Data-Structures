#ifndef AVL_HPP
#define AVL_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class AVL
{
    class Node
    {
    public:
        T data;
        int height, BF;
        Node *left, *right, *parent;
        Node(T data) :
            data(data),
            height(0),
            BF(0),
            left(nullptr),
            right(nullptr),
            parent(nullptr) {}
    };
    Node *root;
    int numberOfNodes = 0;

    Node* getMin(Node* node);
    Node* getMax(Node* node);
    Node* rightRotate(Node *curr);
    Node* leftRotate(Node *curr);
    Node* insert(Node *curr, T value);
    // Node* getParent(Node *curr);
    Node* balance(Node *node);
    void update(Node *node);
    void remove(Node *curr, T value);
    void remove(Node *curr);
    void removeWithTwoChildren(Node *curr);
    int height(Node* node) const;
    void inOrderTraversal(Node* node) const;
    void inReversedOrderTraversal(Node* node) const;
    void preOrderTraversal(Node* node) const;
    void postOrderTraversal(Node* node) const;
    void visit(Node* node) const;

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