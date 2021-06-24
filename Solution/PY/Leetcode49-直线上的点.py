from typing import List
from collections import defaultdict

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        res = 0
        for p in points:
            dup,ver = 0,0
            cnt = defaultdict(int)
            for q in points:
                if p == q:
                    dup += 1
                elif p[0] == q[0]:
                    ver += 1
                else:
                    k = (p[1] - q[1]) / (p[0] - q[0])
                    cnt[k] += 1
            cur = ver
            for k,t in cnt.items():
                cur = max(cur,t)
            res = max(res,cur + dup)
        return res
        