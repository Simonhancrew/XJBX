//
// Created by han on 2020/9/22.
//

#ifndef FUNDEMENTALADT_VECTOR_TRAVERSE_H
#define FUNDEMENTALADT_VECTOR_TRAVERSE_H
#include "Vector.h"
//函数指针
template <typename T> void Vector<T>::traverse(void(*visit)(T&)) {
    for(int i =0;i<_size;i++){
        visit(_elem[i]);
    }
}
template <typename T> template <typename VST>
void Vector<T>::traverse ( VST& visit )
{ for ( int i = 0; i < _size; i++ ) visit ( _elem[i] ); } //遍历向量


template <typename T> struct Increase //函数对象：递增一个T类对象
{  virtual void operator() ( T& e ) { e++; }  }; //假设T可直接递增或已重载++

template <typename T> void increase ( Vector<T> & V ) //统一递增向量中的各元素
{  V.traverse ( Increase<T>() );  } //以Increase<T>()为基本操作进行遍历
#endif //FUNDEMENTALADT_VECTOR_TRAVERSE_H
