package sbgo

func flipAndInvertImage(A [][]int) [][]int {
	m, n := len(A), len(A[0])
	for i := 0; i < m; i++ {
		start, end := 0, n-1
		for start < end {
			if A[i][start] == A[i][end] {
				A[i][start] ^= 1
				A[i][end] ^= 1
			}
			start++
			end--
		}
		if start == end {
			A[i][start] ^= 1
		}
	}
	return A
}
