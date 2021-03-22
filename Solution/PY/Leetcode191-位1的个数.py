class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n != 0:
            n -= n & (-n)
            res += 1
        return res