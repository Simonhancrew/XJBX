package sbgo

func strangePrinter(s string) int {
	n := len(s)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for len := 1; len <= n; len++ {
		for i := 0; i+len-1 < n; i++ {
			j := i + len - 1
			dp[i][j] = 1 + dp[i+1][j]
			for k := i + 1; k <= j; k++ {
				if s[i] == s[k] {
					dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k+1][j])
				}
			}
		}
	}
	return dp[0][n-1]
}
