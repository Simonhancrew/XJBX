package sbgo

func firstBadVersion(n int) int {
	l, r := 1, n
	for l < r {
		mid := (l + r) >> 1
		if !isBadVersion(mid) {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}
