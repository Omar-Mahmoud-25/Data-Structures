#include "Trie.hpp"


Trie::Node::Node() : word(false) {}

Trie::Trie() {
    root = new Node();
}

void Trie::insert(string word) {
    Node* node = root;
    for (char c : word) {
        if (node->children[c] == nullptr)
            node->children[c] = new Node();
        node = node->children[c];
    }
    node->word = true;
}

bool Trie::search(string word) {
    Node* node = root;
    for (char c : word) {
        if (node->children[c] == nullptr)
            return false;
        node = node->children[c];
    }
    return node->word;
}

bool Trie::startsWith(string prefix) {
    Node* node = root;
    for (char c : prefix) {
        if (node->children[c] == nullptr)
            return false;
        node = node->children[c];
    }
    return true;
}
