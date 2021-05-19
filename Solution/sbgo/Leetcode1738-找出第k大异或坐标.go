package sbgo

import "sort"

func kthLargestValue(matrix [][]int, k int) int {
	n, m := len(matrix), len(matrix[0])
	res := []int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if i >= 1 {
				matrix[i][j] ^= matrix[i-1][j]
			}
			if j >= 1 {
				matrix[i][j] ^= matrix[i][j-1]
			}
			if i >= 1 && j >= 1 {
				matrix[i][j] ^= matrix[i-1][j-1]
			}
			res = append(res, matrix[i][j])
		}
	}
	//1.8之后推荐
	sort.Slice(res, func(i, j int) bool {
		return res[i] > res[j]
	})
	return res[k-1]
}
