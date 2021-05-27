class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        s = x ^ y
        ans = 0
        while s:
            s -= (s & (-s))
            ans += 1
        return ans