package sbgo

func findMaxAverage(nums []int, k int) float64 {
	sum := 0
	maxsum := 0
	for i := 0; i < k; i++ {
		sum += nums[i]
	}
	maxsum = sum
	n := len(nums)
	for i := k; i < n; i++ {
		sum += (nums[i] - nums[i-k])
		maxsum = max(sum, maxsum)
	}
	ans := float64(maxsum) / float64(k)
	return ans
}
