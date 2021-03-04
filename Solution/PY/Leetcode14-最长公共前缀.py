from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        a = len(strs[0])
        b = len(strs)
        for i in range(a):
            char = strs[0][i]
            for j in range(b):
                if i == len(strs[j]) or char != strs[j][i]:
                    return strs[0][0:i]
        return  strs[0]