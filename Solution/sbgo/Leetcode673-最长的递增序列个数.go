package sbgo

func findNumberOfLIS(nums []int) int {
	n := len(nums)
	if n <= 1 {
		return n
	}
	dp, count := make([]int, n), make([]int, n)
	for i := range dp {
		dp[i] = 1
		count[i] = 1
	}
	maxcount := 0
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				if dp[j]+1 > dp[i] {
					dp[i] = dp[j] + 1
					count[i] = count[j]
				} else if dp[j]+1 == dp[i] {
					count[i] += count[j]
				}
			}
			maxcount = max(maxcount, dp[i])
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		if dp[i] == maxcount {
			ans += count[i]
		}
	}
	return ans
}
