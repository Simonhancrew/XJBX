class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        maxjump = min(steps,arrLen)
        mod = int(1e9 + 7)
        dp = [[0] * maxjump for _ in range(steps + 1)]
        dp[0][0] = 1
        for i in range(1,steps + 1):
            for j in range(maxjump):
                dp[i][j] = dp[i - 1][j]
                if j >= 1:
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod
                if j + 1 < maxjump:
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod
        return dp[steps][0]