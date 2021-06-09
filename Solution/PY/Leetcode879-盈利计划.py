from typing import List

class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        dp = [[0] * (minProfit + 1) for _ in range(n + 1)]
        MOD = int(1e9 + 7)
        for i in range(n + 1):
            dp[i][0] = 1
        for i in range(len(group)):
            g,p = group[i],profit[i]
            for j in range(n,g - 1,-1):
                for k in range(minProfit,-1,-1):
                    dp[j][k] = (dp[j][k] + dp[j - g][max(0,k - p)]) % MOD
        return dp[n][minProfit]