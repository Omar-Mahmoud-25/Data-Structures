#include "Fenwick.hpp"
#define ll long long
using namespace std;

FenwickTree::FenwickTree(vector<int>& v){
    tree.resize(v.size() + 1, 0);
    for (int i = 0; i < v.size(); i++)
        update(i+1, v[i]);
}

ll FenwickTree::query(int postion){
    ll sum = 0;
    while (postion){
        sum += tree[postion];
        postion -= (postion & -postion);
    }
}

ll FenwickTree::query(int x,int y){
    if (x > y)
        swap(x,y);
    return query(y) - query(x-1);
}

void FenwickTree::update(int postion, int value){
    value = value - query(postion,postion);
    while(postion < tree.size()){
        this->tree[postion] += value;
        postion += (postion & -postion);
    }
}

