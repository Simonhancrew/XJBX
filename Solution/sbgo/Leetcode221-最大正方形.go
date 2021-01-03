package sbgo

func maximalSquare(matrix [][]byte) int {
	m := len(matrix)
	n := len(matrix[0])
	res := 0
	//动态数组初始化写make
	dp := make([][]int, len(matrix))
	//第二维也要创建
	for i := 0; i < len(matrix); i++ {
		dp[i] = make([]int, len(matrix[0]))
		for j := 0; j < len(matrix[0]); j++ {
			dp[i][j] = int(matrix[i][j] - '0')
			if dp[i][j] == 1 {
				res = 1
			}
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == '1' {
				if i == 0 || j == 0 {
					dp[i][j] = 1
				} else {
					dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1
				}
				if dp[i][j] > res {
					res = dp[i][j]
				}
			} else {
				dp[i][j] = 0
			}
		}
	}
	return res * res
}
