from typing import List
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        n = len(nums)
        cnt = 0
        for i in range(0,n-1):
            x,y = nums[i],nums[i+1]
            if(x > y):
                cnt += 1
                if cnt > 1:
                    return False
                if i > 0 and nums[i+1] < nums[i-1]:
                    nums[i+1] = nums[i] 

        return True