//
// Created by han on 2020/9/8.
//

#ifndef FUNDEMENTALADT_VECTOR_EXPAND_H
#define FUNDEMENTALADT_VECTOR_EXPAND_H
#include "Vector.h"
template<typename T>
void Vector<T>::expand(){
    //if _capacity is ok
    if(_size<_capacity) return;
    //if the capacity is lower than the minimal capacity
    if(_size<DEFAULT_CAPACITY) _size = DEFAULT_CAPACITY;
    //recorde the old address
    T* oldElem = _elem;
    //create new space
    _elem = new T[_capacity<<=1];
    for(int i =0;i<_size;i++) {
        _elem[i] = oldElem[i];//
    }
    delete[] oldElem;
}
#endif //FUNDEMENTALADT_VECTOR_EXPAND_H
