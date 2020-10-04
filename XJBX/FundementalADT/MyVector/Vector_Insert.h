//
// Created by han on 2020/9/22.
//

#ifndef FUNDEMENTALADT_VECTOR_INSERT_H
#define FUNDEMENTALADT_VECTOR_INSERT_H
#include "Vector.h"
template <typename T> Rank Vector<T>::insert(Rank r, const T &e) {
    expand();//看看有没有必要扩容
    for(int i = _size;i>r;i--){
        _elem[i] = _elem[i-1];//从后往前移位填空，直到r
    }
    _elem[r] = e;
    _size++;//更新容量
    return r;
}

#endif //FUNDEMENTALADT_VECTOR_INSERT_H
