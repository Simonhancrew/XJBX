package sbgo

func findMaxConsecutiveOnes(nums []int) int {
	count, maxcount := 0, 0
	for _, num := range nums {
		if num == 1 {
			count++
		} else {
			maxcount = max(maxcount, count)
			count = 0
		}
	}
	maxcount = max(maxcount, count)
	return maxcount
}
