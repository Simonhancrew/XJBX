class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        N = 1 << 10
        INT_MAX = int(2 << 10)
        dp = [[INT_MAX] * N for _ in range(k)]
        g = [INT_MAX] * k
        n = len(nums)
        for i in range(k):
            mp = defaultdict(int)
            cnt = 0
            for j in range(i,n,k):
                cnt += 1
                mp[nums[j]] += 1
            if i == 0:
                for mask in range(0,N):
                    dp[0][mask] = min(dp[0][mask],cnt - mp[mask])
                    g[0] = min(g[0],dp[0][mask])
            else:
                for mask in range(0,N):
                    dp[i][mask] = g[i - 1] + cnt
                    for x,countx in mp.items():
                        dp[i][mask] = min(dp[i][mask],dp[i - 1][mask ^ x] + cnt - countx)
                    g[i] = min(g[i],dp[i][mask])
        return dp[k - 1][0]