from typing import List
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        parent = list(range(n))
        def find(x):
            if parent[x] == x:
                return x
            parent[x] = find(parent[x])
            return parent[x]
        def union(x,y)->bool:
            fx = find(x)
            fy = find(y)
            if fx == fy:
                return False
            parent[fy] = fx
            return True
        
        def manhattan(x,y)->int:
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1])
        #创建空list
        edges = list()

        for i in range(n):
            for j in range(i + 1,n):
                edges.append((manhattan(i,j),i,j))
        #py的sort
        edges.sort()
        ans , num = 0,1
        for arg1,arg2,arg3 in edges:
            if union(arg2,arg3):
                ans += arg1
                num += 1
                if num == n:
                    break
        return ans