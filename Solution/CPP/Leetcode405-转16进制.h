#include <string>
using namespace std;
//位运算
class Solution {
public:
    string toHex(int num) {
        string pattern = "0123456789abcdef";
        string ans = "";
        //后4位和全1与，得到4位变成16进的值
        int mod = 0xf;
        //最大int，32位，最多移8次
        int shift = 0;
        if(num == 0){
            return "0";
        }
        while(num && shift < 8){
            //16进的值
            int index = num & mod;
            //避免之后的reverse
            ans = pattern[index] + ans;
            num >>= 4;
            shift++;
        }
        return ans;
    }
};