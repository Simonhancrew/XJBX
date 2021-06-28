from typing import List
from collections import defaultdict
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target: return 0
        n = len(routes)
        dist = [int(1e8)] * n
        g = defaultdict(list)
        que = []
        for i in range(n):
            for j in routes[i]:
                if j == source:
                    dist[i] = 1
                    que.append(i)
                g[j].append(i)
        
        while que:
            t = que.pop(0)
            for x in routes[t]:
                if target == x:
                    return dist[t]
                for y in g[x]:
                    if dist[y] > dist[t] + 1:
                        dist[y] = dist[t] + 1
                        que.append(y)
                g.pop(x)
        return -1