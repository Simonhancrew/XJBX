package sbgo

func findTargetSumWays(nums []int, S int) int {
	sum := 0
	for _, val := range nums {
		sum += val
	}
	if S > sum || (S+sum)%2 == 1 {
		return 0
	}
	wet := (S + sum) / 2
	dp := make([]int, wet+1)
	dp[0] = 1
	for i := range nums {
		for j := wet; j >= nums[i]; j-- {
			dp[j] += dp[j-nums[i]]
		}
	}
	return dp[wet]
}
