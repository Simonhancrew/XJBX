from typing import List

class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        MINI = int(-1e9 + 10)
        dp = [MINI] *(target + 1)
        dp[0] = 0
        for i in range(9):
            for j in range(cost[i],target + 1):
                dp[j] = max(dp[j],dp[j - cost[i]] + 1)

        if dp[target] < 0:
            return '0'
        ans = list()
        j = target
        for i in range(8,-1,-1):
            while j >= cost[i] and dp[j] == dp[j - cost[i]] + 1:
                ans.append(i + 1)
                j -= cost[i]
        return ''.join(ans) 