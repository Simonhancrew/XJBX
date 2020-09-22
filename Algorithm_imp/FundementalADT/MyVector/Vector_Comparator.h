//
// Created by han on 2020/9/22.
//

#ifndef FUNDEMENTALADT_VECTOR_COMPARATOR_H
#define FUNDEMENTALADT_VECTOR_COMPARATOR_H
//朴实无华比较
template<typename T> static bool lt(T* a,T* b){return lt(*a,*b);}
template<typename T> static bool lt(T& a,T& b){return a<b;}
template<typename T> static bool eq(T* a,T* b){return eq(*a,*b);}
template<typename T> static bool eq(T& a,T& b){return a == b;}

#endif //FUNDEMENTALADT_VECTOR_COMPARATOR_H
