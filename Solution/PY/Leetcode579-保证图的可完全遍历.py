from typing import List

class UnionFind:
    def __init__(self,n:int):
        self.parent = list(range(n))
        self.rank = [1 for _ in range(n)]
        self.Area = n
    def find(self,x:int)->int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self,x,y)->bool:
        fx,fy = self.find(x),self.find(y)
        if fx == fy:
            return False
        if self.rank[fx] < self.rank[fy]:
            fx,fy = fy,fx
        self.parent[fy] = fx
        self.rank[fx] += self.rank[fy]
        self.Area -= 1
        return True

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        ans = 0
        ufa,ufb = UnionFind(n),UnionFind(n)
        #连接公共边,全部连完是必要的
        for edge in edges:
            edge[1] -= 1
            edge[2] -= 1
            if edge[0] == 3:
                if ufa.union(edge[1],edge[2]) == False:
                    ans+=1
                else:
                    ufb.union(edge[1],edge[2])
        
        for edge in edges:
            if edge[0] == 1:
                if ufa.union(edge[1],edge[2]) == False:
                    ans += 1
            if edge[0] == 2:
                if ufb.union(edge[1],edge[2]) == False:
                    ans += 1 
    
        if ufa.Area != 1 or ufb.Area != 1:
            return -1
        return ans