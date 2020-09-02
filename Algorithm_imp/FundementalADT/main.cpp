#include <iostream>
#include "Bubblesort/BubbleSort2.h"
int main() {
    int a[] = {1,2,34,4,5,7,8,9,0,123,123123,44,2};
    bubbleSort2(a,sizeof(a)/sizeof(a[0]));
    for(auto i:a){
        std::cout<<i<<',';
    }
    std::cout<<std::endl;
    return 0;
}
