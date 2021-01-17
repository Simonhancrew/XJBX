from typing import List
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        offset_x = coordinates[0][0]
        offset_y = coordinates[0][1]
        n = len(coordinates)
        for i in range(n):
            coordinates[i][0] -= offset_x
            coordinates[i][1] -= offset_y
        
        A,B = coordinates[1][1],-coordinates[1][0]
        for i in range(2,n):
            if A * coordinates[i][0] + B * coordinates[i][1] != 0:
                return False
        return True