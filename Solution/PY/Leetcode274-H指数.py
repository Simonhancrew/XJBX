class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        n = len(citations)
        res = 0
        for i in range(n,0,-1):
            if citations[n - i] >= i:
                res = i
                break

        return res