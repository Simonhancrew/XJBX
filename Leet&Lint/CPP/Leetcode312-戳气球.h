#include <vector>
using namespace std;
//区间型动态规划，考虑怎么处理扎破气球的消去
//关于这种需要消去的，从最后一步去考虑，
//考虑最后一个扎破的气球，然乎他两边是还有一个1的，
//维护一个区间动态，这样就将气球分割开了
//dp[i][j]为扎破i+1 -> j-1最多可获得的金币数
//k是扎破ij之前扎破的气球
//dp[i][j] = dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]
//k从i+1到j-1
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> A(n+2,0);
        A[0] = A[n + 1] = 1;
        for(int i = 1;i <= n;i++){
            A[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n+2,vector<int> (n + 2,0));
        //没有气球要扎破的时候全0
        // for(int i = 0;i < n + 1;++i){
        //     dp[i][i + 1] = 0;
        // }
        //区间动态第一个维护的是区间
        for(int len = 3;len <= n + 2;++len){
            //i <= n - len + 2
            for(int i = 0;i <= n-len +2;++i){
                int j = i +len - 1;
                for(int k = i + 1;k < j;++k){
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j]+ A[i]*A[k]*A[j]);
                }
            }
        }
        return dp[0][n+1];
    }
};