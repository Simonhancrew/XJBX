package sbgo

func transpose(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, m)
	}
	for i, row := range matrix {
		for j, v := range row {
			ans[j][i] = v
		}
	}
	return ans
}
