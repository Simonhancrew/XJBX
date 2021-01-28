package sbgo

func pivotIndex(nums []int) int {
	n := len(nums)
	if n <= 2 {
		return -1
	}
	totalSum := 0
	for _, val := range nums {
		totalSum += val
	}
	sum := 0
	for i := range nums {
		// tmp := sum
		if sum == totalSum-sum-nums[i] {
			return i
		}
		sum += nums[i]
	}
	return -1
}
