from typing import List
class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        n = len(encoded)
        res = [0] * (n + 1)
        res[0] = first
        for i in range(1,n + 1):
            res[i] = encoded[i - 1] ^ res[i - 1]
        return res