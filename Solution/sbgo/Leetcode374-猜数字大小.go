package sbgo

func guessNumber(n int) int {
	l, r := 1, n
	for l < r {
		mid := l + (r-l)/2
		if guess(mid) > 0 {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}
