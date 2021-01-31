from typing import List
class UnionFind:
    def __init__(self,n):
        self.parent = list(range(n))
        self.rank   = [1 for _ in range(n)]
        self.Area = n
    def find(self,x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self,x,y):
        fx,fy = self.find(x),self.find(y)
        if fx == fy:
            return 
        if self.rank[fx] < self.rank[fy]:
            fx,fy = fy,fx
        self.parent[fy] = fx
        self.rank[fx] += self.rank[fy]
        self.Area -= 1

  
class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        n = len(strs)
        uf = UnionFind(n)
        def check(strs1,strs2):
            num = 0
            ll = len(strs1)
            for i in range(ll):
                if strs1[i] != strs2[i]:
                    num += 1
                if num > 2:
                    return False
            return True
        for i in range(n-1):
            for j in range(i+1,n):
                if strs[i] == strs[j]:
                    uf.union(i,j)
                    break
                if check(strs[i],strs[j]):
                    uf.union(i,j)
        return uf.Area