#include<vector>
#include <stdlib.h>
#include <climits>
using namespace std;
//最值型动态规划
//最后一步，A的最后一个元素变成B中最后一个的元素，前面的子问题最优
//前面一步中，B改变成的数字j,abs(x - j) <= target,动态规划就要前一个值进状态
//dp[i][j]前i个序列的最小值，当A[i-1]变成j。
//根据题目，b中每一个数也应该在1-100
//dp[i][j] = dp[i-1][k] + abs(A[i - 1] - j)其中 j - target<=k<=j + target
class Solution {
public:
    int MinAdjustmentCost(vector<int> &A, int target) {
        int n = A.size();
        int dp[n + 1][101];
        for(int i = 0;i <= 100;++i){
            //初始条件
            dp[1][i] = abs(i - A[0]);
        }
        for(int i = 2;i <= n;++i){
            for(int j = 0;j <= 100;++j){
                //数组声明的不要忘了赋值
                dp[i][j] = INT_MAX;
                //前一个子问题最后A[i-2]变成了k
                for(int k = j - target;k <= j + target;++k){
                    //超过区间的不用考虑
                    if(k < 0 || k >100){
                        continue;
                    }
                    dp[i][j] = min(dp[i][j],dp[i - 1][k] + abs(A[i - 1] - j));
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0;i <= 100;++i){
            res = min(res,dp[n][i]);
        }
        return res;
    }
};