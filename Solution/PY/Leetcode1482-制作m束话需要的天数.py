from typing import List
class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        l = min(bloomDay)
        r = max(bloomDay)
        if m * k > len(bloomDay):
            return -1
        def check(day):
            flowers,bqt = 0,0
            for _,bloom in enumerate(bloomDay):
                if bloom <= day:
                    flowers += 1
                    if flowers == k:
                        bqt += 1
                        if bqt == m:
                            break
                        flowers = 0
                else:
                    flowers = 0
            return bqt == m
        while l < r:
            mid = l + r >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        if not check(l):
            l = -1
        return l