//
// Created by han on 2020/9/21.
//

#ifndef FUNDEMENTALADT_VECTOR_SHRINK_H
#define FUNDEMENTALADT_VECTOR_SHRINK_H
#include "Vector.h"

template<typename  T> void Vector<T>::shrink() {
    //装填因子过小就收缩
    if(_capacity<DEFAULT_CAPACITY<<1) return;//不至于收缩到DEFAULT_CAPACITY以下
    if(_size<<2>_capacity) return;//以25%为界限
    T* oldElem = _elem;
    _elem = new T[_capacity>>=1];//减半
    for(int i = 0;i<_size;i++){
        _elem[i] = oldElem[i];
    }
    delete[] oldElem;
}

#endif //FUNDEMENTALADT_VECTOR_SHRINK_H
