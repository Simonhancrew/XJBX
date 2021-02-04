from typing import List
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        ans = 0
        sum = 0
        for i in range(k):
            sum += nums[i]
        ans = sum / k
        n = len(nums)
        for i in range(k,n):
            sum += (nums[i] - nums[i - k])
            ans = max(ans,sum / k)
        return ans