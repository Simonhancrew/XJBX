#include <vector>
using namespace std;
/*
序列型动态规划一般需要开n+1长度的dp数组。
如果序列的最后对状态有要求，不妨直接设置出来，即dp[i][j]，j就是当前i的状态
另外在求值的时候，注意最小值的累加技巧，维护一个最小值和次小值，就不用每次加都遍历K了
*/

//dp[i][j] ->前i的序列，最后一位的颜色选择j，此时的最小花费
//因为最后一位的颜色已经确定了，dp[i-1][x]中，只要找到最小的dp[i-1][x]就可以了,其中x != j
//则找到dp[i-1][x]的 最小值。如果x=j,就找dp[i-1][x]的次小值。记录下他们的值和坐标

class Solution {
public:
    int minCostII(vector<vector<int>> &costs) {
        if(costs.size() == 0 || costs[0].size() == 0){
            return 0;
        }
        int n = costs.size();
        int K = costs[0].size();
        vector<vector<int>> dp(n+1,vector<int> (K));
        //前0个房子粉刷的代价
        for(int i = 0;i < K;++i){
            dp[0][i] = 0;
        }
        //每一次更新dp，找到在已经选定当前最后序列颜色时，之前dp中的最小和次小
        //min1和min2代表最小的次小，j1和j2是他们的坐标
        int min1 = INT_MAX,min2 = INT_MAX;
        int j1 = 0,j2 = 0;
        for(int i = 1;i <= n;++i){
            //找到前i序列之前的dp的最小和次小
            //记得每次都要重新赋值min
            min1 = INT_MAX,min2 = INT_MAX;
            for(int j = 0;j < K;++j){
                if(dp[i-1][j] < min1){
                    min2 = min1;
                    j2 = j1;
                    min1 = dp[i-1][j];
                    j1 = j;
                }else{
                    if(dp[i-1][j] < min2){
                        min2 = dp[i-1][j];
                        j2 = j;
                    }
                }
            }
            //赋值dp数组
            for(int j = 0;j < K;++j){
                //最小值+costs[i-1][j]
                if(j != j1){
                    dp[i][j] = dp[i-1][j1] + costs[i-1][j];
                }else{
                    //次小值+costs[i-1][j]
                    dp[i][j] = dp[i-1][j2] + costs[i-1][j];
                }
            }
        }

        //找到最后的最小值
        int res = INT_MAX;
        for(int i = 0;i < K;++i){
            res = min(res,dp[n][i]);
        }
        return res;
    }
};
