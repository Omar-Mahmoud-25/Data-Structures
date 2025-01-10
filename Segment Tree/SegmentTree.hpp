#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
class SegmentTree{
private:
    int size;
    vector <T> tree;
    function <T(T,T)> combine;
    T nullValue;
    void update(int postion, T value,int start,int end,int index);
    T query(int left,int right,int start,int end,int index);
public:
    SegmentTree(vector<T>& v, function <T(T,T)> combine,T nullValue);
    T query(int start,int end);
    void update(int postion, T value);
};