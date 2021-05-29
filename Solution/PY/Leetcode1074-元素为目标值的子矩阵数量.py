from collections import defaultdict
from typing import List
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        ans = 0
        m,n = len(matrix),len(matrix[0])
        def count(presum,target):
            mp = defaultdict(int)
            # mp[0] = 1
            res,cur = 0,0
            for _,val in enumerate(presum):
                cur += val
                if mp[cur - target]:
                    res += mp[cur - target]
                mp[cur] += 1
            return res
        for i in range(m):
            presum = [0] * n
            for j in range(i,m):
                for k in range(0,n):
                    presum[k] += matrix[j][k]
                ans += count(presum,target)
        return ans