package main

import "fmt"

func bubbleSort(nums []int) {
	if len(nums) < 1 {
		return
	}
	n := len(nums)
	var flag bool
	for end := n - 1; end > 0; end-- {
		flag = false
		for i := 0; i < end; i++ {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
				flag = true
			}
		}
		if !flag {
			break
		}
	}
	return
}

func main() {
	input := []int{3, 2, 1, 2, 4, 56, 7, 4, 2, 332}
	bubbleSort(input)
	fmt.Println(input)
}
