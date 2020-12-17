#include <vector>
using namespace std;
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