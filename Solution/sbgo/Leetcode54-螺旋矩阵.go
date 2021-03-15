package sbgo

func spiralOrder(matrix [][]int) []int {
	m, n := len(matrix), len(matrix[0])
	x1, x2, y1, y2 := 0, m-1, 0, n-1
	res := []int{}
	//注意把等于的情况也考虑进来
	for x1 <= x2 && y1 <= y2 {
		for i := y1; i <= y2; i++ {
			res = append(res, matrix[x1][i])
		}
		for i := x1 + 1; i <= x2; i++ {
			res = append(res, matrix[i][y2])
		}

		if x1 < x2 && y1 < y2 {
			for i := y2 - 1; i > y1; i-- {
				res = append(res, matrix[x2][i])
			}
			for i := x2; i > x1; i-- {
				res = append(res, matrix[i][y1])
			}
		}
		x1++
		y1++
		x2--
		y2--
	}
	return res
}
