class Solution:
    def isUgly(self, n: int) -> bool:
        while n and n % 2 == 0:
            n /= 2
        while n and n % 3 == 0:
            n /= 3
        while n and n % 5 == 0:
            n /= 5
        return n == 1