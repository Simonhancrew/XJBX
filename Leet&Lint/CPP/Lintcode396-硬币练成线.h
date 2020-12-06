#include <vector>
using namespace std;
//区间型动态规划，加上博弈
//当成一个人来选
//区间型要用len来往下走
//针对每个区间，最大化自己可以拿的值
class Solution {
public:
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if (n <= 1) return true;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = values[i];
        }
        
        for (int len = 1; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                dp[i][j] =  max(values[i] - dp[i + 1][j], values[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};