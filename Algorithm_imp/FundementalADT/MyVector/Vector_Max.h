//
// Created by han on 2020/9/23.
//

#ifndef FUNDEMENTALADT_VECTOR_MAX_H
#define FUNDEMENTALADT_VECTOR_MAX_H
#include "Vector.h"
template <typename T>Rank Vector<T>::max ( Rank lo, Rank hi ) { //在[lo, hi]内找出最大者
    Rank mx = hi;
    while ( lo < hi-- ) //逆向扫描
        if ( _elem[hi] > _elem[mx] ) //且严格比较
            mx = hi; //故能在max有多个时保证后者优先，进而保证selectionSort稳定
    return mx;
}
#endif //FUNDEMENTALADT_VECTOR_MAX_H
