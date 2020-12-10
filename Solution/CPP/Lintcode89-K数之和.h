#include <vector>
using namespace std;
//形如背包类动态规划
//只不过加入了选择的次数
//那就选择次数进状态
//dp[i][j][k]前i个数，选择j个，总和为k
class Solution {
public:
    int kSum(vector<int> &A, int k, int target) {
        int n = A.size();
        int dp[n + 1][k+1][target+1];
        //初始条件
        for(int i = 0;i <= k;++i){
            for(int j = 0;j <= target;++j){
                dp[0][i][j] = 0;
            }
        }
        dp[0][0][0] = 1;
        //顺序
        for(int i = 1;i <= n;++i){
            for(int j = 0;j <= k;++j){
                for(int s = 0;s <= target;++s){
                    //不选最后一个
                    dp[i][j][s] = dp[i-1][j][s];
                    //选最后一个
                    if(j > 0 && s >= A[i-1]){
                        dp[i][j][s] += dp[i - 1][j - 1][s - A[i - 1]];
                    }
                }
            }
        }

        return dp[n][k][target];
    }
};

//滚动数组优化
class Solution {
public:
    int kSum(vector<int> &A, int k, int target) {
        int n = A.size();
        int dp[n + 1][k+1][target+1];
        int old = 0,now = 0;
        //初始条件
        for(int i = 0;i <= k;++i){
            for(int j = 0;j <= target;++j){
                dp[now][i][j] = 0;
            }
        }
        dp[0][0][0] = 1;
        //顺序
        for(int i = 1;i <= n;++i){
            old = now;
            now = 1- now;
            for(int j = 0;j <= k;++j){
                for(int s = 0;s <= target;++s){
                    //不选最后一个
                    dp[now][j][s] = dp[old][j][s];
                    //选最后一个
                    if(j > 0 && s >= A[i-1]){
                        dp[now][j][s] += dp[old][j - 1][s - A[i - 1]];
                    }
                }
            }
        }

        return dp[now][k][target];
    }
};