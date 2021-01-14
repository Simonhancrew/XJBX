from typing import List
#3.5之后引入类型限定var:type,返回值->type
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        n = len(A)
        res = [0 for x in range(0,n)]
        cur = 0
        for i in range(n):
            cur = cur <<1
            if(cur >= 10):
                cur -= 10
            cur += A[i]
            if cur % 5 == 0:
                res[i] = True   
        return res