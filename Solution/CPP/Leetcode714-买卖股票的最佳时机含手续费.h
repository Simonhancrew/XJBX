#include <vector>
using namespace std;
//dp[i][0]第i天的时候，手中没持有股票的最大收益
//因为手续费只需要付一次，我买入的时候就付了
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n < 2){
            return 0;
        }
        int dp[n][2];
        dp[0][0] = 0,dp[0][1] = -prices[0];
        for(int i = 1;i < n;++i){
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][0] - prices[i],dp[i - 1][1]);
        }
        return dp[n - 1][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[2][2];
        int old = 0,now = 0;
        dp[0][0] = 0,dp[0][1] = -prices[0];
        for(int i = 1;i < n;++i){
            old = now, now = 1- now;
            dp[now][0] = max(dp[old][0],dp[old][1] + prices[i] - fee);
            dp[now][1] = max(dp[old][0] - prices[i],dp[old][1]);
        }
        return dp[now][0];
    }
};


//贪心
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minp = prices[0];
        for(int i = 1;i < prices.size();++i){
            if(prices[i] < minp){
                minp = prices[i];
            }
            if(prices[i] >= minp && prices[i] <= minp + fee){
                continue;
            }
            if(prices[i] > minp + fee){
                res += prices[i] - minp - fee;
                minp = prices[i] - fee;
            }
        }
        return res;
    }
};