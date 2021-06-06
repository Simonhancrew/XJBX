#本质上，这还是一个01背包
#只不过背包的重量是在两个维度上
#然后背包问题的优化滚动数组，注意是按照背包重量的逆序去遍历的(保证不重用每一个物品)

from typing import List
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        #注意不要创建引用
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for string in strs:
            #针对当前的字符串，找一下他的01数量
            num1, num0 = 0, 0
            for chr in string:
                if chr == '0':
                    num0 += 1
                else:
                    num1 += 1
            #2维度的背包，记录每一个重量可以承载的物品
            #逆序遍历防止重复
            for i in range(m, num0 - 1, -1):
                for j in range(n, num1 - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1)

        return dp[m][n]

# 去点idx的维度优化
# class Solution:
#     def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
#         dp = [[0] * (n + 1) for _ in range(m + 1)]
#         for s in strs:
#             cn,cm = 0,0
#             for ch in s:
#                 if ch == '0':
#                     cm +=1
#                 else:
#                     cn += 1
#             for i in range(m,cm-1,-1):
#                 for j in range(n,cn - 1,-1):
#                     dp[i][j] = max(dp[i][j],dp[i - cm][j - cn] + 1)
#         return dp[m][n]