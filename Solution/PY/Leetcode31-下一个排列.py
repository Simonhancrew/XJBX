from typing import List
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        #如何不越界的找到山峰
        i = len(nums) - 2
        while(i >= 0 and nums[i] >= nums[i+1]):
            i -= 1
        #可能i没有合适的值
        if(i >= 0):
            k = len(nums) - 1
            while(k >= i+1 and nums[k] <= nums[i]):
                k-=1
            nums[i],nums[k] = nums[k],nums[i]
        left = i+1
        right = len(nums) - 1
        #一个swap
        while left <= right:
            nums[left] ,nums[right] = nums[right],nums[left]
            left += 1
            right -= 1 
