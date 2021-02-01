package main

import "fmt"

func doubleDirectionBubbleSort(nums []int) {
	if len(nums) < 2 {
		return
	}
	flag := false
	left, right := 0, len(nums)-1
	for left < right {
		flag = false
		for i := left; i < right; i++ {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
				flag = true
			}
		}
		right--
		for i := right; i > left; i-- {
			if nums[i] < nums[i-1] {
				nums[i], nums[i-1] = nums[i-1], nums[i]
				flag = true
			}
		}
		left++
		if !flag {
			return
		}
	}
}

func main() {
	input := []int{3, 2, 1, 2, 4, 56, 7, 4, 2, 332}
	doubleDirectionBubbleSort(input)
	fmt.Println(input)
}
