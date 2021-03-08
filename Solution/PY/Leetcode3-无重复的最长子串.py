from collections import defaultdict

#双指针 + 哈希记录字符出现的次数
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        dic  = defaultdict(int)
        j = 0
        res = 1
        for i in range(n):
            dic[ord(s[i])] += 1
            while dic[ord(s[i])] > 1:
                dic[ord(s[j])] -= 1
                j += 1
            res = max(res,i - j + 1)
        return res