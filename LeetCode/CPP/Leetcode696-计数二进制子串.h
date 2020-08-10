//利用相关数组去解题，计数数连续的个数，{....last,now,....}满足调教的子串一定是min(last,now),我们只关心last和现在这个数的cout，所以可以省一个数组
#include<string>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr = 0,last = 0,n = s.size();
        int res = 0;
        //这种大范围更新的话就可以考虑while,算是一个经验吧。
        while(ptr <n){
            char c = s[ptr];
            int count = 0;
            while(ptr<n && s[ptr] == c){
                ptr++;
                count++;
            }
            res += min(last,count);
            last = count;
        }
        return res;
    }
};