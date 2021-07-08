from typing import List

class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        l1,l2,res = 0,0,0
        n,s1,s2 = len(nums),0,0
        for i in range(n):
            s1 += nums[i]
            while l1 <= i and s1 > goal:
                s1 -= nums[l1]
                l1 += 1
            s2 += nums[i]
            while l2 <= i and s2 >= goal:
                s2 -= nums[l2]
                l2 += 1
            res += l2 - l1
        return res