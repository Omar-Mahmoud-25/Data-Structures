#include "BST.hpp"
using namespace std;

template <class T>
BST<T>::BST(){}

template <class T>
BST<T>::~BST(){this->clear();}

template <class T>
void BST<T>::insert(T val){
    ++numberOfNodes;
    Node<T> *newNode = new Node<T>(val);
    if (root == nullptr)
        return void(root = newNode);
    Node<T> *node = root,*prv = nullptr;
    while(node){
        prv = node;
        if (node->data == val)
            return;
        if (val < node->data)
            node = node->left;
        else 
            node = node->right;
    }
    if (val < prv->data)
        prv -> left = newNode;    
    else 
        prv -> right = newNode;
    newNode->parent = prv;
}

template <class T>
bool BST<T>::find(T val) const{
    Node<T> *node = root;
    while(node)
        if (node->data == val)
            return true;
        else if (val > node->data)
            node = node->right;
        else 
            node = node->left;
    return false;
}

template <class T>
void BST<T>::remove(T val){
    if (root == nullptr)
        return ;
    Node<T> *node = root,*prv = nullptr;
    --numberOfNodes;
    while(node)
        if (node->data == val)
            if (node->left && node->right)
                return removeWithTwoChildren(node);
            else
                return remove(node);
        else if (val < node->data)
            node = node->left;
        else 
            node = node->right;
    return;
}

template <class T>
void BST<T>::remove(Node<T>* node){
    if (node->parent->right == node)
        if (node->right)
            node->parent->right = node->right;
        else if (node->left)
            node->parent->right = node->left;
        else 
            node->parent->right = nullptr;
    else
        if (node->left)
            node->parent->left = node->left;
        else if (node->right)
            node->parent->left = node->right;
        else 
            node->parent->left = nullptr;
    delete node;
    return;
}

template <class T>
void BST<T>::removeWithTwoChildren(Node<T>* node){
    Node<T>* min = getMin(node->right);
    node->data = min->data;
    return remove(min);
}

template <typename T>
typename BST<T>::template Node<T>* BST<T>::getMin(Node<T>* node){
    Node<T>* start = node;
    while(start->left)
        start = start->left;
    return start;
}

template <typename T>
typename BST<T>::template Node<T>* BST<T>::getMax(Node<T>* node){
    Node<T>* start = node;
    while(start->right)
        start = start->right;
    return start;
}

template <class T>
typename BST<T>::template Node<T> *BST<T>::getParent(Node<T> *curr)
{
    if (curr == root || root == nullptr)
        return nullptr;
    Node<T> *node = root;
    while (node)
        if (node->left == curr || node->right == curr)
            return node;
        else if (curr->key < node->key)
            node = node->left;
        else
            node = node->right;
    return nullptr;
}

template <class T>
int BST<T>::size() const{
    return numberOfNodes;
}

template <class T>
void BST<T>::clear(){
    if (root == nullptr)
        return;
    queue <Node<T>*> q;
    q.emplace(root);
    while(!q.empty()){
        Node<T>* node = q.front();
        q.pop();
        if (node->right) 
            q.emplace(node->right);
        if (node->left)
            q.emplace(node->left);
        delete node;
    }
    root = nullptr;
    numberOfNodes = 0;
    return;
}

template <class T>
int BST<T>::height(Node<T>* node) const{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->right),height(node->left));
}

template <class T>
int BST<T>::height() const {
    return height(root);
}

template <class T>
void BST<T>::visit(Node<T>* node) const{
    cout << node->data << ' ';
    return;
}

template <class T>
void BST<T>::inOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    visit(node);
    inOrderTraversal(node->right);
}

template <class T>
void BST<T>::inReversedOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    inOrderTraversal(node->right);
    visit(node);
    inOrderTraversal(node->left);
}

template <class T>
void BST<T>::preOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    visit(node);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template <class T>
void BST<T>::postOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    visit(node);
}

template <class T>
void BST<T>::inOrderTraversal() const{
    return inOrderTraversal(root);
}

template <class T>
void BST<T>::inReversedOrderTraversal() const{
    return inReversedOrderTraversal(root);
}

template <class T>
void BST<T>::preOrderTraversal() const{
    return preOrderTraversal(root);
}

template <class T>
void BST<T>::postOrderTraversal() const{
    return postOrderTraversal(root);
}

template <class T>
void BST<T>::breadthFirstTraversal() const{
    if (root == nullptr)
        return;
    queue<Node<T>*>q;
    q.emplace(root);
    while(!q.empty()){
        Node<T>* node = q.front();
        q.pop();
        cout << node->data << ' ';
        if (node->left)
            q.emplace(node->left);
        if (node->right)
            q.emplace(node->right);
    }
}