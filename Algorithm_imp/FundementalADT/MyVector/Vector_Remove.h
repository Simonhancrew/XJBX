//
// Created by han on 2020/9/22.
//

#ifndef FUNDEMENTALADT_VECTOR_REMOVE_H
#define FUNDEMENTALADT_VECTOR_REMOVE_H
#include "Vector.h"
template <typename T> int Vector<T>::remove(Rank lo, Rank hi) {
    if(lo == hi) return 0;
    while(hi<_size) _elem[lo++] = _elem[hi++];//hi之后的单元需要前移hi-lo个单元
    _size = lo;//此时的lo到了末尾
    shrink();//看一下有没有必要缩小
    return hi-lo;//返回删除的元素数目
}

//删除单一元素
template <typename T> T Vector<T>::remove(Rank r) {
    T e = _elem[r];
    remove(r,r+1);
    return e;
}
#endif //FUNDEMENTALADT_VECTOR_REMOVE_H
