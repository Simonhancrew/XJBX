class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0){
            return false;
        }
        while(n % 2 == 0){
            n = n / 2;
        }
        return n == 1;
    }
};

//如果是2的幂的话，转化成2进制是只有一位上有1的
//所以我们想办法拿到最右边的1，将其与位置置为0
//x & -x就可以拿到最右边的1，将其余位变为0
//此时与的结果应该是和x相等的
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        long x = n;
        return (x & (-x)) == x;
    }
};