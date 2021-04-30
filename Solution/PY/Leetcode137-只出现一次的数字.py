class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ct = collections.Counter(nums)
        ans = 0
        for k,v in ct.items():
            if v == 1:
                ans = k
                break
        return ans 