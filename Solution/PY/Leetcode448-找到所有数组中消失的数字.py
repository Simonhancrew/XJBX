from typing import List
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for num in nums:
            x = (num - 1) % n
            nums[x] += n
        ans = []
        for i in range(n):
            if nums[i] <= n:
                ans.append(i+1)
        return ans