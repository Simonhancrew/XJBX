//
// Created by han on 2020/9/8.
//

#ifndef FUNDEMENTALADT_VECTOR_COPYFROM_H
#define FUNDEMENTALADT_VECTOR_COPYFROM_H
#include "Vector.h"
template <typename T>
void Vector<T>::copyFrom(const T *A, Rank lo, Rank hi) {
    //构造空间，规模置0
    _elem = new T[_capacity = 2*(hi - lo)];
    _size = 0;
    //循环复制
    while(lo<hi){
        _elem[_size++] = A[lo++];
    }
}
#endif //FUNDEMENTALADT_VECTOR_COPYFROM_H
