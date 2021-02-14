from typing import List
from collections import defaultdict
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        n = len(row)
        node = n // 2
        parent = list(range(node))

        def find(x: int) -> int:
            if parent[x] == x:
                return x
            else:
                parent[x] = find(parent[x])
                return parent[x]

        def union(x, y):
            fx, fy = find(x), find(y)
            parent[fy] = fx

        for i in range(0, n, 2):
            lhs = row[i] // 2
            rhs = row[i + 1] // 2
            union(lhs, rhs)

        mp = defaultdict(int)

        for i in range(node):
            fi = find(i)
            mp[fi] += 1
        ret = 0
        for _, v in mp.items():
            ret += v - 1

        return ret