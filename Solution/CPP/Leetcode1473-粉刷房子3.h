#include <vector>
#include <algorithm>
using namespace std;
//考虑最后一步，此时已经全涂完，有target个区域了，最后一个房子的颜色是k。之前的房子的颜色是u，则分情况，u和k是不是一种颜色
//dp[i][j][k] 将前i个房子分割j个区块，最后一个房子的颜色是k
//结果对所有的target分割取min
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 0x3f3f3f3f;//初始无穷大
        int dp[m][target + 1][n+1];
        memset(dp,0x3f,sizeof dp);
        if(houses[0]){
            dp[0][1][houses[0]] = 0;
        }else{
            for(int i = 1;i <= n;i++){
                dp[0][1][i] = cost[0][i - 1];
            }
        }

        for(int i = 1;i < m;i++){
            for(int j = 1;j <= target;j++){
                if(houses[i]){
                    int k = houses[i];
                    for(int u = 1;u <= n;u ++){
                        if(u == k){
                            dp[i][j][k] = min(dp[i][j][k],dp[i - 1][j][u]);
                        }else{
                            dp[i][j][k] = min(dp[i][j][k],dp[i - 1][j - 1][u]);
                        }
                    }
                }else{
                    for(int k = 1;k <= n;k++){
                        for(int u = 1;u <= n;u++){
                            if(u == k)
                                dp[i][j][k] = min(dp[i][j][k],dp[i - 1][j][u] + cost[i][k - 1]);
                            else
                                dp[i][j][k] = min(dp[i][j][k],dp[i - 1][j - 1][u] + cost[i][k - 1]);
                        }
                    }
                }
            }
        }
        int res = INF;
        for(int i = 1;i <= n;i++) res = min(res,dp[m - 1][target][i]);
        if (res == INF) res = -1;
        return res;
    }
};