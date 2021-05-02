from typing import List
from collections import defaultdict
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        hash = defaultdict(int)
        for line in wall:
            s = 0
            for i in range(0,len(line) - 1):
                s += line[i]
                hash[s] += 1

        res = 0
        for _,v in hash.items():
            res = max(res,v)

        return len(wall) - res