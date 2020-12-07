#include <vector>
#include <climits>
using namespace std;
//分阶段
/*
    1 没有持有
    2 买入第一次
    3 卖出第一次之后还没买入
    4 卖出了第一次，买入第二次
    5 卖出第二次及之后的状态
*/
class Solution {
public:
    int maxProfit(vector<int> &prices){
        if(prices.size() == 0){
            return 0;
        }
        int n = prices.size();
        //coding上的处理，不要dp[X][0]
        vector<vector<int>> dp(n+1,vector<int>(6,0));
        dp[0][1] = 0;
        dp[0][2] = dp[0][3] = dp[0][4] = dp[0][5] = INT_MIN;
        //dp[i][j] 前i天，在阶段j，获利状态
        for(int i = 1;i <= n;++i){
            //case1 立足在阶段135，手中没有股票的状态
            for(int j = 1;j <= 5;j += 2){
                //前一天就没有持有股票了，在这个阶段
                dp[i][j] = dp[i-1][j];
                //前一天持有股票，今天卖出
                if(j > 1 && i > 1 && dp[i - 1][j - 1] != INT_MIN){
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                }
            }
            //case2 立足在阶段24，手中持有股票
            for(int j = 2;j <= 5;j += 2){
                //前一天，没有持有股票，今天买入，收入不计算，进入状态2
                dp[i][j] = dp[i - 1][j - 1];
                //昨天就持有股票，继续获利，状态2继续保持
                if(i > 1 && dp[i - 1][j] != INT_MIN){
                    dp[i][j] = max(dp[i][j],dp[i - 1][j] + prices[i - 1] - prices[i - 2]);
                }
                //昨天持有上一次的股票，今天卖了，立刻买入，进入状态4
                if(j > 2 && dp[i - 1][j - 2] != INT_MIN){
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - 2] + prices[i - 1] - prices[i-2]);
                }
            }
        }
        return max(max(dp[n][1],dp[n][3]),dp[n][5]);
    }
};