package sbgo

//slice值传递可以被修改，slice本身可以理解成一个指针

func rotate(matrix [][]int) {
	var t = 0
	var d = len(matrix[0]) - 1
	for ; t < d; t, d = t+1, d-1 {
		rotatecircle(matrix, t, d)
	}

}

func rotatecircle(matrix [][]int, t int, d int) {
	offset := d - t
	for i := 0; i < offset; i++ {
		matrix[t][t+i], matrix[d-i][t], matrix[d][d-i], matrix[t+i][d] =
			matrix[d-i][t], matrix[d][d-i], matrix[t+i][d], matrix[t][t+i]
	}
}
