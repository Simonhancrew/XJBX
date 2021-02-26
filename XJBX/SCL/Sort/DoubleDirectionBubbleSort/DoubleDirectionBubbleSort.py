from typing import List

def DoubleDirectionSort(nums:List):
    if len(nums) < 2:
        return
    flag = False
    left,right = 0,len(nums) - 1
    while left < right:
        flag = False
        for i in range(left,right):
            if nums[i] > nums[i+1]:
                nums[i],nums[i+1] = nums[i+1],nums[i]
                flag = True
        right -= 1
        for i in range(right,left,-1):
            if nums[i-1] > nums[i]:
                nums[i-1],nums[i] = nums[i],nums[i-1]
                flag = True
        left += 1
        if flag == False:
            return


if __name__ == "__main__":
    input = [3,2,1,2,4,56,7,4,2,332]
    DoubleDirectionSort(input)
    print(input)