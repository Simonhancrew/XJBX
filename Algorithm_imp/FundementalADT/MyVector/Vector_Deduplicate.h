//
// Created by han on 2020/9/22.
//

#ifndef FUNDEMENTALADT_VECTOR_DEDUPLICATE_H
#define FUNDEMENTALADT_VECTOR_DEDUPLICATE_H
#include "Vector.h"
template <typename T> int Vector<T>::deduplicate() {
    int oldsize = _size;
    Rank i = 1;
    while(i<_size){
        (find(_elem[i],0,i)<0)?i++:remove(i);//有一样的就去除，没有就继续i++查找后继
    }
    return oldsize-_size;
}
#endif //FUNDEMENTALADT_VECTOR_DEDUPLICATE_H
