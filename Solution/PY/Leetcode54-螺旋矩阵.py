from typing import List
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m,n = len(matrix),len(matrix[0])
        x1,y1,x2,y2 = 0,0,m-1,n-1
    
        res = []
        while x1 <= x2 and y1 <= y2:
            for i in range(y1,y2+1):
                res.append(matrix[x1][i])
            for i in range(x1+1,x2+1):
                res.append(matrix[i][y2])
            
            if x1 < x2 and y1 < y2:
                for i in range(y2 -1,y1,-1):
                    res.append(matrix[x2][i])
                for i in range(x2,x1,-1):
                    res.append(matrix[i][y1])
            x1 += 1
            y1 += 1
            x2 -= 1
            y2 -=1
        return res