from typing import List
import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = [(grid[0][0],0,0)]
        seen = set()
        ret = 0
        while len(q) > 0:
            val,x,y = heapq.heappop(q)
            id = x * n + y
            if id in seen:
                continue
            seen.add(id)
            ret = max(ret,val)
            if (x,y) == (n-1,n-1):
                break
            for nx,ny in [[x-1,y],[x+1,y],[x,y+1],[x,y-1]]:
                if 0 <= nx < n and 0 <= ny < n:
                    nid = nx * n + ny
                    if nid not in seen:
                        heapq.heappush(q,(grid[nx][ny],nx,ny))

        return ret
