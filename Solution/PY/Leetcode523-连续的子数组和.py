from typing import DefaultDict, List
from collections import defaultdict
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n < 2:
            return False
        re = 0
        mp = defaultdict(int)
        mp[0] = -1
        for i in range(n):
            re = (re + nums[i]) % k
            if re in mp:
                if i - mp[re] >= 2:
                    return True
            else:
                mp[re] = i
        return False