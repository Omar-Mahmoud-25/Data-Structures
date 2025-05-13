#ifndef AVL_CPP
#define AVL_CPP
#include "AVL.hpp"

template <class T>
AVL<T>::~AVL(){this->clear();}

template <typename T>
typename AVL<T>::Node* AVL<T>::getMin(Node* node){
    Node* start = node;
    while(start->left)
        start = start->left;
    return start;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::getMax(Node* node){
    Node* start = node;
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
    queue <Node*> qu;
    qu.emplace(root);
    while(!qu.empty()){
        Node* node = qu.front();
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
int AVL<T>::height(Node* node) const{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->right),height(node->left));
}

template <class T>
bool AVL<T>::find(T val) const{
    Node *node = root;
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
void AVL<T>::visit(Node* node) const{
    cout << node->data << ' ';
    return;
}

template <class T>
void AVL<T>::inOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    visit(node);
    inOrderTraversal(node->right);
}

template <class T>
void AVL<T>::inReversedOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;
    inReversedOrderTraversal(node->right);
    visit(node);
    inReversedOrderTraversal(node->left);
}

template <class T>
void AVL<T>::preOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;
    visit(node);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template <class T>
void AVL<T>::postOrderTraversal(Node* node) const{
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
    queue<Node*>q;
    q.emplace(root);
    while(!q.empty()){
        Node* node = q.front();
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
        root = new Node(value);
    else
        insert(root, value);
}

template <class T>
typename AVL<T>::Node* AVL<T>::insert(Node *curr, T value)
{
    if (curr == nullptr)
        return new Node(value);
    if (value < curr->data){
        curr->left = insert(curr->left, value);
        curr->left->parent = curr;
    }
    else{
        curr->right = insert(curr->right, value);
        curr->right->parent = curr;
    }
    update(curr);
    return balance(curr);
}

template <class T>
void AVL<T>::update(Node *node)
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
typename AVL<T>::Node* AVL<T>::leftRotate(Node *curr)
{
    Node *newRoot = curr->right, *parent = curr->parent;
    Node *T2 = newRoot->left;
    if (parent == nullptr)
        root = newRoot,
        newRoot->parent = nullptr;
    else if (parent->right == curr)
        parent->right = newRoot,
        newRoot->parent = parent;
    else
        parent->left = newRoot,
        newRoot->parent = parent;
    newRoot->left = curr;
    curr->parent = newRoot;
    curr->right = T2;
    if (T2)
        T2->parent = curr;
    update(curr);
    update(newRoot);
    return newRoot;
}

template <class T>
typename AVL<T>::Node* AVL<T>::rightRotate(Node *curr)
{
    Node *newRoot = curr->left;
    Node *T2 = newRoot->right, *parent = curr->parent;
    if (parent == nullptr)
        root = newRoot,
        newRoot->parent = nullptr;
    else if (parent->right == curr)
        parent->right = newRoot,
        newRoot->parent = parent;
    else
        parent->left = newRoot,
        newRoot->parent = parent;
    newRoot->right = curr;
    curr->parent = newRoot;
    curr->left = T2;
    if (T2) 
        T2->parent = curr;
    update(curr);
    update(newRoot);
    return newRoot;
}

template <class T>
typename AVL<T>::Node* AVL<T>::balance(Node *curr)
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
void AVL<T>::removeWithTwoChildren(Node *node)
{
    Node *min = node->right;
    while (min->left)
        min = min->left;
    node->data = min->data;
    return remove(min);
}

template <class T>
void AVL<T>::remove(Node *node)
{
    Node *parent = node->parent;
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
void AVL<T>::remove(Node *curr, T value)
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