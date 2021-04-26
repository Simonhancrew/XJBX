from typing import List
class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        l = max(weights)
        r = sum(weights)
        def possible(load):
            cur,res = 0,0
            for i in range(len(weights)):
                if cur != 0 and cur + weights[i] <= load:
                    cur += weights[i]
                else:
                    cur = weights[i]
                    res += 1
            if res <= D:
                return True
            return False
        while l < r:
            mid = (l + r) // 2
            if possible(mid):
                r = mid
            else:
                l = mid + 1
        return l 