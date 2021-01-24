from typing import List
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:  
        n = len(nums)
        if n <= 1:
            return n
        dp = [1] * n
        maxLis = 0
        for i in range(1,n):
            for  j in range(0,i):
                if nums[i] > nums[j] and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1

            maxLis = max(dp[i],maxLis)

        return maxLis            