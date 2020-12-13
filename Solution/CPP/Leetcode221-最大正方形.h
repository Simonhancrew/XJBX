#include <vector>
#include <algorithm>
using namespace std;
//坐标型动态规划
//考虑最后一步，假设以(i,j)为右下角的是一个最大正方形，边长为L
//则(i-1,j)，(i-1,j-1),(i,j-1)为右下角的正方形边长最少为L-1
//则，(i,j)为右下角的正方形的边长就是之前的三个三个正方形边长的最小值 + 1
//这样就的到了子问题
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxLen = 0;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(matrix[i][j] == '1'){
                    if(i == 0||j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(min(dp[i - 1][j],dp[i - 1][j - 1]),dp[i][j - 1]) + 1;
                    }
                    maxLen = max(maxLen,dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        int res = maxLen * maxLen;
        return res;
    }
};

//滚动数组
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        int maxLen = 0;
        int old = 0,now = 0;
        for(int i = 0;i < m;++i){
            old = now;
            now = 1 - now;
            for(int j = 0;j < n;++j){
                if(matrix[i][j] == '1'){
                    if(i == 0||j == 0){
                        dp[now][j] = 1;
                    }else{
                        dp[now][j] = min(min(dp[old][j],dp[old][j - 1]),dp[old][j - 1]) + 1;
                    }
                    maxLen = max(maxLen,dp[now][j]);
                }else{
                    dp[now][j] = 0;
                }
            }
        }
        int res = maxLen * maxLen;
        return res;
    }
};