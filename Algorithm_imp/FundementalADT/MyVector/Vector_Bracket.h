//
// Created by han on 2020/9/21.
//

#ifndef FUNDEMENTALADT_VECTOR_BRACKET_H
#define FUNDEMENTALADT_VECTOR_BRACKET_H
#include "Vector.h"
template <typename T> T& Vector<T>::operator[](Rank r) {
    return _elem[r];
}

template<typename T> const T& Vector<T>::operator[](Rank r) const {
    return _elem[r];
}//仅限作为右值
#endif //FUNDEMENTALADT_VECTOR_BRACKET_H
