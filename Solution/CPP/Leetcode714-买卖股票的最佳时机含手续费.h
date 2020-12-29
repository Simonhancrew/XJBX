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
            //最开始的状态
            //找到一个买入点，只要更低了就可以怀疑是一个买入点
            if(prices[i] < minp){
                minp = prices[i];
            }
            //一个点，卖出不赚钱，但他确实比低点高，继续往下走，此时我进第二个状态
            //这个状态可以回到状态一
            if(prices[i] >= minp && prices[i] <= minp + fee){
                continue;
            }
            //卖出赚钱了，但我需要考虑后序还能不能赚到更多
            //我进入当前这个状态
            if(prices[i] > minp + fee){
                //收集当前的利润
                res += prices[i] - minp - fee;
                //下一个点不知道能不能继续增长，但无论如何，
                //该状态只能保持或者回到状态1，如果回到状态1的话我的minp也是要更新的
                //下一个点的值只要大于peice[i]就可以继续增，
                //但此时我假设是没有卖出的，下一步还有fee的影响，要去掉fee带来的负面影响
                //更新minp减掉一个fee
                minp = prices[i] - fee;
            }
        }
        return res;
    }
};