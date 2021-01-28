package sbgo

func removeDuplicates(nums []int) int {
	ptr, count := 1, 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			count++
		} else {
			count = 1
		}

		if count <= 2 {
			nums[ptr] = nums[i]
			ptr++
		}
	}
	return ptr
}
