from typing import List
import copy
class UnionFind:
    def __init__(self,n):
        self.parent = list(range(n))
        self.rank = [1 for _ in range(n)]
    def find(self,x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self,x,y):
        fx = self.find(x)
        fy = self.find(y)
        if fx == fy:
            return
        self.parent[fy] = fx
        self.rank[fx] += self.rank[fy]
    def get_size(self,x):

        return self.rank[self.find(x)]

class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        m,n = len(grid),len(grid[0])
        size = m * n
        uf = UnionFind(size + 1)
        ans = [0] * len(hits)
        #python的深拷贝
        copyl = copy.deepcopy(grid)
        for hit in hits:
            copyl[hit[0]][hit[1]] =  0
        for i in range(n):
            if copyl[0][i] == 1:
                uf.union(size,i)
        def get_index(x,y):
            return x * n + y
        for i in range(1,m):
            for j in range(n):
                if copyl[i][j] == 1:
                    if copyl[i-1][j] == 1:
                        uf.union(get_index(i,j),get_index(i-1,j))
                    if j > 0 and copyl[i][j-1] == 1:
                        uf.union(get_index(i,j),get_index(i,j-1))
        l = len(hits)
        ans = [0] * l
        def inArea(x,y):
            return x >=0 and y >=0 and x < m and y < n
        directions = [[1,0],[0,1],[-1,0],[0,-1]]
        for i in range(l-1,-1,-1):
            x = hits[i][0]
            y = hits[i][1]
            if grid[x][y] == 0:
                continue
            origin = uf.get_size(size)
            if x == 0:
                uf.union(size,y)
            for direction in directions:
                prex = x + direction[0]
                prey = y + direction[1]
                if inArea(prex,prey) and copyl[prex][prey] == 1:
                    uf.union(get_index(prex,prey),get_index(x,y))
                cur = uf.get_size(size)
                ans[i] = max(0,cur - origin - 1)
                copyl[x][y] = 1
        return ans
