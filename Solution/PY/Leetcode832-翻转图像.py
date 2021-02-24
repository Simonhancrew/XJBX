from typing import List
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        m ,n = len(A),len(A[0])
        for i in range(m):
            start,end = 0,n - 1
            while start < end:
                if A[i][start] == A[i][end]:
                    A[i][start] ^= 1
                    A[i][end] ^= 1
                start += 1
                end -= 1
            if start == end:
                A[i][start] ^= 1
        return A