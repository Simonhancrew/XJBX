from typing import List
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        path = []
        res = []


        def ispa(s,l,r):
            while l < r:
                if s[l] == s[r]:
                    l += 1
                    r -= 1
                else:
                    return False
            return True


        def dfs(s,start):
            if start >= len(s):
                res.append(path[:])
            for i in range(start,len(s)):
                if ispa(s,start,i):
                    strs = s[start:i + 1]
                    path.append(strs)
                else:
                    continue
                dfs(s,i+1)
                path.pop()

        dfs(s,0)
        return res