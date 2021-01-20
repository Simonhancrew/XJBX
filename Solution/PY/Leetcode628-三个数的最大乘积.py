from typing import List
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        return max(nums[0] * nums[1] * nums[n-1],nums[n-3] * nums[n - 2] * nums[n - 1])

class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        #max1最大
        max1,max2,max3 = -float('inf'),-float('inf'),-float('inf')
        #min1最小
        min1,min2 = float('inf'),float('inf')
        for num in nums:
            if num < min1:
                min2 = min1
                min1 = num
            elif num < min2:
                min2 = num
        
            if num > max1:
                max3 = max2
                max2 = max1
                max1 = num
            elif num > max2:
                max3 = max2
                max2 = num
            elif num > max3:
                max3 = num
        return max(min1 * min2 * max1,max1 * max2 * max3)