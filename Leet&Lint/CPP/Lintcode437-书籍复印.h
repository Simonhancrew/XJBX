#include <vector>
using namespace std;
//划分型动态规划，指定段数
class Solution {
public:
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        if(n == 0){
            return 0;
        }
        if(k > n){
            k = n;
        }
        //k个抄写的，前n本书
        vector<vector<int>> dp(k+1,vector<int>(n+1,INT_MAX));
        //处理一下0个抄写员，0本书的情况
        dp[0][0] = 0;
        // for(int i =1;i <= n;++i){
        //     dp[0][i] = INT_MAX;
        // }
        //反向处理，避免一直+
        int sum = 0;
        for(int i = 1;i<=k;++i){
            dp[i][0] = 0;
            for(int j = 1;j <= n;++j){
                dp[i][j] = INT_MAX;
                sum = 0;
                for(int m = j;m >= 0;--m){
                    dp[i][j] =min(dp[i][j],max(dp[i-1][m],sum));
                    if(m > 0){
                        sum += pages[m-1];
                    }
                }
            }
        }
        return dp[k][n];
    }
};