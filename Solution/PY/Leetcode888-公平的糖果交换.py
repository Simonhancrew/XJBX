from typing import List
import collections
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        suma = 0
        sumb = 0
        mp = collections.defaultdict(int)
        for a in A:
            suma += a
            mp[a] += 1
        for b in B:
            sumb += b
        want = (suma - sumb) // 2
        for b in B:
            if mp[want + b] > 0:
                return [want + b,b]
        return []
