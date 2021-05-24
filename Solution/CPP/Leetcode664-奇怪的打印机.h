#include <string>
using namespace std;


// dp[i][j] 将[i,j]染色成最终的样子的最少染色次数
// 1 我嫩找到头尾是一个字符的情况，如果头尾不是一个字符，刷完了也会背以后的覆盖，不会取到最小值
// 2 最特殊的情况就是没有字符与i一样了，dp[i][j] = dp[i + 1][j] + 1
// 3 其余的情况可以转移为 dp[i][k - 1] + dp[k + 1][j]，刷i的时候顺便刷了k

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int dp[101][101];//范围小于100
        memset(dp,0,sizeof dp);
        for(int len = 1;len <= n;len++){
            for(int i = 0;i + len - 1 < n;i++){
                int j = i + len - 1;
                dp[i][j] = 1 + dp[i + 1][j];
                for(int k = i + 1;k <= j;k++){
                    if(s[i] == s[k])
                        dp[i][j] = min(dp[i][j],dp[i][k - 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};