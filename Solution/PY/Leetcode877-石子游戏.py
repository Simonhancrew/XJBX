from typing import List

class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0] * n for _ in range(n)]
        for length in range(1,n + 1):
            for i in range(0,n - length + 1):
                j = i + length - 1
                if i == j:
                    dp[i][j] = piles[i]
                else:
                    dp[i][j] = max(piles[i] - dp[i + 1][j],piles[j] - dp[i][j - 1])
        return dp[0][n - 1] > 0