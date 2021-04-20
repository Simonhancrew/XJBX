class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m,n = len(haystack),len(needle)
        if n == 0:
            return 0
        i,j = 0,0
        while i < m and j < n:
            if haystack[i] == needle[j]:
                j += 1
            else:
                i -= j
                j = 0
            i += 1
        if j < n:
            return -1
        return i - n