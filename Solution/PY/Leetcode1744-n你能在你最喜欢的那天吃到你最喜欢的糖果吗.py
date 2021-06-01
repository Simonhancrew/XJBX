from typing import List

class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(candiesCount)
        presum = [0] * n
        presum[0] = candiesCount[0]
        for i in range(1,n):
            presum[i] = presum[i - 1] + candiesCount[i]
        
        ans = []
        for query in queries:
            ftype,day,cap = query[0],query[1],query[2]
            x1,y1 = day + 1,(day + 1) * cap
            x2 = 1 if ftype == 0 else presum[ftype - 1] + 1
            y2 = presum[ftype]
            ans.append(not(x1 > y2 or y1 < x2))
       
        return ans