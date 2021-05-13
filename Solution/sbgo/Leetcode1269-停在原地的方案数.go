package sbgo

func numWays(steps int, arrLen int) int {
	maxjump := min(arrLen, steps)
	dp := make([][]int, steps+1)
	for i := range dp {
		dp[i] = make([]int, maxjump)
	}
	dp[0][0] = 1
	var mod int
	mod = 1e9 + 7
	for i := 1; i <= steps; i++ {
		for j := 0; j < maxjump; j++ {
			dp[i][j] = dp[i-1][j]
			if j >= 1 {
				dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod
			}
			if j+1 < maxjump {
				dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod
			}
		}
	}
	return dp[steps][0]
}
