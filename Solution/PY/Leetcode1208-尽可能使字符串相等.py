class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        ans = 0
        cost = 0
        start = end = 0
        length = len(s)
        while end < length:
            cost += abs(ord(s[end]) - ord(t[end]))
            while cost > maxCost:
                cost -= abs(ord(s[start]) - ord(t[start]))
                start += 1
            ans = max(ans,end - start + 1)
            end += 1
        return ans