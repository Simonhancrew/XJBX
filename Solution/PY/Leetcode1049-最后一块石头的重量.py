from typing import List
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:  
        res = 0
        n = len(stones)
        for stone in stones:
            res += stone
        target = int(res / 2)
        dp = [0] * (target+1)
        for i in range(n):
            #注意逆序
            for j in range(target,stones[i] - 1,-1):
                dp[j] = max(dp[j],dp[j - stones[i]] + stones[i])
        return res - 2 * dp[target]