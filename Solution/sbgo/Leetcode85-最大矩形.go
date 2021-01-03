package sbgo

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	res := 0
	m := len(matrix)
	n := len(matrix[0])
	dp := make([][][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = make([]int, 3)
			if matrix[i][j] == '1' {
				if i == 0 && j == 0 {
					dp[i][j][0], dp[i][j][1], dp[i][j][2] = 1, 1, 1
				} else if i == 0 {
					dp[i][j][0], dp[i][j][1], dp[i][j][2] = dp[i][j-1][0]+1, 1, dp[i][j-1][2]+1
				} else if j == 0 {
					dp[i][j][0], dp[i][j][1], dp[i][j][2] = 1, dp[i-1][j][1]+1, dp[i-1][j][2]+1
				} else {
					dp[i][j][0] = dp[i][j-1][0] + 1 //左边有多少个1,长
					dp[i][j][1] = dp[i-1][j][1] + 1
					colMin := dp[i][j][0]
					row := dp[i][j][1]
					for k := 0; k < row; k++ {
						colMin = min(dp[i-k][j][0], colMin)
						dp[i][j][2] = max(dp[i][j][2], colMin*(k+1))
					}
				}
			}
			res = max(res, dp[i][j][2])
		}
	}
	return res
}
