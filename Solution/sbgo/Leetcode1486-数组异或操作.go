package sbgo

func xorOperation(n int, start int) int {
	res := 0
	for i := 0; i < n; i++ {
		num := start + 2*i
		res ^= num
	}
	return res
}
