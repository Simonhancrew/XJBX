from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        i,ans = 0,0
        while i < len(costs) and coins >= costs[i]:
            coins -= costs[i]
            i += 1
            ans += 1
        return ans