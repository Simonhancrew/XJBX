#先考虑最后一步，假设我找到了最后的一个[l,end]的区间回文，最后判断当前的最小回文子串就是
#之前[0,l-1]的子串个数 + 1(最后一个回文子串) 与 不考虑最后一个分割的总数
#dp上的体现就是 dp[j] + 1 和 dp[i]
#在从前往后思考，看看能不能形成递推
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        #构建一下回文串数组
        #判断[l,r]是不是回文
        judge = [[False] * n for _  in range(n)]
        for i in range(n):
            l,r = i,i
            while l >= 0 and r < n and s[l] == s[r]:
                judge[l][r] = True
                l -= 1
                r += 1
            l,r = i,i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                judge[l][r] = True
                l -= 1
                r += 1
        abig = 1 << 20
        dp = [abig] *(n + 1)
        dp[0] = 0
        for i in range(1,n+1):
            for j in range(i):
                if judge[j][i-1]:
                    dp[i] = min(dp[j] + 1,dp[i])

        return dp[n] - 1