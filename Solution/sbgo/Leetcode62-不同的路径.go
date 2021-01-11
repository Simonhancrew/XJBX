package sbgo

func uniquePaths(m int, n int) int {
	dp := make([][]int, m)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				dp[i][j] = 1
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}

func uniquePaths2(m int, n int) int {
	dp := make([][]int, 2)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	old, now := 0, 0
	for i := 0; i < m; i++ {
		old = now
		now = 1 - now
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				dp[now][j] = 1
			} else {
				dp[now][j] = dp[old][j] + dp[now][j-1]
			}
		}
	}
	return dp[now][n-1]
}
