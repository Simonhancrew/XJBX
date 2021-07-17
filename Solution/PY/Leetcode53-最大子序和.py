from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans,n = nums[0],len(nums)
        dp = [0] * 2
        dp[0] = nums[0]
        old,now = 0,0
        for i in range(1,n):
            old = now
            now = 1- now
            dp[now] = max(nums[i],dp[old] + nums[i])
            ans = max(ans,dp[now])
        return ans