#include <string>
#include <sstream>
using namespace std;
//找到不和规则的悬崖，悬崖之前递减的数全部-1，悬崖之后的数替换成9
//注意stringstream的使用
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        int t = num.size();
        for(int i = num.size() - 1;i >= 1;--i){
            if(num[i-1] > num[i]){
                t = i;
                num[i-1]--;
            }
        }
        while(t < num.size()){
            num[t++] = '9';
        }
        stringstream s(num);
        int res = 0;
        s >> res;
        return res;
    }
};