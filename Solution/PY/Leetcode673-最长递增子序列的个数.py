from typing import List
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        count = [1] * n
        maxcount = 0
        if n <= 1:
            return n
        for i in range(1,n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[i] < dp[j]+1:
                        dp[i] = dp[j] + 1
                        count[i] = count[j]
                    elif dp[j] + 1 == dp[i]:
                        count[i] += count[j]
                maxcount = max(dp[i],maxcount)
        ans = 0
        for i in range(n):
            if dp[i] == maxcount:
                ans += count[i]
        return ans
