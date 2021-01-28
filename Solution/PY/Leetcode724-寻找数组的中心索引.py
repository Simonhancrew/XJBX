from typing import List
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return -1
        totalSum = 0
        for num in nums:
            totalSum += num
        sum = 0
        for i in range(n):
            if totalSum - nums[i] - sum == sum:
                return i
            sum += nums[i]
        return -1