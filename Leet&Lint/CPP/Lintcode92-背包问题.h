#include <vector>
using namespace std;
//可行性背包
//最后一步，最后一个物品有没有进背包+最后一步背包的物品是那个
//背包问题，要把总承重放入状态，不然一定有问题
//因为最优策略中，前n-1个物品拼出的不一定是不超过target的最大值
//最后一步最优，能拼出最重（选和不选），最后一个物品放不放进背包
//于是需要两个状态，前i个物品和能否拼出w的重量
//dp[i][w] =dp[i-1][w] or dp[i-1][w - A[i-1]]
class Solution {
public:
    int backPack(int m, vector<int> &A) {
        int n = A.size();
        if(n == 0){
            return 0;
        }
        //看作序列型
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        //前0个，拼出0重量
        dp[0][0] = true;
        for(int i = 1;i <= n;++i){
            for(int j = 0;j <= m;++j){
                dp[i][j] = dp[i-1][j];
                //如果w不小于A[i-1]
                if(j >= A[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j - A[i-1]];
                }
            }
        }
        for(int i = m;i >=0;--i){
            if(dp[n][i]){
                return i;
            }
        }
        return 0;
    }
};