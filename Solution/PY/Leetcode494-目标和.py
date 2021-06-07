from typing import List
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        Sum = sum(nums)
        if Sum < target or (Sum + target) & 1 == 1:
            return 0
        pos = (Sum + target) >> 1
        dp = [0] *(pos + 1)
        dp[0] = 1
        for i in range(len(nums)):
            for j in range(pos,nums[i] - 1,-1):
                dp[j] += dp[j - nums[i]]
        return dp[pos]

# class Solution:
#     def __init__(self):
#         self.cnt = 0
#     def findTargetSumWays(self, nums: List[int], target: int) -> int:
#         def dfs(nums,target,sum,idx):
#             if idx == len(nums):
#                 if sum == target:
#                     self.cnt += 1
#             else:
#                 dfs(nums,target,sum + nums[idx],idx + 1)
#                 dfs(nums,target,sum - nums[idx],idx + 1)
#         dfs(nums,target,0,0)
#         return self.cnt