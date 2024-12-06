#include <bits/stdc++.h>
#define ll long long
using namespace std;

class FenwickTree{
private:
    vector<ll> tree;
    ll query(int postion);
public:
    FenwickTree(int size);
    FenwickTree(vector<int>& v);
    void update(int postion, int value);
    ll query(int x, int y);
};