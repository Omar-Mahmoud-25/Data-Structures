#ifndef DYNAMICARRAY_CPP
#define DYNAMICARRAY_CPP
#include "DynamicArray.hpp"
using namespace std;

template <class T>
DynamicArray<T>::DynamicArray(){
    data = new T[1];
    length = 0;
    maxSize = 1;
}

template <class T>
DynamicArray<T>::DynamicArray(int size){
    data = new T[size];
    length = size;
    maxSize = size;
}

template <class T>
DynamicArray<T>::~DynamicArray(){
    delete[] data;
}

template <class T>
T& DynamicArray<T>::operator[](int index){
    return data[index];
}

template <class T>
T& DynamicArray<T>::at(int index){
    if (index < 0 || index >= length)
        throw out_of_range("Index out of range");
    return data[index];
}

template <class T>
T& DynamicArray<T>::back(){
    return data[length-1];
}

template <class T>
int DynamicArray<T>::size(){
    return length;
}

template <class T>
int DynamicArray<T>::capacity(){
    return maxSize;
}

template <class T>
void DynamicArray<T>::push_back(T value){
    if (length == maxSize)
        resize();
    data[length++] = value;
}

template <class T>
void DynamicArray<T>::pop_back(){
    if (length == 0)
        throw out_of_range("Array is empty");
    length--;
}

template <class T>
void DynamicArray<T>::resize(){
    maxSize *= 2;
    T* newData = new T[maxSize];
    for (int i = 0; i < length; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

template <class T>
void DynamicArray<T>::erase(int index){
    if (index < 0 || index >= length)
        throw out_of_range("Index out of range");
    for (int i = index; i < length-1; ++i)
        data[i] = data[i+1];
    length--;
}

template <class T>
void DynamicArray<T>::clear(){
    delete[] data;
    length = 0;
    maxSize = 0;
}

template <class T>
bool DynamicArray<T>::empty(){
    return length == 0;
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other){
    data = new T[other.length];
    for (int i = 0; i < other.length; ++i)
        data[i] = other.data[i];
    length = other.length;
    maxSize = other.maxSize;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){
    delete[] data;
    data = new T[other.length];
    for (int i = 0; i < other.length; ++i)
        data[i] = other.data[i];
    length = other.length;
    maxSize = other.maxSize;
    return *this;
}

template <class T>
void DynamicArray<T>::reverse(){
    for (int i = 0; i < length/2; ++i)
        swap(data[i],data[length-i-1]);
}

#endif