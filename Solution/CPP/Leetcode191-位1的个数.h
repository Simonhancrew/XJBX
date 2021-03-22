//还可以用lowbit
#include <cstdint>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            res += n&1;
            n >>= 1;
        }
        return res;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            n -= n & (-n);
            res++;
        }
        return res;
    }
};