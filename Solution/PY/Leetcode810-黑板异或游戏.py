from typing import List
class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        res = 0
        if len(nums) % 2 == 0:
            return True
        for num in nums:
            res ^= num
        return res == 0