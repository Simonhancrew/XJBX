from collections import defaultdict
class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.htime = defaultdict(list)
        self.hvalue = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.htime[key].append(timestamp)
        self.hvalue[key].append(value)

    def get(self, key: str, timestamp: int) -> str:
        if not self.htime[key]:
            return ""
        if timestamp < self.htime[key][0]:
            return ""
        if timestamp >= self.htime[key][-1]:
            return self.hvalue[key][-1]
        l,r = 0,len(self.htime[key]) - 1
        while l < r:
            mid = (l + r + 1) // 2
            if self.htime[key][mid] <= timestamp:
                l = mid
            else:
                r = mid - 1
        return self.hvalue[key][l] 