class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        maxn = 0
        nums = [0] * 26
        fast,slow = 0,0
        while fast < n:
            nums[ord(s[fast]) - ord('A')] += 1
            maxn = max(maxn,nums[ord(s[fast]) - ord('A')])
            if fast - slow + 1 -maxn > k:
                nums[ord(s[slow]) - ord('A')] -= 1
                slow += 1
            fast += 1
        return fast - slow