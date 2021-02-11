from typing import List
import heapq
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.hp = []
        heapq.heapify(self.hp)
        for i,_ in enumerate(nums):
            self.add(nums[i])

    def add(self, val: int) -> int:
        heapq.heappush(self.hp,val)
        if len(self.hp) > self.k:
            heapq.heappop(self.hp)
        return self.hp[0]
