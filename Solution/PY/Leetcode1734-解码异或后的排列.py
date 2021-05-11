from typing import List
class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        ans = [0] * n
        x = 0
        for i in range(1,n + 1):
            x ^= i
        cur = 0
        for i in range(0,n - 1,2):
            cur ^= encoded[i]
        last = cur ^ x
        ans[n - 1] = last
        for i in range(n-2,-1,-1):
            ans[i] = ans[i+1] ^ encoded[i]
        return ans