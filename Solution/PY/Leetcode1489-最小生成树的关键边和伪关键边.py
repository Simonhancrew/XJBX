from typing import List
class UnionFind:
    def __init__(self,n:int):
        self.parent = list(range(n))
        self.size = [1]*n
        self.Area = n
    def find(self,x:int)->int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self,x:int,y:int)->bool:
        fx ,fy = self.find(x),self.find(y)
        if fx == fy:
            return False
        if self.size[fx] < self.size[fy]:
            fx,fy = fy,fx
        self.parent[fy] = fx
        self.size[fx] += self.size[fy]
        self.Area -= 1
        return True
class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        m = len(edges)
        for i in range(m):
            edges[i].append(i)
        edges.sort(key = lambda x : x[2])

        uf = UnionFind(n)
        val = 0
        for i in range(m):
            if uf.union(edges[i][0],edges[i][1]):
                val += edges[i][2]
        
        ans = [list(),list()]
        
        for i in range(m):
            uf_cur = UnionFind(n)
            vla_cur = 0
            for j in range(m):
                if i != j and uf_cur.union(edges[j][0],edges[j][1]):
                    vla_cur += edges[j][2]

            if  uf_cur.Area != 1 or (uf_cur.Area == 1 and vla_cur > val):
                ans[0].append(edges[i][3])
                continue
            
            uf_cur = UnionFind(n)
            uf_cur.union(edges[i][0],edges[i][1])
            vla_cur = edges[i][2]
            for j in range(m):
                if i != j and  uf_cur.union(edges[j][0],edges[j][1]):
                    vla_cur += edges[j][2]
            
            if val == vla_cur:
                ans[1].append(edges[i][3])

        return ans 