#include "SegmentTree.hpp"
using namespace std;

template <class T>
SegmentTree<T>::SegmentTree(vector<T>& v, function <T(T,T)> combine,T nullValue){
    this->nullValue = nullValue;
    size = 1;
    this->combine = combine;
    while(size < v.size())
        size <<= 1;
    tree.resize(size << 1,nullValue);
    for (int i = 0; i<v.size(); ++i)
        update(i+1,v[i]);
}

template <class T>
T SegmentTree<T>::query(int left,int right,int start,int end,int index){
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[index];
    int mid = (start + end) >> 1;
    return combine(query(left,right,start,mid,index << 1),query(left,right,mid+1,end,index << 1 | 1));
}

template <class T>
T SegmentTree<T>::query(int start,int end){
    return query(start,end,1,size,1);
}

template <class T>
void SegmentTree<T>::update(int postion, T value,int start,int end,int index){
    if (start == end){
        tree[index] = value;
        return;
    }
    int mid = (start + end) >> 1;
    if (postion <= mid)
        update(postion,value,start,mid,index << 1);
    else
        update(postion,value,mid+1,end,index << 1 | 1);
    tree[index] = combine(tree[index << 1],tree[index << 1 | 1]);
}

template <class T>
void SegmentTree<T>::update(int postion, T value){
    update(postion,value,1,size,1);
}