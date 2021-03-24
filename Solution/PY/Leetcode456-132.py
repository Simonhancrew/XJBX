from typing import List

class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        stk = list()
        mini = [0] * n
        mini[0] = nums[0]
        for i in range(1,n):
            mini[i] = min(mini[i- 1],nums[i])  
        #枚举3，右边是一个单调栈
        for i in range(n-1,-1,-1):
            while len(stk) > 0 and stk[-1] <= mini[i]:
                stk.pop()
            if len(stk) > 0 and stk[-1] < nums[i]:
                return True
            stk.append(nums[i])
        return False