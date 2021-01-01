package sbgo

func minPathSum(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	dp := make([][]int, len(grid))
	row := len(grid)
	col := len(grid[0])
	for i := 0; i < row; i++ {
		dp[i] = make([]int, col)
	}
	dp[0][0] = grid[0][0]
	for i := 1; i < col; i++ {
		dp[0][i] = dp[0][i-1] + grid[0][i]
	}
	for i := 1; i < row; i++ {
		dp[i][0] = dp[i-1][0] + grid[i][0]
		for j := 1; j < col; j++ {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
		}
	}
	return dp[row-1][col-1]
}

//滚动数组优化

func minPathSum2(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	dp := make([][]int, 2)
	row := len(grid)
	col := len(grid[0])
	now, old := 0, 0
	for i := 0; i < 2; i++ {
		dp[i] = make([]int, col)
	}
	dp[0][0] = grid[0][0]
	for i := 1; i < col; i++ {
		dp[0][i] = dp[0][i-1] + grid[0][i]
	}
	for i := 1; i < row; i++ {
		old = now
		now = 1 - now
		dp[now][0] = dp[old][0] + grid[i][0]
		for j := 1; j < col; j++ {
			dp[now][j] = min(dp[old][j], dp[now][j-1]) + grid[i][j]
		}
	}
	return dp[now][col-1]
}
