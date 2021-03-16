package sbgo

func generateMatrix(n int) [][]int {
	startx, starty, offset, loop, count := 0, 0, 1, n/2, 1
	res := make([][]int, n)
	for i := range res {
		res[i] = make([]int, n)
	}
	for ; loop > 0; loop-- {
		i, j := startx, starty
		for j < starty+n-offset {
			res[i][j] = count
			count++
			j++
		}
		for i < startx+n-offset {
			res[i][j] = count
			count++
			i++
		}
		for j > starty {
			res[i][j] = count
			count++
			j--
		}
		for i > startx {
			res[i][j] = count
			count++
			i--
		}
		startx++
		starty++
		offset += 2
	}
	if n%2 != 0 {
		mid := n / 2
		res[mid][mid] = count
	}
	return res
}
