#include <vector>
using namespace std;
class Solution {
//打家劫舍，动态规划
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        //序列型，开大一个dp空间，代表前n位的dp值
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            //选最后一个，不选最后一个
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};

//滚动优化
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        //序列型，开大一个dp空间，代表前n位的dp值
        int n = nums.size();
        int dp1 = 0;
        int dp2 = nums[0];
        int res = dp2;
        for(int i=2;i <= n;i++){
            //选最后一个，不选最后一个.
            //不选最后一个就是选了dp[i-1],选了就是dp[i-2] + nums[i-1]
            res = max(dp2,dp1+nums[i-1]);
            dp1 = dp2;
            dp2 = res;
        }
        return res;
    }
};