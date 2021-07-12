from typing import List
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l,r = 0,len(citations)
        n = len(citations)
        def check(idx):
            return citations[n - idx] >= idx
        while l < r:
            mid = (l + r + 1) >> 1
            if(check(mid)): l = mid
            else: r = mid - 1
        return l