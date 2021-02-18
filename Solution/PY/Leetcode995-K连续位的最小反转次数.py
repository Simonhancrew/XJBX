from typing import List
class Solution:
    def minKBitFlips(self, A: List[int], K: int) -> int:
        n = len(A)
        ans = cnt = 0
        dif = [0] * (n + 1)
        for i in range(n):
            cnt += dif[i]
            if (A[i] + cnt) % 2 == 0:
                if i + K > n:
                    return -1
                ans += 1
                cnt += 1
                dif[i + K] -= 1
        return ans