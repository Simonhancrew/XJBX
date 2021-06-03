from typing import List
from collections import defaultdict
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        ans,mp,cur = 0,defaultdict(int),0
        n = len(nums)
        cnt = 0
        mp[0] = -1
        for i in range(n):
            cur = 1 if nums[i] == 1 else -1
            cnt += cur
            if cnt in mp:
                ans = max(ans,i - mp[cnt])
            else:
                mp[cnt] = i
        return ans