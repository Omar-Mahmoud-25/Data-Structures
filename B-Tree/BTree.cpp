#include <iostream>
#include "BTree.hpp"
using namespace std;

// not completed yet


template <typename T, size_t N>
int BTree<T, N>::numberOfNodes(){
    return numOfNodes;
}

template <typename T, size_t N>
BTree<T, N>::BTree(){}

template <typename T, size_t N>
BTree<T, N>::~BTree(){
    this->clear(root);
}

template <typename T, size_t N>
void BTree<T, N>::clear(Node* node){
    if (node == nullptr)
        return;
    for (int i = 0; i<N+1; ++i)
        if (node->children[i])
            clear(node->children[i]);
    deleteNode(node);
}

template <typename T, size_t N>
void BTree<T, N>::deleteNode(Node* node){
    if (node == nullptr)
        return;
    delete[] node->children;
    delete[] node->data;
    delete node;
}

template <typename T, size_t N>
void BTree<T, N>::clear(){
    return clear(root);
}

template <typename T, size_t N>
void BTree<T, N>::print(){
    return depthFirst(root,0);
}

template <typename T, size_t N>
void BTree<T, N>::depthFirst(Node* node, int numOfTabs){
    if (node == nullptr)
        return;

    for (int i = 0; i<numOfTabs; ++i)
        cout << "   ";
    for (int i = 0; i<node->size-1; ++i)
        cout << node->data[i] << ',';
    cout << node->data[node->size-1] << '\n';

    for (int i = 0; i<=N; ++i)
        depthFirst(node->children[i],numOfTabs+1);
    return ;
}

template <typename T, size_t N>
void BTree<T, N>::insert(T data){
    ++numOfData;
    if (root == nullptr){
        root = new Node(data);
        numOfNodes = 1;
    }
    else
        insert(root,data);
}

template <typename T, size_t N>
void BTree<T, N>::insert(Node* node, T data){
    for (int i = 0; i<=node->size; ++i){
        if (i == node->size || node->data[i] > data){
            if (node->children[i])
                return insert(node->children[i],data);
            else{
                for (int j = node->size; j > i; --j)
                    node->data[j] = node->data[j-1];                
                node->data[i] = data;
                ++node->size;
                if (node->size == N)
                    split(node);
                
                return;
            }
        }
    }
}

template <typename T, size_t N>
void BTree<T, N>::split(Node* node){
    ++numOfNodes;
    Node* parent = node->parent;
    int mid = ((N-1)>>1);
    if (parent == nullptr){
        ++numOfNodes;
        root = new Node();
        parent = root;
    }
    int newPosition = 0;
    for (int i = 0; i<parent->size; ++i)
        if (parent->data[i] < node->data[mid] && (i == parent->size-1 || parent->data[i+1] > node->data[mid]))
            newPosition = i+1;
    for (int i = node->size; i > newPosition; --i){
        parent->data[i] = parent->data[i-1];
        parent->children[i+1] = parent->children[i];
    }
    parent->data[newPosition] = node->data[mid];
    parent->children[newPosition] = new Node();
    for (int i = 0; i<mid; ++i){
        parent->children[newPosition]->data[i] = node->data[i];
        parent->children[newPosition]->children[i] = node->children[i];
    }
    parent->children[newPosition]->children[mid] = node->children[mid];
    parent->children[newPosition+1] = new Node();
    for (int i = mid+1,j = 0; i<N; ++i,++j){
        parent->children[newPosition+1]->data[j] = node->data[i];
        parent->children[newPosition+1]->children[j] = node->children[i];
    }
    parent->children[newPosition+1]->children[N-mid] = node->children[N];

    parent->children[newPosition]->size = mid;
    parent->children[newPosition+1]->size = N-mid-1;
    parent->children[newPosition]->parent = parent;
    parent->children[newPosition+1]->parent = parent;

    ++parent->size;
    deleteNode(node);
    if (parent->size == N)
        split(parent);
}