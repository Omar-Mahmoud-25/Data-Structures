#ifndef SPARSETABLE_HPP
#define SPARSETABLE_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class SparseTable{
private:
    vector<vector<T>> table;
    function <T(T,T)> combine;
    int length;
public:
    SparseTable(const vector<T>& data,const function <T(T,T)>& operation);
    T query(int l,int r);
    int size();
};

#endif