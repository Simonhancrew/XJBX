from typing import List
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        l,res,n = 0,1,len(nums)
        need = 0
        for r in range(1,n):
            need += (r - l) * (nums[r] - nums[r - 1])
            while need > k:
                need -= nums[r] - nums[l]
                l += 1
            res = max(res,r - l + 1)
        return res
