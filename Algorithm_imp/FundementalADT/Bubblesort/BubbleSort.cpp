//
// Created by han on 2020/9/1.
//
#include <algorithm>
void bubbleSort(int a[],int n){
    int cmp = 0,swp = 0;
    while (n--){
        for(int i =0;i<n;i++){
            if(a[i]>a[i+1]){
                std::swap(a[i],a[i+1]);
                swp++;
            }
            cmp++;
        }
    }
}
