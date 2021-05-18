from typing import List
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        presum = [0] * (n + 1)
        for i in range(0,n):
            presum[i + 1] = presum[i] ^ arr[i]
        res = 0
        for i in range(0,n):
            for k in range(i + 1,n):
                if presum[i] == presum[k + 1]:
                    res += k - i
        return res