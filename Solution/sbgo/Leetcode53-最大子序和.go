package sbgo

func maxSubArray(nums []int) int {
	ans, n := nums[0], len(nums)
	dp := make([]int, 2)
	dp[0] = nums[0]
	old, now := 0, 0
	for i := 1; i < n; i++ {
		old = now
		now = 1 - now
		dp[now] = max(dp[old]+nums[i], nums[i])
		ans = max(ans, dp[now])
	}
	return ans
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
