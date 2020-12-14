//位运算
//不进位的用异或，进位的信息用与左移一位
//不断的对进位信息和不进位信息执行加，这个加分为两不，一步求不进位信息，一步求进位信息
//直到进位信息为0
class Solution {
public:
    int add(int a, int b) {
        while(b != 0){
            //负数不支持左移
            int carry = (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};