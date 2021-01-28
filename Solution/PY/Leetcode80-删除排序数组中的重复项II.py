from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count,ptr = 1,1
        n = len(nums)
        for i in range(1,n):
            if nums[i-1] == nums[i]:
                count += 1
            else:
                count = 1
            
            if count <= 2:
                nums[ptr] = nums[i]
                ptr += 1

        return ptr
