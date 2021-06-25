from collections import defaultdict
from typing import List
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        start = '0000'
        if start == target:return 0
        lock = set()
        for s in deadends: lock.add(s)
        if start in lock: return -1
        que = [start]
        dist = defaultdict(int)
        dist[start] = 0
        while que:
            t = que.pop(0)
            for i in range(4):
                for j in range(-1,2,2):
                    st = [x for x in t]
                    st[i] = str((ord(st[i]) - ord('0') + j + 10) % 10)
                    st = ''.join(st)
                    if st not in dist and st not in lock:
                        dist[st] = dist[t] + 1
                        if st == target:
                            return dist[st]
                        que.append(st)
        return -1