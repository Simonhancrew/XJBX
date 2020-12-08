#include <string>
using namespace std;
//双序列型动态规划
//考虑s的前i，t的前j
//最后一部，前面子问题最优，t的最后一个字符和s的最后一个字符结合成对
//考虑之前的dp[i - 1][j - 1]
//加入这两个不结成对,去掉s的最后一个数
//dp[i -1][j]
//dp[i][j],s的前i个数，t的前j个数组成多少个不同的子序列
//可以开2维滚动数组优化
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(),n = t.size();
        long long dp[m + 1][n + 1];
        for(int i = 0;i <= m;++i){
            for(int j = 0;j <= n;++j){
                //初始条件，s为空，物理意义
                if(i == 0 && j != 0){
                    dp[i][j] = 0;
                    continue;
                }
                //s不空，t空，则考虑转移方程dp[i][1]
                //加入最后一个对子能结成，则dp[i][1] = dp[i-1][0] + dp[i - 1][1];
                //dp[1][1] = dp[0][0](s[1] == t[1]) + dp[0][1]
                //所以s不空，t空要设为1
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j];
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] += dp[i - 1][j - 1];
                }
                
            }
        }
        return dp[m][n];
    }
};