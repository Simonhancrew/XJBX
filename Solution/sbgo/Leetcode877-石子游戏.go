package sbgo

func stoneGame(piles []int) bool {
	n := len(piles)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for len := 1; len <= n; len++ {
		for i := 0; i+len-1 < n; i++ {
			j := i + len - 1
			if i == j {
				dp[i][j] = piles[i]
			} else {
				dp[i][j] = max(piles[i]-dp[i+1][j], piles[j]-dp[i][j-1])
			}
		}
	}
	return dp[0][n-1] > 0
}
