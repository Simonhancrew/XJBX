//
// Created by han on 2020/9/23.
//

#ifndef FUNDEMENTALADT_VECTOR_ASSIGNMENT_H
#define FUNDEMENTALADT_VECTOR_ASSIGNMENT_H
#include "Vector.h"
template <typename T> Vector<T>& Vector<T>::operator= ( Vector<T> const& V ) { //深复制
    if ( _elem ) delete [] _elem; //释放原有内容
    copyFrom ( V._elem,  0, V.size()); //整体复制
    return *this; //返回当前对象的引用，以便链式赋值
}
#endif //FUNDEMENTALADT_VECTOR_ASSIGNMENT_H
