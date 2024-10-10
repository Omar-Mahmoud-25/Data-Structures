#include <bits/stdc++.h>
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "Dynamic Array/DynamicArray.cpp"
#include "Red-Black Tree/RBTree.cpp"
#include "AVL Tree/AVL.cpp"
using namespace std;

int main(){
    // RBTree <int> tree;
    // tree.insert(7);
    // tree.insert(5);
    // tree.insert(9);
    // tree.insert(8);
    // tree.insert(11);
    // tree.insert(6);
    // tree.insert(4);
    // tree.insert(10);
    // tree.insert(12);
    // tree.breadthFirstTraversal();
    // cout << nl;
    // tree.remove(8);
    // tree.breadthFirstTraversal();

    RBTree<int> rbtree;

    // Insert nodes
    for (int i = 1; i <= 10; ++i) 
        rbtree.insert(i * 10);
    rbtree.breadthFirstTraversal();
    cout << "\n\n";

    // Delete nodes
    for (int i = 10; i; --i)
        cout << "deleting " << i << '\n',
        rbtree.remove(i * 10),
        rbtree.breadthFirstTraversal(),
        cout << "\n\n";

    // Multiple deletions
    // rbtree.remove(10);
    // rbtree.remove(20);
    // rbtree.remove(30);
    // rbtree.remove(40);

    // In-order traversal after multiple deletions
    // cout << "In-Order Traversal after multiple deletions (10, 20, 30, 40):\n";
    // rbtree.breadthFirstTraversal();
    // cout << endl;

    // Expected output:
    // 50 60 70 80 90 100
    return 0;
}