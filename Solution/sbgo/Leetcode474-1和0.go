package sbgo

func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for _, str := range strs {
		num0, num1 := 0, 0
		for _, chr := range str {
			if chr == '0' {
				num0++
			} else {
				num1++
			}
		}

		for i := m; i >= num0; i-- {
			for j := n; j >= num1; j-- {
				dp[i][j] = max(dp[i][j], dp[i-num0][j-num1]+1)
			}
		}
	}
	return dp[m][n]
}
