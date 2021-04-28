#include <cmath>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        bool flag = false;
        for(long a = 0;a * a <= c;a++){
            long b = sqrt(c - a * a);
            if(a * a + b * b == c) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};