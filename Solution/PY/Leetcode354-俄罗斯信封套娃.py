from typing import List
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        if len(envelopes) == 0 or len(envelopes[0]) == 0:
            return 0
        n = len(envelopes)
        dp = [1] * n
        //必须要大才能放进去
        envelopes.sort(key = lambda x:(x[0],-x[1]))
        for i in range(n):
            for j in range(i):
                if envelopes[j][1] < envelopes[i][1]:
                    dp[i] = max(dp[i],dp[j] + 1)
        
        return max(dp)