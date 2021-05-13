#include <cstring>
#include <algorithm>
//1 不考虑不动和往后跳，能跳到的最大idx就是min(arrlen,steps)
//2 考虑转移方程，这里跳的次数要放前面，不然基本会想不出来
//3 可以从3种方式转移过来，不动或者左右跳过来，注意边界的判断
using namespace std;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int mod = 1e9 + 7;
        int maxjump = min(steps,arrLen);
        int dp[steps + 1][maxjump];//dp[i][j]，跳了i步，到达了j位置
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        for(int i = 1;i <= steps;i++){
            for(int j = 0;j < maxjump;j++){
                dp[i][j] = dp[i - 1][j];
                if(j - 1 >= 0){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod; 
                }
                if(j + 1 < maxjump){
                    dp[i][j] = (dp[i - 1][j + 1] + dp[i][j]) % mod;
                }
            }
        }
        return dp[steps][0];
    }
};