package sbgo

func canEat(candiesCount []int, queries [][]int) []bool {
	n := len(candiesCount)
	presum := make([]int, n)
	presum[0] = candiesCount[0]
	for i := 1; i < n; i++ {
		presum[i] = presum[i-1] + candiesCount[i]
	}

	ans := make([]bool, len(queries))
	for i, query := range queries {
		ftype, day, cap := query[0], query[1], query[2]
		x1, y1 := day+1, (day+1)*cap
		x2 := 1
		if ftype > 0 {
			x2 = presum[ftype-1] + 1
		}
		y2 := presum[ftype]
		ans[i] = !(x1 > y2 || y1 < x2)
	}
	return ans
}
