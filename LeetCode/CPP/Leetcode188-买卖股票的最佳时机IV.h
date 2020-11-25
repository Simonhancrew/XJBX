#include <vector>
#include <climits>
using namespace std;
//像是一个数组分slice
//分阶段，1 3 5 2k+1 阶段中手中没有持有股票
//dp[i][j] = max(昨天没有持有股票，昨天持有股之后今天卖了且不买入)
//阶段 2，4，2k手中持有股票
//dp[i][j] = max(昨天持有且今天继续持有，昨天不持有且今天买入，昨天有前前一个状态的股票且今天立即卖出且买入)
//在k>N/2时，因为卖出买入要两天，等价于找到山峰山谷，求最大收益
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        //就等于多与一半的天数可以买入，基本就等于白给k
        if(k > n/2){
            int res = 0;
            for(int i = 0;i < n-1;++i){
                //只要上升就+
                res += max(prices[i+1] - prices[i],0);
            }
            return res;
        }
        //序列型开数组的技巧,k多开是因为懒得处理0，阶段从1开始
        vector<vector<int>> dp(n+1,vector<int> (2*k + 2));
        dp[0][1] = 0;
        //之后的全部赋值位INT_MIN
        for(int i = 2;i <= 2*k + 1;++i){
            dp[0][i] = INT_MIN;
        }
        for(int i = 1;i <= n;++i){
            //奇数阶段,手中不持有股票
            for(int j = 1;j <= 2 * k + 1;j += 2){
                dp[i][j] = dp[i-1][j];
                //i也要大于1否则没意义，前一天在持有股票，且当天卖出，今天不持有
                if(j > 1 && i > 1 && dp[i-1][j-1] != INT_MIN){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + prices[i-1] - prices[i-2]);
                }
            }
            //偶数阶段
            for(int j = 2;j <= 2*k+1;j += 2){
                //昨天没持有股票，今天买入
                dp[i][j] = dp[i-1][j-1];
                //昨天持有，今天继续获利
                if(i > 1 && dp[i-1][j] != INT_MIN){
                    dp[i][j] = max(dp[i][j],dp[i-1][j] + prices[i-1] - prices[i-2]);
                }
                //
                if(i > 1 && j > 2 && dp[i-1][j-2] != INT_MIN){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-2] + prices[i-1] - prices[i-2]);
                }
            }
        }
        int res = INT_MIN;
        for(int i = 1;i <= 2*k + 1;i += 2){
            res = max(res,dp[n][i]);
        }
        return res;
    }
};