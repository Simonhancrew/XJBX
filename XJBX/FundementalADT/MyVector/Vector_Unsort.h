//
// Created by han on 2020/9/21.
//

#ifndef FUNDEMENTALADT_VECTOR_UNSORT_H
#define FUNDEMENTALADT_VECTOR_UNSORT_H
#include "Vector.h"
#include <random>
template<typename T> void Vector<T>::unsort(Rank lo, Rank hi) {
    //治乱区间
    T* V = _elem+lo;
    for(int i = hi-lo;i>0;i--){
        swap(V[i-1],V[rand()%i]);
    }
}
#endif //FUNDEMENTALADT_VECTOR_UNSORT_H
