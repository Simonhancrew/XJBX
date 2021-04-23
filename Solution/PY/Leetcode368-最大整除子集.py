from typing import List
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        dp = [1] * n
        nums.sort()
        k = 0
        for i in range(n):
            for j in range(0,i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[i],dp[j] + 1)
            if dp[k] < dp[i]:
                k = i
        res = []
        while True:
            res.append(nums[k])
            if dp[k] == 1:
                break
            for i in range(0,k):
                if nums[k] % nums[i] == 0 and dp[k ] == dp[i] + 1:
                    k = i
                    break
        return res