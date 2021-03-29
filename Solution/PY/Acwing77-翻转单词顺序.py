class Solution(object):
    def reverseWords(self, s):
        s = list(s)
        s.reverse()
        i = 0
        while i < len(s):
            j = i + 1
            while(j < len(s) and s[j] != ' '): j += 1
            start,end = i,j
            while(start < end - 1):
                s[start],s[end - 1] = s[end-1],s[start]
                start += 1
                end -= 1
            i = j
            i += 1
        return "".join(s)