from typing import List

# 二分的上下界问题和存在性判断

class Solution:
    def search(self, nums: List[int], target: int) -> int: 
        if not nums:
            return 0 
        l,r = 0,len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        l1 = l
        if nums[l1] != target:
            return 0
        l,r = 0,len(nums) - 1
        while l < r:
            mid = (l + r + 1) // 2
            if nums[mid] <= target:
                l = mid
            else:
                r = mid - 1
        return l - l1 + 1