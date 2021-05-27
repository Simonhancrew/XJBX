package sbgo

func hammingDistance(x int, y int) int {
	ans, s := 0, x^y
	for s != 0 {
		s -= (s & (-s))
		ans++
	}
	return ans
}
