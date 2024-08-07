#ifndef SPARSETABLE_CPP
#define SPARSETABLE_CPP
#include "SparseTable.hpp"
using namespace std;

template <class T>
SparseTable<T>::SparseTable(const vector<T>& data,const function <T(T,T)>& operation){
    this->operation = operation;
    this->length = (int)data.size();
    table.resize(this->length,vector<T>(32-__builtin_clz(this->length)+1));
    for (int i = 0; i<n; ++i)
            table[i][0] = v[i];
    for (int p = 1; (1 << p)<=n; ++p)
        for (int i = 0; i+(1<<p) <= n; ++i)
            table[i][p] = this->operation(table[i][p-1],table[i+(1<<(p-1))][p-1]);
}

template <class T>
T SparseTable<T>::query(int l,int r){
    if (r < l)
        swap(l,r);
    int lg = 31-__builtin_clz(r-l+1);
    return this->operation(table[l][lg],table[r-(1<<lg)+1][lg]);
}

template <class T>
int SparseTable<T>::size(){
    return this->length;
}
#endif