#ifndef RBTREE_CPP
#define RBTREE_CPP
#include "RBTree.hpp"

template <class T>
RBTree<T>::~RBTree(){this->clear();}

template <class T>
int RBTree<T>::size() const{
    return numberOfNodes;
}

template <class T>
void RBTree<T>::clear(){
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
int RBTree<T>::height(Node<T>* node) const{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->right),height(node->left));
}

template <class T>
int RBTree<T>::height() const{
    return height(root);
}

template <class T>
bool RBTree<T>::find(T val) const{
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
void RBTree<T>::visit(Node <T>* node) const{
    cout << node->data << ' ' << 
    (node->black? "black":"red") << '\n';
    return;
}

template <class T>
void RBTree<T>::inOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    visit(node);
    inOrderTraversal(node->right);
}

template <class T>
void RBTree<T>::inReversedOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    inReversedOrderTraversal(node->right);
    visit(node);
    inReversedOrderTraversal(node->left);
}

template <class T>
void RBTree<T>::preOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    visit(node);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template <class T>
void RBTree<T>::postOrderTraversal(Node <T>* node) const{
    if (node == nullptr)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    visit(node);
}

template <class T>
void RBTree<T>::inOrderTraversal() const{
    return inOrderTraversal(root);
}

template <class T>
void RBTree<T>::inReversedOrderTraversal() const{
    return inReversedOrderTraversal(root);
}

template <class T>
void RBTree<T>::preOrderTraversal() const{
    return preOrderTraversal(root);
}

template <class T>
void RBTree<T>::postOrderTraversal() const{
    return postOrderTraversal(root);
}

template <class T>
void RBTree<T>::breadthFirstTraversal() const{
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
void RBTree<T>::insert(T val){
    ++numberOfNodes;
    Node<T> *newNode = new Node<T>(val);
    if (root == nullptr){
        root = newNode;
        root->black = true;
        return;
    }
    Node<T> *node = root,*prev = nullptr;
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
void RBTree<T>::handleTwoAdjacentRedNodes(Node<T> *node){
    if (!node)
        return;
    if (node == root){
        node->black = true;
        return;
    }
    Node<T>* parent = node->parent;
    if (node->black || parent->black)
        return;
    Node<T>* grandParent = parent->parent;
    Node<T>* uncle = (parent == grandParent->left? grandParent->right:grandParent->left);
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
typename RBTree<T>::template Node<T>* RBTree<T>::leftRotate(Node<T> *curr)
{
    Node<T> *newRoot = curr->right, *parent = curr->parent;
    Node<T> *T2 = newRoot->left;
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
typename RBTree<T>::template Node<T>* RBTree<T>::rightRotate(Node<T> *curr)
{
    Node<T> *newRoot = curr->left;
    Node<T> *T2 = newRoot->right, *parent = curr->parent;
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
void RBTree<T>::remove(T value){
    if (root == nullptr)
        return;
    return remove(root, value);
}

template <class T>
void RBTree<T>::remove(Node<T> *curr, T value)
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
void RBTree<T>::removeNode(Node<T> *node){
    --numberOfNodes;
    while(node->left || node->right){
        if (node->left){
            Node<T> *max = node->left;
            while (max->right)
                max = max->right;
            node->data = max->data;
            node = max;
        }
        else{
            Node<T> *min = node->right;
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
void RBTree<T>::handleDoubleBlack(Node<T> *node){
    if (node && (!node->black || node == root)){
        node->black = true;
        return;
    }
    Node<T>* parent = node->parent;
    Node<T>* brother = (node == parent->left? parent->right:parent->left);
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
    Node<T>* nearChild = (node == parent->left? brother->left:brother->right);
    Node<T>* farChild = (node == parent->left? brother->right:brother->left);
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