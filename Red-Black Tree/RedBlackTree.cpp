#ifndef REDBLACKTREE_CPP
#define REDBLACKTREE_CPP
#include "RedBlackTree.hpp"

template <class T>
RedBlackTree<T>::~RedBlackTree(){this->clear();}

template <class T>
int RedBlackTree<T>::size() const{
    return numberOfNodes;
}

template <class T>
void RedBlackTree<T>::clear(){
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
int RedBlackTree<T>::height(Node* node) const{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->right),height(node->left));
}

template <class T>
int RedBlackTree<T>::height() const{
    return height(root);
}

template <class T>
bool RedBlackTree<T>::find(T val) const{
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
void RedBlackTree<T>::visit(Node* node) const{
    cout << node->data << ' ' << 
    (node->black? "black":"red") << '\n';
    return;
}

template <class T>
void RedBlackTree<T>::inOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    visit(node);
    inOrderTraversal(node->right);
}

template <class T>
void RedBlackTree<T>::inReversedOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;
    inReversedOrderTraversal(node->right);
    visit(node);
    inReversedOrderTraversal(node->left);
}

template <class T>
void RedBlackTree<T>::preOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;
    visit(node);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template <class T>
void RedBlackTree<T>::postOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    visit(node);
}

template <class T>
void RedBlackTree<T>::inOrderTraversal() const{
    return inOrderTraversal(root);
}

template <class T>
void RedBlackTree<T>::inReversedOrderTraversal() const{
    return inReversedOrderTraversal(root);
}

template <class T>
void RedBlackTree<T>::preOrderTraversal() const{
    return preOrderTraversal(root);
}

template <class T>
void RedBlackTree<T>::postOrderTraversal() const{
    return postOrderTraversal(root);
}

template <class T>
void RedBlackTree<T>::breadthFirstTraversal() const{
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
void RedBlackTree<T>::insert(T val){
    ++numberOfNodes;
    Node *newNode = new Node(val);
    if (root == nullptr){
        root = newNode;
        root->black = true;
        return;
    }
    Node *node = root,*prev = nullptr;
    while(node){
        prev = node;
        if (node->data == val)
            return;
        if (val < node->data)
            node = node->left;
        else 
            node = node->right;
    }
    if (val < prev->data)
        prev -> left = newNode,
        newNode->parent = prev;    
    else 
        prev -> right = newNode,
        newNode->parent = prev;
    handleTwoAdjacentRedNodes(newNode);
    return;
}

template <class T>
void RedBlackTree<T>::handleTwoAdjacentRedNodes(Node *node){
    if (!node)
        return;
    if (node == root){
        node->black = true;
        return;
    }
    Node* parent = node->parent;
    if (node->black || parent->black)
        return;
    Node* grandParent = parent->parent;
    Node* uncle = (parent == grandParent->left? grandParent->right:grandParent->left);
    if (uncle && !uncle->black){
        parent->black = true;
        uncle->black = true;
        if (grandParent != root)
            grandParent->black = false;
    }
    else{
        if (parent == grandParent->left){
            if (node == parent->right)
                leftRotate(parent);
            rightRotate(grandParent);
        }
        else{
            if (node == parent->left)
                rightRotate(parent);
            leftRotate(grandParent);
        }
        parent->black = true;
        grandParent->black = false;
    }
    handleTwoAdjacentRedNodes(grandParent);
    return;
}

template <class T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::leftRotate(Node *curr)
{
    Node *newRoot = curr->right, *parent = curr->parent;
    Node *T2 = newRoot->left;
    if (parent == nullptr)
        root = newRoot;
    else if (parent->right == curr)
        parent->right = newRoot;
    else
        parent->left = newRoot;
    newRoot->parent = parent;
    newRoot->left = curr;
    curr->parent = newRoot;
    curr->right = T2;
    if (T2)
        T2->parent = curr;
    return newRoot;
}

template <class T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::rightRotate(Node *curr)
{
    Node *newRoot = curr->left;
    Node *T2 = newRoot->right, *parent = curr->parent;
    if (parent == nullptr)
        root = newRoot;
    else if (parent->right == curr)
        parent->right = newRoot;
    else
        parent->left = newRoot;
    newRoot->parent = parent;
    newRoot->right = curr;
    curr->parent = newRoot;
    curr->left = T2;
    if (T2)
        T2->parent = curr;
    return newRoot;
}

template <class T>
void RedBlackTree<T>::remove(T value){
    if (root == nullptr)
        return;
    return remove(root, value);
}

template <class T>
void RedBlackTree<T>::remove(Node *curr, T value)
{
    if (curr == nullptr)
        return;
    if (curr->data == value)
        removeNode(curr);
    else if (value < curr->data)
        remove(curr->left, value);
    else
        remove(curr->right, value);
    return;
}

template <class T>
void RedBlackTree<T>::removeNode(Node *node){
    --numberOfNodes;
    while(node->left || node->right){
        if (node->left){
            Node *max = node->left;
            while (max->right)
                max = max->right;
            node->data = max->data;
            node = max;
        }
        else{
            Node *min = node->right;
            while (min->left)
                min = min->left;
            node->data = min->data;
            node = min;
        }
    }
    if (node->black)
        handleDoubleBlack(node);
    if (node->parent)
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
    else
        root = nullptr;
    delete node;
    return;
}

template <class T>
void RedBlackTree<T>::handleDoubleBlack(Node *node){
    if (node && (!node->black || node == root)){
        node->black = true;
        return;
    }
    Node* parent = node->parent;
    Node* brother = (node == parent->left? parent->right:parent->left);
    if (brother == nullptr)
        return handleDoubleBlack(parent);
    if (!brother->black){
        if (brother == parent->left)
            rightRotate(parent);
        else
            leftRotate(parent);
        brother->black = !brother->black;
        parent->black = !parent->black;
        return handleDoubleBlack(node);
    }
    if ((brother->left == nullptr || brother->left->black) && (brother->right == nullptr || brother->right->black)){
        brother->black = !brother->black;
        return handleDoubleBlack(parent);
    }
    Node* nearChild = (node == parent->left? brother->left:brother->right);
    Node* farChild = (node == parent->left? brother->right:brother->left);
    if (nearChild && !nearChild->black){
        if (nearChild == brother->left)
            rightRotate(brother);
        else
            leftRotate(brother);
        brother->black = !brother->black;
        nearChild->black = !nearChild->black;
        farChild = brother;
        brother = nearChild;
    }
    if (brother == parent->right)
        leftRotate(parent);
    else
        rightRotate(parent);
    brother->black = parent->black;
    parent->black = true;
    farChild->black = true;
}

#endif