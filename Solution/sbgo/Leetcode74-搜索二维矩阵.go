package sbgo

func searchMatrix(matrix [][]int, target int) bool {
	n, m := len(matrix), len(matrix[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == target {
				return true
			} else if matrix[i][j] > target {
				return false
			}
		}
	}
	return false
}
