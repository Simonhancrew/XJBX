package sbgo

func hIndex(citations []int) int {
	l, r, n := 0, len(citations), len(citations)
	check := func(idx int) bool {
		return citations[n-idx] >= idx
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
