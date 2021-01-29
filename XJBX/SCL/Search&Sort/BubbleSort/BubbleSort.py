from typing import List
def bubble_sort(nums:List):
    if len(nums) < 1:
        return 
    n = len(nums)
    flag = False
    for end in range(n - 1,0,-1):
        flag = False
        for i in range(0,end):
            if nums[i] > nums[i+1]:
                nums[i],nums[i+1] = nums[i+1],nums[i]
                flag = True
        if flag == False:
            break
    return 

if __name__ == "__main__":
    input = [3,2,1,2,4,56,7,4,2,332]
    bubble_sort(input)
    print(input)