#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1,dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1,dp2 = 1;
        int dp3 = 1;
        for(int i = 2;i <= n;i++){
            dp3 = dp2 + dp1;
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
};