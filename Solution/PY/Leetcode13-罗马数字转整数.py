class Solution:
    kv = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }
    def romanToInt(self, s: str) -> int:
        n = len(s)
        res = Solution.kv[s[n - 1]]
        for i in range(n - 2,-1,-1):
            cur = Solution.kv[s[i]]
            right = Solution.kv[s[i + 1]]
            if right <= cur:
                res += cur
            else:
                res -= cur
        return res