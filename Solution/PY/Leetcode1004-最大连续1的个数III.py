from typing import List
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        start,zeros,ans = 0,0,0
        n = len(A)
        for end in range(n):
            if A[end] == 0:
                zeros += 1
            while zeros > K:
                if A[start] == 0:
                    zeros -= 1
                start += 1
            ans = max(ans,end - start + 1)
        return ans