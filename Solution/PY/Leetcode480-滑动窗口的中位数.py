from typing import List
from bisect import bisect_left
#极度暴力，直接找到应该插入和删除的位置
#然后暴力的删除和插入，暴力的找中间值然后暴力的加入
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        ans = []
        window = []
        n = len(nums)
        for i in range(n):
            id = bisect_left(window,nums[i])
            window.insert(id,nums[i])
            
            if len(window) > k:
                idx = bisect_left(window,nums[i - k])
                del window[idx]

            if len(window) == k:
                median = (window[k // 2] + window[(k - 1) // 2]) / 2
                ans.append(median)

        return ans