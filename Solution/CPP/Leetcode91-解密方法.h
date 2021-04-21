#include <string>
#include <vector>
using namespace std;
//划分型动态规划
//最后一步，最后一个char解密，或者时最后两个char可以解密
//则解码的方法总数就是到dp[i-1]和dp[i-2]的和
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        if(n == 0) return 0;
        dp[0] = 1;
        for(int i = 1;i <= n;++i){
            //一个digit
            int t = s[i-1] - '0';
            //字符的合理判断
            if(t >= 1 && t <= 9){
                dp[i] += dp[i-1];
            }
            //两个digit
            if(i >= 2){
                //是否可以解密的判断
                t = (s[i-2] - '0')*10 + (s[i-1] -'0');
                if(t >= 10 && t <= 26){
                    dp[i] += dp[i-2]; 
                }
            }
        }
        return dp[n];
    }
};

//dp要用到i-1状态的话一般多开

class Solution2 {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            if(s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];
            if(i > 1){
                int t = (s[i- 1] - '0') * 10 + s[i] - '0';
                if(t >= 10 && t <= 26) dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};