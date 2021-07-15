from typing import List

class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        n = len(arr)
        arr.sort()
        arr[0] = 1
        for i in range(1,n):
            arr[i] = min(arr[i],arr[i - 1] + 1)
        return arr[-1]