#ifndef BST_HPP
#define BST_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class BST
{
private:
    class Node{
    public:
        T data;
        Node *left = nullptr,*right = nullptr,*parent = nullptr;
        Node(T data):data(data){}
    };
    Node* root = nullptr;
    int numberOfNodes = 0;
    Node* getMin(Node *node);
    Node* getMax(Node *max);
    Node* getParent(Node* curr);
    void remove(Node* node);
    void removeWithTwoChildren(Node* node);
    int height(Node* node) const;
    void inOrderTraversal(Node* node) const;
    void inReversedOrderTraversal(Node* node) const;
    void preOrderTraversal(Node* node) const;
    void postOrderTraversal(Node* node) const;
    void visit(Node* node) const;
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