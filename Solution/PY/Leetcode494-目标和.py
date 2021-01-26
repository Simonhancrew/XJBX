from typing import List
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:    
        sum = 0
        n = len(nums)
        for num in nums:
            sum += num
        if S > sum:
            return 0
        if (S + sum) % 2 == 1:
            return 0
        val = (S + sum) // 2 
        dp = [0] * (val + 1) 
        dp[0] = 1
        for i in range(n):
            #左闭右开，注意方向
            for j in range(val,nums[i] - 1,-1):
                dp[j] += dp[j - nums[i]]
        return dp[val]