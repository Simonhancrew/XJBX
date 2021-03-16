from typing import List

#循环不变，找到开启坐标，然后这种的循环圈数就是n / 2
#如果有奇数的话中心还要另外处理
#选择好自己的开闭区间，然后offset是每次都要更新的（扣好边界）
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        startx,starty,loop,offset = 0,0,n//2,1
        count = 1
        res = [[0] * n for _ in range(n)]
        for i in range(loop):
            i,j = startx,starty
            while j < starty + n - offset:
                res[i][j] = count
                count += 1
                j += 1
            while i < startx + n - offset:
                res[i][j] = count 
                count += 1
                i += 1
            while j > starty:
                res[i][j] = count
                count += 1
                j -= 1
            while i > startx:
                res[i][j] = count
                count += 1
                i -= 1
            startx += 1
            starty += 1
            offset += 2
        mid = n // 2
        if n % 2 != 0:
            res[mid][mid] = count   
        return res