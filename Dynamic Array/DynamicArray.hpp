#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <bits/stdc++.h>
using namespace std;

template <class T>
class DynamicArray{
private:
    T* data;
    int length;
    int maxSize;
    void resize();
public:
    DynamicArray();
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray& operator=(const DynamicArray<T>& other);
    ~DynamicArray();
    T& operator[](int index);
    T& at(int index);
    T& back();
    int size();
    int capacity();
    void push_back(T value);
    void pop_back();
    void erase(int index);
    void clear();
    bool empty();
    void reverse();
};

#endif