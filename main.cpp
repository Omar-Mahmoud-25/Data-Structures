#include <bits/stdc++.h>
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "Dynamic Array/DynamicArray.cpp"
#include "Red-Black Tree/RBTree.cpp"
#include "AVL Tree/AVL.cpp"
using namespace std;

int main(){
    RBTree <int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(6);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.remove(6);
    tree.breadthFirstTraversal();
    return 0;
}