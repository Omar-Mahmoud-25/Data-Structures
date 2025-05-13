#include <bits/stdc++.h>

using namespace std;

// not completed yet

class IntervalTree {
private:
    struct Node {
        int low, high, max, height;
        Node* left;
        Node* right;
        Node(int l, int h) : low(l), high(h), max(h), height(1), left(nullptr), right(nullptr) {}
    };
    Node* root;
    Node* insert(Node* node, int low, int high);
    bool search(Node* node, int low, int high);
    Node* remove(Node* node, int low, int high);
    Node* minValueNode(Node* node);
    bool doOverlap(int low1, int high1, int low2, int high2);
    int height(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);

public:
    IntervalTree();
    void insert(int low, int high);
    bool search(int low, int high);
    void remove(int low, int high);
};
