from typing import List
class NumArray:

    def __init__(self, nums: List[int]):
        self.sum = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            self.sum[i + 1] = self.sum[i] + nums[i]

    def sumRange(self, i: int, j: int) -> int:
        return self.sum[j + 1] - self.sum[i]