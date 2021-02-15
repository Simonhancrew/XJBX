from typing import List
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        maxcount = 0
        for _,j in enumerate(nums):
            if j == 1:
                count += 1
            else:
                maxcount = max(maxcount,count)
                count = 0
        maxcount = max(maxcount,count)
        return maxcount