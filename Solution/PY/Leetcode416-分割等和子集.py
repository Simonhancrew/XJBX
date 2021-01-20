from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 2:
            return False
        maxnum,res = 0,0
        for num in nums:
            res += num
            maxnum = max(maxnum,num)
        target = int(res / 2)

        if res % 2 == 1 or maxnum > target:
            return False
        #list的创建使用[[] * n] * n会所有数组一起改变
        dp = [[False] * (target+1) for _ in range(n)]

        for i in range(n):
            dp[i][0] = True

        dp[0][nums[0]] = True

        for i in range(1,n):
            num = nums[i]
            for j in range(1,target+1):
                if j > num:
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-num]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n-1][target]