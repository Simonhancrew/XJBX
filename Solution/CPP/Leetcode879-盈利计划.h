#include <vector>

using namespace std;

// dp[i][j][k],代表从前i个中选，人数不少于j，利润大于等于k的所有计划数
// 这是一个二位的背包费用问题，把人数和利润抽象成称重。、
// 实际情况下，k是可以小于0的，但是题目环境下没有意义，用0代表这个状态。
// 初始化的时候从实际意义出发，前0个中选，任意人数（不少于），利润大于等于0的方案，实际意义下就至少是1

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int dp[n + 1][minProfit + 1];
        memset(dp,0,sizeof dp);
        for(int i = 0;i <= n;i++) dp[i][0] = 1;
        for(int i = 0;i < group.size();i++){
            int g = group[i],p = profit[i];
            for(int j = n;j >= g;j--){
                for(int k = minProfit;k >= 0;k--){
                    dp[j][k] = (dp[j][k] + dp[j - g][max(0,k - p)]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};