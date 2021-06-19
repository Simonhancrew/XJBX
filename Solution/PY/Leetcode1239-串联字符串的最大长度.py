from typing import List
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        n,ans = len(arr),0
        for i in range(1 << n):
            st = [0] * 26
            flag = False
            for j in range(n):
                if (i >> j) & 1:
                    for ch in arr[j]:
                        st[ord(ch) - ord('a')] += 1
                        if st[ord(ch) - ord('a')] > 1:
                            flag = True
                            break
                if flag:break
            if not flag:ans = max(ans,sum(st))
        return ans