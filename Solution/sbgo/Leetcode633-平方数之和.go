package sbgo

func judgeSquareSum(c int) bool {
	a, b := 0, 0
	for a <= b {
		if c > a*a+b*b {
			b++
		} else if c < a*a+b*b {
			a++
			b--
		} else {
			return true
		}
	}
	return false
}
