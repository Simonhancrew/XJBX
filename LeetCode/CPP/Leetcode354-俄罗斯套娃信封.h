#include <vector>
#include <algorithm>
//这其实是一个坐标型动态规划->以XX结尾的位置有多少最优解
//序列型->前XX位置的最优解
//最长上升序列的变种
//dp[i] = max(dp[i],dp[j] + 1 & j < i & 放的进去)
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0 || envelopes[0].size() == 0){
            return 0;   
        }
        int n = envelopes.size();
        vector<int> dp(n);
        //按照信封的第一个值排序，之后就变最长上升序列类似的问题了
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &lhs,vector<int> &rhs){
            if(lhs[0] == rhs[0]){
                return lhs[1] < rhs[1];
            }else{
                return lhs[0] < rhs[0];
            }
        });

        int res = 1;

        for(int i = 0;i < n;++i){
            dp[i] = 1;
            //j < i
            for(int j = 0;j < i;++j){
                //能被放进信封，一定要大于，相等的放不进去
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
//需要优化且可以优化，复杂度O(n*n)