from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        path,res= [],[]
        used = [0] * n
        nums.sort()
        def dfs(index):
            # 注意深拷贝
            res.append(path[:])
            for i in range(index,len(nums)):
                if i > 0 and nums[i - 1] == nums[i] and used[i - 1] == 0:
                    continue
                path.append(nums[i])
                used[i] =  1
                dfs(i + 1)
                used[i] = 0
                path.pop()

        dfs(0)

        return res