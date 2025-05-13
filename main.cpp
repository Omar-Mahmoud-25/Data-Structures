#include <bits/stdc++.h>
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "Dynamic Array/DynamicArray.cpp"
#include "Red-Black Tree/RedBlackTree.cpp"
#include "AVL Tree/AVL.cpp"
#include "B-Tree/BTree.cpp"
#include "Suffix Array/SuffixArray.cpp"
#include "Single Linked List/SingleLinkedList.cpp"
#include "Doube Linked List/DoubleLinkedList.cpp"
#include "Binary Search Tree/BST.cpp"

using namespace std;

int main() {
    // Test Single Linked List
    SingleLinkedList<int> singleList;
    singleList.push_back(10);
    singleList.push_back(20);
    singleList.push_front(5);
    singleList.insert_at(15, 2);
    cout << "Single Linked List: ";
    for (auto it = singleList.begin(); it != singleList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Test Double Linked List
    DoubleLinkedList<int> doubleList;
    doubleList.push_back(10);
    doubleList.push_back(20);
    doubleList.push_front(5);
    doubleList.insert_at(15, 2);
    cout << "Double Linked List: ";
    for (auto it = doubleList.begin(); it != doubleList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Test Binary Search Tree
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(7);
    cout << "BST In-Order Traversal: ";
    bst.inOrderTraversal();
    cout << endl;

    // Test AVL Tree
    AVL<int> avl;
    avl.insert(10);
    avl.insert(5);
    avl.insert(15);
    avl.insert(7);
    cout << "AVL In-Order Traversal: ";
    avl.inOrderTraversal();
    cout << endl;

    // Test Red-Black Tree
    RedBlackTree<int> rbt;
    rbt.insert(10);
    rbt.insert(5);
    rbt.insert(15);
    rbt.insert(7);
    cout << "Red-Black Tree In-Order Traversal: ";
    rbt.inOrderTraversal();
    cout << endl;

    return 0;
}