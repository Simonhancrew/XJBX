package sbgo

func generate(numRows int) [][]int {
	//slice不用append的话就用动态分配一下大小
	//引用型数据结构都要这样
	ans := make([][]int, numRows)
	for i := 0; i < numRows; i++ {
		ans[i] = make([]int, i+1)
		ans[i][0], ans[i][i] = 1, 1
		for j := 1; j < i; j++ {
			ans[i][j] = ans[i-1][j] + ans[i-1][j-1]
		}
	}
	return ans
}
