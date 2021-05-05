class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        maxV= nums[0]
        for num in nums:
            maxV = max(num,maxV)
        Sum = [0] * (maxV + 1)
        for num in nums:
            Sum[num] += num
        old,now = Sum[0],Sum[1]
        n = len(Sum)
        for i in range(3,n + 1):
            tmp = max(old + Sum[i - 1],now)
            old = now
            now = tmp
        return now