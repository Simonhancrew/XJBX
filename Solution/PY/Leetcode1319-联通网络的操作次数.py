from typing import List
class UnionFind:
    def __init__(self,n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.Area = n
    def find(self,x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self,x,y):
        fx , fy = self.find(x),self.find(y)
        if fx == fy:
            return 
        if self.size[fx] < self.size[fy]:
            fx,fy = fy,fx
        self.Area -= 1
        self.parent[fy] = self.parent[fx]
        self.size[fx] += self.size[fy]
    
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        uf = UnionFind(n)
        if len(connections) < n - 1:
            return -1
        for conn in connections:
            uf.union(conn[1],conn[0])

        return uf.Area - 1