#include <iostream>
using namespace std;
template <typename T, size_t N>
class BTree{
private:
    class Node{
    public:
        T* data = new T[N];
        Node** children = new Node*[N+1];
        Node* parent;
        int size = 0;
        Node(){
            size = 0;
            parent = nullptr;
            for (int i = 0; i<N + 1; ++i)
                children[i] = nullptr;
        }
        Node(T data){
            size = 1;
            this->data[0] = data;
            parent = nullptr;
            for (int i = 0; i<N + 1; ++i)
                children[i] = nullptr;
        }
    };
    void insert(Node* node, T data);
    Node* root = nullptr;
    int numOfNodes = 0,numOfData = 0;
    void split(Node* node);
    void depthFirst(Node* node, int numOfTabs);
    void clear(Node* node);
    void deleteNode(Node* node);
public:
    BTree();
    ~BTree();
    int numberOfNodes();
    void insert(T data);
    // void remove(T data);
    void clear();
    void print();
};