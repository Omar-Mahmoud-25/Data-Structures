#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class RedBlackTree{
    
    class Node{
    public:
        T data;
        bool black;
        Node *left, *right, *parent;
        Node(T data) :
            data(data),
            black(false),
            left(nullptr),
            right(nullptr),
            parent(nullptr) {}
        
    };
    Node *root;
    int numberOfNodes = 0;

    Node* rightRotate(Node *curr);
    Node* leftRotate(Node *curr);
    void handleTwoAdjacentRedNodes(Node *curr);
    void remove(Node *curr, T value);
    void removeNode(Node *curr);
    void handleDoubleBlack(Node* curr);
    int height(Node* node) const;
    void inOrderTraversal(Node* node) const;
    void inReversedOrderTraversal(Node* node) const;
    void preOrderTraversal(Node* node) const;
    void postOrderTraversal(Node* node) const;
    void visit(Node* node) const;

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