package sbgo

func numTrees(n int) int {
	dp := make([]int, n+1)
	dp[0], dp[1] = 1, 1
	for i := 2; i <= n; i++ {
		for j := 1; j < i; j++ {
			dp[i] += dp[i-j] * dp[j-1]
		}
	}
	return dp[n]
}
