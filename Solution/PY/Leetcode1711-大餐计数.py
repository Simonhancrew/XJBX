from typing import List
from collections import defaultdict

class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        res = 0
        MOD = int(1e9 + 7)
        mp = defaultdict(int)
        m = max(deliciousness) * 2
        for d in deliciousness:
            i = 1
            while i <= m:
                pair = mp[i - d]
                res = (pair + res) % MOD
                i <<= 1
            mp[d] += 1
        return res