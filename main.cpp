#include <bits/stdc++.h>
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "Dynamic Array/DynamicArray.cpp"
#include "Red-Black Tree/RedBlackTree.cpp"
#include "AVL Tree/AVL.cpp"
#include "B-Tree/BTree.cpp"
#include "Suffix Array/SuffixArray.cpp"
using namespace std;

int main(){
    BTree<int,3> t1;
     t1.insert(1);
     t1.insert(5);
     t1.insert(0);
     t1.insert(4);
     t1.insert(3);
     t1.insert(2);
     t1.print();

     BTree <char,5> t;
     t.insert('G');
     t.insert('I');
     t.insert('B');
     t.insert('J');
     t.insert('C');
     t.insert('A');
     t.insert('K');
     t.insert('E');
     t.insert('D');
     t.insert('S');
     t.insert('T');
     t.insert('R');
     t.insert('L');
     t.insert('F');
     t.insert('H');
     t.insert('M');
     t.insert('N');
     t.insert('P');
     t.insert('Q');
     t.print();
    return 0;
}