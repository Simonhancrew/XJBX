from typing import List
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        dt = [0] * (len(nums) + 1)
        for num in nums:
            dt[num] += 1
            if dt[num] > 1:
                ans.append(num)
        
        for i in range(1,n + 1):
            if dt[i] == 0:
                ans.append(i)
                break

        return ans