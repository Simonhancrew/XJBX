#include <vector>
using namespace std;
//最后一步的最优解
//一定会有一个j*j减完
//那么剩下的n-j*j的最优解？
//dp[i] -> 数字i可以被多少完全平方数组成
//dp[i] = min(dp[i - j*j] + 1),其中，1=<j*j<=i
class Solution {
public:
    int numSquares(int n) {
        //划分型动态规划
        vector<int> dp(n + 1,INT_MAX);
        //0可以被0个完全平方数拼成
        dp[0] = 0;
        for(int i = 1;i <= n;++i){
            //对于每一个i，求出他的最优解
            //j*j必须小于i
            for(int j = 1;j * j <= i;++j){
                if(dp[i - j*j] + 1 < dp[i]){
                    dp[i] = dp[i - j*j] + 1;
                }
            }
        }
        return dp[n];
    }
};


//等价于一个完全背包问题
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        memset(dp,0x3f,sizeof dp);
        dp[0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j * j <= i;j++){
                dp[i] = min(dp[i],dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};