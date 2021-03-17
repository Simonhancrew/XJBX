class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m ,n = len(s),len(t)
        dp = [[0] * (n+ 1) for _ in range(m+1)]
        #t中的字符一定要在s中出现，所以我们分情况来考虑
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 and j != 0:
                    #用空串去匹配非空串，当然匹配不出来
                    dp[i][j] = 0
                    continue
                if j == 0:
                    # 去匹配一个空串，任何串都可以匹配，我们约定这个时候
                    dp[i][j] = 1
                    continue
                #最后有两种情况，第一种就是前i-1个字符已经把t给匹配完了
                dp[i][j] = dp[i - 1][j]
                if s[i - 1] == t[j - 1]:
                    #此时最后一个字符相等的，可以考虑另外一种情况
                    #前i - 1只匹配了前j -  1
                    dp[i][j] += dp[i - 1][j - 1]
        return dp[m][n]



# 下面优化了第一维度
# class Solution:
#     def numDistinct(self, s: str, t: str) -> int:
#         m ,n = len(s),len(t)
#         dp = [[0] * (n+ 1) for _ in range(2)]
#         #t中的字符一定要在s中出现，所以我们分情况来考虑
#         old,now = 0,0
#         for i in range(m + 1):
#             old = now
#             now = 1 - now
#             for j in range(n + 1):
#                 if i == 0 and j != 0:
#                     #用空串去匹配非空串，当然匹配不出来
#                     dp[now][j] = 0
#                     continue
#                 if j == 0:
#                     # 去匹配一个空串，任何串都可以匹配，我们约定这个时候
#                     dp[now][j] = 1
#                     continue
#                 #最后有两种情况，第一种就是前i-1个字符已经把t给匹配完了
#                 dp[now][j] = dp[old][j]
#                 if s[i - 1] == t[j - 1]:
#                     #此时最后一个字符相等的，可以考虑另外一种情况
#                     #前i - 1只匹配了前j -  1
#                     dp[now][j] += dp[old][j - 1]
#         return dp[now][n]