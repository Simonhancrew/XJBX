#  看成一棵树，左右儿子是分割的方法和是否翻转
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        n = len(s1)
        dp = [[[False] * (n + 1) for _ in range(n)] for _ in range(n)]


        for k in range(1,n + 1):
            for i in range(n - k + 1):
                for j in range(n - k + 1):
                    if k == 1:
                        dp[i][j][k] = (s1[i] == s2[j])
                    else:
                        for w in range(1,k):
                            if dp[i][j][w] and dp[i + w][j + w][k - w]:
                                dp[i][j][k] = True     
                                break
                            if dp[i][j + k - w][w] and dp[i + w][j][k - w]:
                                dp[i][j][k] = True
                                break

        return dp[0][0][n]