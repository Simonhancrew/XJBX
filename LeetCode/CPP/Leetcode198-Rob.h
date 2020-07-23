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
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};