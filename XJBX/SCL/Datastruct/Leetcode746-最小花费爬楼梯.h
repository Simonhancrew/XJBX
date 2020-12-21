#include <vector>
using namespace std;
//坐标型动态规划，考虑最后一步，之前从i-1跳到i或者从i-2跳到i，取最小值，
//要注意i是最后一个楼梯的更上一级
//此时假设从i-1级跳到i，则cost是之前跳到i-1的cost+cost[i-1](注意跳到i-1是还没算当前级的cost)
//我们要跳到最后的顶部
//初始可以从0级和1级起跳
//第1级跳过去的cost是cost[0]
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n + 1];
        dp[0] = 0,dp[1] = 0;
        for(int i = 2;i <= n;++i){
            dp[i] = min(dp[i - 1] + cost[i - 1],dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int pre = 0,cur = 0,aft = 0;
        for(int i = 2;i <= n;++i){
            aft = min(cur + cost[i - 1],pre + cost[i - 2]);
            pre = cur;
            cur = aft;
        }
        return aft;
    }
};
