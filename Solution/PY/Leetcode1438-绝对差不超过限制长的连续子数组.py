from typing import List
from collections import deque
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        minlist,maxlist = deque(),deque()
        n = len(nums)
        left = right = 0
        ret = 0
        while right < n:
            while maxlist and maxlist[-1] < nums[right]:
                maxlist.pop()
            while minlist and minlist[-1] > nums[right]:
                minlist.pop()
            
            maxlist.append(nums[right])
            minlist.append(nums[right])

            while maxlist and minlist and maxlist[0] - minlist[0] > limit:
                if nums[left] == maxlist[0]:
                    maxlist.popleft()
                if minlist[0] == nums[left]:
                    minlist.popleft()
                left += 1
            
            ret = max(ret,right - left + 1)
            right += 1
        return ret