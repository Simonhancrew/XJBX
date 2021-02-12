from typing import List
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        pre = []
        cur = []
        for i in range(rowIndex + 1):
            cur = [0] * (i + 1)
            cur[0] = cur[i] = 1
            j = 1
            while j < i:
                cur[j] = pre[j] * 1 + pre[j-1] * 1
                j += 1
            pre = cur
        return cur