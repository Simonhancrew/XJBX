class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        s = ' ' + s
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1,n+1):
            if s[i] >= '1' and s[i] <= '9':
                dp[i] += dp[i -1]
            if i > 1:
                t =(ord(s[i - 1]) - ord('0')) * 10 + ord(s[i]) - ord('0')
                if t >= 10 and t <= 26:
                    dp[i] += dp[i - 2]
        return dp[n]