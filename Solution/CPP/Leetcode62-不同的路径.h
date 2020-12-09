#include <vector>
using std::vector;
//动态规划
//最后一步，能到达最后
//退后一步，形成递推
//考虑边界条件
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0] = 1;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(i == 0 ||j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};


//开2维滚动数组优化的方法
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[2][n];
        int old = 0;
        int now = 1;
        for(int i = 0;i < m;++i){
            old = now;
            now = 1- now;
            for(int j = 0;j < n;++j){
                if(i == 0||j == 0){
                    dp[now][j] = 1;
                    continue;
                }
                dp[now][j] = dp[now][j - 1] + dp[old][j];
            }
        }
        return dp[now][n - 1];
    }
};