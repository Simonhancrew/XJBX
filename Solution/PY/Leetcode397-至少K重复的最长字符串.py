from collections import Counter
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        n = len(s)
        ret = 0
        c = Counter(s)
        end = len(c)
        for i in range(end+1):
            l = r = 0
            total = 0
            less = 0
            cnt = [0] * 26
            while r < n:
                cnt[ord(s[r]) - ord('a')] += 1
                if cnt[ord(s[r]) - ord('a')] == 1:
                    less += 1
                    total += 1
                if cnt[ord(s[r]) - ord('a')] == k:
                    less -= 1

                while total > i:
                    cnt[ord(s[l]) - ord('a')] -= 1
                    if cnt[ord(s[l]) - ord('a')] == k - 1:
                        less += 1
                    if cnt[ord(s[l]) - ord('a')] == 0:
                        less -= 1
                        total -= 1
                    l += 1
                if less == 0:
                    ret = max(ret,r - l + 1)
                r += 1
        return  ret



def longestSubstring(s:str,k:int)->int:
    n = len(s)
    def dfs(s:str,l,r,k):
        cnt = [0] *26
        for i in range(l,r + 1):
            cnt[ord(s[i]) - ord('a')] += 1
        split = 0
        for i in range(26):
            if cnt[i] > 0 and cnt[i] < k:
                split = i + ord('a')
                break
        if split == 0:
            return r - l + 1
        i = l
        ret = 0
        while i <= r:
            while i<= r and split == ord(s[i]):
                i += 1
            start = i
            while i <= r and split != ord(s[i]):
                i += 1
            length = dfs(s,start,i-1,k)
            ret = max(ret,length)
        return ret

    return dfs(s,0,n-1,k)