#include <vector>
#include <algorithm>
using namespace std;
//最值型背包
//最后一步，放了最后一个，之前的n-1价值v，放了之后v+V[i]
//最后一步，不能放，之前的，v，最后v
//同之前的背包，状态栏序列长度加重量，状态值是最大价值
//dp[i][w] = 前i个值能拼出重量为w的背包的最大价值 
class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int n = A.size();
        if(n == 0){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        dp[0][0]=0;
        for(int i = 1;i <= n;++i){
            for(int j = 0;j <= m;++j){
                dp[i][j] = dp[i-1][j];
                if(j >= A[i - 1] && dp[i-1][j - A[i-1]] != -1){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-A[i-1]] + V[i-1]);
                }
            }
        }
        int ret = 0;
        ret = *max_element(dp[n].begin(),dp[n].end());
        return ret;
    }
};

//单数组优化，因为从后向前更新覆盖之前的值，前面的值和后面的无关
class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V){
        int n = A.size();
        if(n == 0){
            return 0;
        }
        vector<int> dp(m+1,-1);
        dp[0] = 0;
        for(int i = 1;i <= n;++i){
            for(int w = m;w >= 0;--w){
                if(w >= A[i-1] && dp[w - A[i-1]] != -1){
                    dp[w] = max(dp[w],dp[w - A[i-1]] + V[i-1]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};