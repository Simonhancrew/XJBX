//
// Created by han on 2020/9/2.
//

#include <algorithm>
void bubbleSort2(int a[],int n){
    int cmp =0,swp = 0;
    bool flag = false;
    while(!flag){
        flag = true;
        for(int i =0;i<n-1;i++){
            if(a[i]>a[i+1]){
                std::swap(a[i],a[i+1]);
                flag =false;
                swp++;
            }
            cmp++;
        }
    }
}