
from typing import List

class Solution:
    def __init__(self):
        self.ans = []
        self.cur = []
        self.st = list()
    def permutation(self, s: str) -> List[str]:
        n = len(s)
        self.st = [0] * n
        s = sorted(s)
        def dfs(s,idx):
            if idx == len(s):
                self.ans.append(''.join(self.cur))
                return
            for i in range(len(s)):
                if not self.st[i]:
                    if i > 0 and s[i - 1] == s[i] and self.st[i - 1] == False:
                        continue
                    self.st[i] = True
                    self.cur.append(s[i])
                    dfs(s,idx + 1)
                    self.st[i] = False
                    self.cur.pop()
        dfs(s,0)
        return self.ans