class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for leng in range(1,n + 1):
            for i in range(0,n + 1 - leng):
                j = i + leng - 1
                dp[i][j] = 1 + dp[i + 1][j]
                for k in range(i + 1,j + 1):
                    if s[i] == s[k]:
                        dp[i][j] = min(dp[i][j],dp[i][k - 1] + dp[k + 1][j])
        return dp[0][n - 1] 