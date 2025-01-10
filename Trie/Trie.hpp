#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    class Node {
    public:
        bool word;
        map<char,Node*> children;
        Node();
    };

    Node* root;
    Trie();
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
};
