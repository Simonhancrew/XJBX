#include <stdint.h>
//取余
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            count += n % 2;
            n = n / 2;
        }
        return count;
    }
};

//mask与
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            ++count;
            n &= (n - 1);//n和n-1与会把最低位的1消除
        }
        return count;
    }
};