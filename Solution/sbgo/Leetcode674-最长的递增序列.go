package sbgo

func findLengthOfLCIS(nums []int) int {
	start := 0
	ans := 0
	for i := range nums {
		if i > 0 && nums[i] <= nums[i-1] {
			start = i
		}
		ans = max(ans, i-start+1)
	}
	return ans
}
