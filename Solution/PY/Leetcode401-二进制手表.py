from typing import List
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []
        for i in range((1 << 10)):
            s = 0
            for j in range(10):
                if (i >> j) & 1:
                    s += 1
            if s == turnedOn:
                h = i >> 6
                m = i & 63
                if h < 12 and m < 60:
                    ans.append("{:d}:{:02d}".format(h,m))
        return ans