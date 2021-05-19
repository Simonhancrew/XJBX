from typing import List
class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        n,m = len(matrix),len(matrix[0])
        res = []
        for i in range(n):
            for j in range(m):
                if i >= 1:
                    matrix[i][j] ^= matrix[i - 1][j]
                if j >= 1:
                    matrix[i][j] ^= matrix[i][j - 1]
                if j >= 1 and i >= 1:
                    matrix[i][j] ^= matrix[i - 1][j - 1]
                res.append(matrix[i][j])
        res.sort(reverse=True)
        return res[k - 1]