package sbgo

func climbStairs(n int) int {
	dp1, dp2, dp3 := 1, 1, 1
	for i := 2; i <= n; i++ {
		dp3 = dp2 + dp1
		dp1 = dp2
		dp2 = dp3
	}
	return dp3
}
