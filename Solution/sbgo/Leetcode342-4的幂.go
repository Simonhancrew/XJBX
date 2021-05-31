package sbgo

func isPowerOfFour(n int) bool {
	return n > 0 && (n&-n == n) && n%3 == 1
}
