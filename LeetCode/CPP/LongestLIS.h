class Solution {
    lt300 ，最长上升子序列，可以用二分查找优化。dp[i]->以i位置元素为结尾的最大上升序列长度
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<int> dp(nums.size(),0);
        dp[0]=1;
        int Lis =1;
        for(int i=1;i<dp.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            if(Lis<dp[i]){
                Lis = dp[i];
            }
        }
        return Lis;
    }
};