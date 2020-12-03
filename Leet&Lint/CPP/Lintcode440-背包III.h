#include <vector>
#include <algorithm>
using namespace std;
//最值型背包
//动态规划的小技巧，如果在计算的时候会枚举很多项
//不妨回去看看之前的状态，可能之前在算状态转移时这些步骤已经算在内了
//优化的要点就是去找重复的步骤
//dp[i][w] = dp[i-1][w] ,dp[i][w - A[i-1]] + V[i-1]
//前i种，拼成w重量的最大价值 
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
                    dp[i][j] = max(dp[i][j],dp[i][j-A[i-1]] + V[i-1]);
                }
            }
        }
        int ret = 0;
        ret = *max_element(dp[n].begin(),dp[n].end());
        return ret;
    }
};

//单数组优化
class Solution {
public:
    int backPackIII(int m, vector<int> &A, vector<int> &V){
        int n = A.size();
        if(n == 0){
            return 0;
        }
        vector<int> dp(m+1,-1);
        //背包2相似
        //这里从前往后，刚刚好更新前部分之后当前值也可以更新
        dp[0] = 0;
        for(int i = 1;i <= n;++i){
            for(int w = 0;w <= m;++w){
                if(w >= A[i-1] && dp[w - A[i-1]] != -1){
                    dp[w] = max(dp[w],dp[w - A[i-1]] + V[i-1]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};