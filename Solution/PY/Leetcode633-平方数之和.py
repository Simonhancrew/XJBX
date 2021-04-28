from math import sqrt
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c == 0:
            return True
        i = 0
        while i * i <= c:
            b = sqrt(c - i * i)
            if b == int(b):
                return True
            i += 1
        return False