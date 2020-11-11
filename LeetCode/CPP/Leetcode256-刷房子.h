#include <vector>
#include <climits>
using namespace std;
//序列型动态规划
//还是找最后一步，但最后一步受到之前一部颜色的限制，就再记录之前的颜色
//不知道能不能过
//记录dp[i][j],到了i位置的最小值，i-1位置走的是cost[j].
class Solution{
public:
    int minCost(vector<vector<int>>& costs){
        if(costs.empty()||costs[0].empty()) return 0;
        int m = costs.size();
        //开dp数组注意要大一位
        vector<vector<int>> dp(m+1,vector<int> (3,INT_MAX));
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i = 1;i <= m;++i){
            //i-1位置的颜色
            for(int j = 0;j < 3;++j){
                //i-2位置的颜色选择costs[k]
                for(int k = 0;k < 3;++k){
                    //颜色不相同
                    if(j == k){
                        continue;
                    }
                    //小值更新
                    if(dp[i][j] > dp[i-1][k]+costs[i-1][j]){
                        dp[i][j] = dp[i-1][k] + costs[i-1][j];
                    }
                }
            }
        }
        int res = min(min(dp[m][0],dp[m][1]),dp[m][2]);
        return res;
    }
};