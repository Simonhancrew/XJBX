from typing import List
#避免两次循环的话就直接开两倍的数组大小循环求模就行
#之后从后往前遍历，开一个单调栈，单调递减
#存的就是从后往前的大数，在往前便利的时候能栈不空的时候能找到就返回
#反之就返回-1
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [-1] * n
        s = []
        for i in range(2*n-1,-1,-1):
            while s and nums[i % n] >= s[-1]:
                s.pop()
            if len(s) > 0:
                res[i % n] = s[-1]
            else:
                res[i % n] = -1
            s.append(nums[i % n])
        return res