package sbgo

func matrixReshape(nums [][]int, r int, c int) [][]int {
	row, col := len(nums), len(nums[0])
	if row*col != r*c {
		return nums
	}
	ans := make([][]int, r)
	for i := 0; i < r; i++ {
		ans[i] = make([]int, c)
		for j := 0; j < c; j++ {
			l, r := (i*c+j)/col, (i*c+j)%col
			ans[i][j] = nums[l][r]
		}
	}
	return ans
}
