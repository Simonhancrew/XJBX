from typing import List
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        row = len(nums)
        col = len(nums[0])
        if row * col != r * c:
            return nums
        ans = [[0] * c for _ in range(r)]
        for i in range(r):
            for j in range(c):
                l = (i * c + j) // col
                r = (i * c + j) % col
                ans[i][j] = nums[l][r]
        return ans