from typing import List
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        n = len(A)
        inc,dec = True,True
        for i in range(n-1):
            if A[i] > A[i + 1]:
                inc = False
            if A[i] < A[i + 1]:
                dec = False
        return dec or inc