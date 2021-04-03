package sbgo

func longestCommonSubsequence(text1 string, text2 string) int {
	n, m := len(text1), len(text2)
	dp := make([][]int, n+1)
	for i, _ := range dp {
		dp[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			if text1[i-1] == text2[j-1] {
				dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j])
			}
		}
	}
	return dp[n][m]
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
