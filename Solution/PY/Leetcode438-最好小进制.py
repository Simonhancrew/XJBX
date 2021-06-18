import math

class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)
        for t in range(int(math.log(n,2)) + 1,2,-1):
            r,k = 0,int(math.pow(n,1.0 / (t - 1))) 
            for _ in range(t): r = r * k + 1
            if r == n:return str(k)
        return str(n - 1)