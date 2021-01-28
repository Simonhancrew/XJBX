from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        fast,slow = 0,0
        n = len(nums)
        while fast < n:
            if nums[fast] == nums[slow]:
                fast += 1
            else:
                slow += 1 
                nums[slow] = nums[fast]
                fast += 1
        return slow + 1
                