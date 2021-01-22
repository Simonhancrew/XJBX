from typing import List
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        res = list()
        n = len(A)
        for i in range(n-1,-1,-1):
            sum = A[i] + K % 10
            #地板除
            K = K // 10
            if sum >= 10:
                sum = sum - 10
                #把carry位放到所有数K里
                K = K + 1
            res.append(sum)
        while K > 0:
            res.append(K % 10)
            K = K // 10
        res.reverse()
        return res