#include <climits>
class Solution {
public:
    int divide(int dividend, int divisor){
        if(dividend == 0){
            return 0;
        }
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend > INT_MIN){
                return -dividend;
            }
            return INT_MAX;
        }
        long a = dividend,b = divisor;
        int sign = -1;
        if((a>0 && b > 0) || (a < 0 && b < 0)){
            sign = 1;
        }
        a = a > 0?a:-a;
        b = b > 0?b:-b;
        long res = div(a,b);
        if(sign>0){
            return res > INT_MAX?INT_MAX:res;
        }
        return -res < INT_MIN?INT_MIN:-res;
    }
private:    
    long div(long a,long b){
        if(a < b) return 0;
        long count = 1;
        long tb = b;
        while(tb +tb <= a){
            count += count;
            tb += tb;
        }
        return count + div(a - tb,b);
    }
};