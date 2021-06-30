from typing import List

class Solution:
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        edges = [[] for _ in range(n)]
        for s2d in relation:
            edges[s2d[0]].append(s2d[1])
        ans = [0]
        def dfs(idx,step,ans):
            if step == k:
                if idx == n - 1:
                    ans[0] += 1
                return 
            for dst in edges[idx]:
                dfs(dst,step + 1,ans)
        dfs(0,0,ans)
        return ans[0]