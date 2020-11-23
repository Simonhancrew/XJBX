#include <vector>
using namespace std;
//对于圈的处理，就去处理首尾，找到不同的情况，去头去尾
//不同时处理，就变成序列了
class Solution {
public:
    int rob(vector<int> &nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        //case1 去头求res
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2;i < n;++i){
            //注意要加的nums的index
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        int res1 = dp[n-1];
        //case2 去尾求res
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2;i < n;++i){
            //注意index
            dp[i] = max(dp[i-1],dp[i-2] + nums[i-1]);
        }
        res1 = max(res1,dp[n-1]);
        return res1;
    }
};