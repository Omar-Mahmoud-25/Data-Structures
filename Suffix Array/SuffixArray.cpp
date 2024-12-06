#include "SuffixArray.hpp"
#include "mergeSort.cpp"
#include <iostream>
using namespace std;

SuffixArray::SuffixArray(const char *string){
    this->string = string;
    this->stringLength = 0;
    while(string[stringLength] != '\0')
        this->stringLength++;
    this->suffixArray = new int[stringLength];
}

SuffixArray::~SuffixArray(){
    delete[] suffixArray;
}

void SuffixArray::constructUsingPrefixDoubling(){
    int *rank = new int[stringLength];
    Suffix *suffixes = new Suffix[stringLength];
    
    for (int i = 0; i<stringLength; ++i){
        rank[i] = string[i];
        suffixes[i] = Suffix(i,rank[i],(i + 1 < stringLength) ? string[i + 1] : -1);
    }

    MergeSort(suffixes,stringLength);

    for (int k = 1; k < (stringLength<<2); k <<= 1) {
        int currentRank = 0;
        int previousCurrentRank = suffixes[0].currentRank;
        int previousNextRank = suffixes[0].nextRank;
        suffixes[0].currentRank = currentRank;
        rank[suffixes[0].index] = currentRank;

        for (int i = 1; i < stringLength; ++i) {
            if (suffixes[i].currentRank == previousCurrentRank && suffixes[i].nextRank == previousNextRank)
                suffixes[i].currentRank = currentRank;
            else {
                previousCurrentRank = suffixes[i].currentRank;
                previousNextRank = suffixes[i].nextRank;
                suffixes[i].currentRank = ++currentRank;
            }
            rank[suffixes[i].index] = suffixes[i].currentRank;
        }

        for (int i = 0; i < stringLength; ++i) {
            int nextRankIndex = suffixes[i].index + k;
            suffixes[i].nextRank = (nextRankIndex < stringLength) ? rank[nextRankIndex] : -1;
        }
        MergeSort(suffixes, stringLength);

        if (currentRank == stringLength)
            break;
    }

    for (int i = 0; i < stringLength; ++i)
        suffixArray[i] = suffixes[i].index;
    delete[] rank;
    delete[] suffixes;
    return;
}

void SuffixArray::print(){
    for (int i = 0; i<stringLength; ++i)
        cout << suffixArray[i] << ' ';
    return;
}