from typing import List
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        windowsize = n - k
        s = sum(cardPoints[:windowsize])
        minsum = s
        for i in range(windowsize,n):
            s += (cardPoints[i] - cardPoints[i - windowsize])
            minsum = min(minsum,s)
        return sum(cardPoints) - minsum
        