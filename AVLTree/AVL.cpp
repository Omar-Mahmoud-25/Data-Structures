#ifndef AVL_CPP
#define AVL_CPP
#include "AVL.hpp"

template <class T>
AVL<T>::~AVL(){this->clear();}

template <typename T>
typename AVL<T>::template Node<T>* AVL<T>::getMin(Node<T>* node){
    Node<T>* start = node;
    while(start->left)
        start = start->left;
    return start;
}

template <typename T>
typename AVL<T>::template Node<T>* AVL<T>::getMax(Node<T>* node){
    Node<T>* start = node;
    while(start->right)
        start = start->right;
    return start;
}

template <class T>
int AVL<T>::size() const{
    return numberOfNodes;
}

template <class T>
void AVL<T>::clear(){
    if (root == nullptr)
        return;
    queue <Node<T>*> qu;
    qu.emplace(root);
    while(!qu.empty()){
        Node<T>* node = qu.front();
        qu.pop();
        if (node->right) 
            qu.emplace(node->right);
        if (node->left)
            qu.emplace(node->left);
        delete node;
    }
    root = nullptr;
    numberOfNodes = 0;
    return;
}

template <class T>
int AVL<T>::height(Node<T>* node) const{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->right),height(node->left));
}

template <class T>
bool AVL<T>::find(T val) const{
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
int AVL<T>::height() const {
    return height(root);
}

template <class T>
void AVL<T>::visit(Node <T>* node) const{
    cout << node->data << ' ';
    return;
}

template <class T>
void AVL<T>::inOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    visit(node);
    inOrderTraversal(node->right);
}

template <class T>
void AVL<T>::inReversedOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    inReversedOrderTraversal(node->right);
    visit(node);
    inReversedOrderTraversal(node->left);
}

template <class T>
void AVL<T>::preOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    visit(node);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template <class T>
void AVL<T>::postOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    visit(node);
}

template <class T>
void AVL<T>::inOrderTraversal() const{
    return inOrderTraversal(root);
}

template <class T>
void AVL<T>::inReversedOrderTraversal() const{
    return inReversedOrderTraversal(root);
}

template <class T>
void AVL<T>::preOrderTraversal() const{
    return preOrderTraversal(root);
}

template <class T>
void AVL<T>::postOrderTraversal() const{
    return postOrderTraversal(root);
}

template <class T>
void AVL<T>::breadthFirstTraversal() const{
    if (root == nullptr)
        return;
    queue<Node<T>*>q;
    q.emplace(root);
    while(!q.empty()){
        Node<T>* node = q.front();
        q.pop();
        visit(node);
        if (node->left)
            q.emplace(node->left);
        if (node->right)
            q.emplace(node->right);
    }
}

template <class T>
void AVL<T>::insert(T value)
{
    ++numberOfNodes;
    if (root == nullptr)
        root = new Node<T>(value);
    else
        insert(root, value);
}

template <class T>
typename AVL<T>::template Node<T>* AVL<T>::insert(Node<T> *curr, T value)
{
    if (curr == nullptr)
        return new Node<T>(value);
    if (value < curr->data)
        curr->left = insert(curr->left, value);
    else
        curr->right = insert(curr->right, value);
    update(curr);
    return balance(curr);
}

template <class T>
typename AVL<T>::template Node<T>* AVL<T>::getParent(Node<T> *curr)
{
    if (curr == root || root == nullptr)
        return nullptr;
    Node<T> *node = root;
    while (node)
        if (node->left == curr || node->right == curr)
            return node;
        else if (curr->data < node->data)
            node = node->left;
        else
            node = node->right;
    return nullptr;
}

template <class T>
void AVL<T>::update(Node<T> *node)
{
    int leftHeight = -1, rightHeight = -1;
    if (node->left)
        leftHeight = node->left->height;
    if (node->right)
        rightHeight = node->right->height;
    node->height = max(rightHeight, leftHeight) + 1;
    node->BF = rightHeight - leftHeight;
}

template <class T>
typename AVL<T>::template Node<T>* AVL<T>::leftRotate(Node<T> *curr)
{
    Node<T> *newRoot = curr->right, *parent = getParent(curr);
    Node<T> *T2 = newRoot->left;
    if (parent == nullptr)
        root = newRoot;
    else if (parent->right == curr)
        parent->right = newRoot;
    else
        parent->left = newRoot;
    newRoot->left = curr;
    curr->right = T2;
    update(curr);
    update(newRoot);
    return newRoot;
}

template <class T>
typename AVL<T>::template Node<T>* AVL<T>::rightRotate(Node<T> *curr)
{
    Node<T> *newRoot = curr->left;
    Node<T> *T2 = newRoot->right, *parent = getParent(curr);
    if (parent == nullptr)
        root = newRoot;
    else if (parent->right == curr)
        parent->right = newRoot;
    else
        parent->left = newRoot;
    newRoot->right = curr;
    curr->left = T2;
    update(curr);
    update(newRoot);
    return newRoot;
}

template <class T>
typename AVL<T>::template Node<T> *AVL<T>::balance(Node<T> *curr)
{
    if (curr->BF < -1)
    {
        if (curr->left->BF > 0)
            curr->left = leftRotate(curr->left);
        curr = rightRotate(curr);
    }
    else if (curr->BF > 1)
    {
        if (curr->right->BF < 0)
            curr->right = rightRotate(curr->right);
        curr = leftRotate(curr);
    }
    return curr;
}

template <class T>
void AVL<T>::remove(T value)
{
    if (root == nullptr)
        return;
    return remove(root, value);
}

template <class T>
void AVL<T>::removeWithTwoChildren(Node<T> *node)
{
    Node<T> *min = node->right;
    while (min->left)
        min = min->left;
    node->data = min->data;
    return remove(min);
}

template <class T>
void AVL<T>::remove(Node<T> *node)
{
    Node<T> *parent = getParent(node);
    --numberOfNodes;
    if (parent && parent->right == node)
    {
        if (node->right)
            parent->right = node->right;
        else if (node->left)
            parent->right = node->left;
        else
            parent->right = nullptr;
    }
    else if (parent)
    {
        if (node->left)
            parent->left = node->left;
        else if (node->right)
            parent->left = node->right;
        else
            parent->left = nullptr;
    }
    delete node;
    return;
}

template <class T>
void AVL<T>::remove(Node<T> *curr, T value)
{
    if (curr == nullptr)
        return;
    if (curr->data == value)
    {
        if (curr->left && curr->right)
            removeWithTwoChildren(curr);
        else
            remove(curr);
    }
    if (value < curr->data)
        remove(curr->left, value);
    else
        remove(curr->right, value);
    update(curr);
    curr = balance(curr);
}

#endif