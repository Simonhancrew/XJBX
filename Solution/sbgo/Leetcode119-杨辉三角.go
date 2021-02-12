package sbgo

func getRow(rowIndex int) []int {
	pre := []int{}
	cur := []int{}
	for i := 0; i <= rowIndex; i++ {
		cur = make([]int, i+1)
		cur[0] = 1
		cur[i] = 1
		for j := 1; j < i; j++ {
			cur[j] = pre[j] + pre[j-1]
		}
		pre = cur
	}
	return cur
}
