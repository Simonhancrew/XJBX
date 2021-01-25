from typing import List
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid)
        parent = list(range(4 * n * n))
        def find(x:int) -> int:
            if parent[x] == x:
                return x
            parent[x] = find(parent[x])
            return parent[x]
        def union(x,y):
            fx,fy = find(x),find(y)
            if fx == fy:
                return 
            parent[fy] = fx
        for i in range(n):
            for j in range(n):
                idx = 4 * (i * n + j)
                if grid[i][j] == '/':
                    union(idx,idx + 3)
                    union(idx + 1,idx + 2)
                else:
                    union(idx,idx + 1)
                    union(idx+2,idx + 3)
                if grid[i][j] == ' ':
                    union(idx,idx+3)
                if i > 0:
                    union(idx,idx - 4 * n + 2)
                if j > 0:
                    union(idx + 3,idx -3)
        cnt = 0
        for i in range (4 *n *n):
            if parent[i] == i:
                cnt+=1

        return cnt