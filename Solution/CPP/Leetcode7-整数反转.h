using namespace std;
#include<climits>
//溢出的问题的处理，a = a*10 +pop,溢出的话a*10一定大于intmax/10或者等于，但是pop不符合要求。
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > INT_MAX - INT_MAX / 10)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < INT_MIN - INT_MIN / 10)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            if(x > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            if(x < 0 && res < (INT_MIN - x % 10) / 10) return 0; 
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};