from typing import List
class Solution:
    def __init__(self):
        self.jobs = []
        self.k = 0
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        self.jobs = jobs
        self.k = k
        l,r = max(jobs),sum(jobs)
        def check(mid):
            workloads = [0] * self.k
            return back(workloads,mid,0)
        def back(workloads,limit,idx):
            if idx == len(self.jobs):
                return True
            cur = self.jobs[idx]
            for i,_ in enumerate(workloads):
                if workloads[i] + cur <= limit:
                    workloads[i] += cur
                    if back(workloads, limit, idx + 1):
                        return True
                    workloads[i] -= cur
                if workloads[i] == 0 or workloads[i] + cur == limit:
                    break
            return False
        while l < r:
            mid = l + r >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l