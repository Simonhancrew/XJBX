//如果加减都不能用，一定第一时间想位运算
class Solution {
public:
    int getSum(int a, int b) {
        return b==0?a:getSum(a^b,(unsigned int)(a&b)<<1);
    }
};


class Solution {
public:
    int getSum(int a,int b){
        while(b != 0){
            int sum = a ^ b;
            //如果是个负数的话，与之后造成的位移是未定义的
            auto carry = ((unsigned int)(a & b)) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
    