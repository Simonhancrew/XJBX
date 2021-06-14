class Solution:
    def guessNumber(self, n: int) -> int:
        l,r = 1,n
        while l < r:
            mid = (l + r) >> 1
            if guess(mid) > 0:
                l = mid + 1
            else:
                r = mid 
        return l