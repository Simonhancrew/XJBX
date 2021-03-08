#include <iostream>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        //这里的取-其实是取反码
        printf("%d",-n);
        while(n){
            n -= (n & -n);
            res++;
        }
        return res;
    }
};