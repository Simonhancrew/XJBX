//
// Created by han on 2020/9/22.
//

#ifndef FUNDEMENTALADT_VECTOR_FIND_H
#define FUNDEMENTALADT_VECTOR_FIND_H
#include "Vector.h"

template <typename T> Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const {
    while ((lo<hi--) && e != _elem[hi]);//从后往前，多个返回最大的Rank,找不到会在hi == lo -1停下
    return hi;//失败返回 lo -1
}
#endif //FUNDEMENTALADT_VECTOR_FIND_H
