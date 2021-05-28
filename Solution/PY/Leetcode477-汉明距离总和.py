from typing import List
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for i in range(30):
            c = 0
            for num in nums:
                if num >> i & 1 == 1:
                    c += 1
            res += c * (n - c)
        return res