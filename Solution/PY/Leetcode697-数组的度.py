from typing import List
from collections import defaultdict
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        mp = defaultdict(list)
        for i,num in enumerate(nums):
            if num in mp:
                mp[num][0] += 1
                mp[num][2] = i
            else:
                mp[num] = [1,i,i]
        ans = 0 
        maxnums = 0
        for time,start,end in mp.values():
            if maxnums < time:
                maxnums = time
                ans = end - start + 1
            elif maxnums == time:
                #海象运算符号，避免两次运算
                if ans > (tmp := end - start + 1):
                    ans = tmp
        return ans