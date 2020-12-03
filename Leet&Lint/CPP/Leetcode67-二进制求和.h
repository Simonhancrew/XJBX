#include <string>
using namespace std;
//技巧上，reverse两个str
//然后遍历全部的最大长度
//最后carry位还有值，就继续push一个1
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
        string ret = "";
        int n = max(a.size(),b.size());
        bool carry = false;
        for(int i = 0;i < n;++i){
            int cur = 0;
            if(carry){
                cur += 1;
                carry = false;
            }
            cur += i < a.size()?a[i] - '0':0;
            cur += i < b.size()?b[i] - '0':0;
            ret.push_back(cur%2 + '0');
            if(cur >= 2){
                carry = true;
            }
        }
        if(carry) ret.push_back('1');
        reverse(ret.begin(),ret.end());
        return ret;
    }
};