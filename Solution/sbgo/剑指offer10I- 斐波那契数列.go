package sbgo

func fib(n int) int {
	x, y := 0, 1
	var cons = 1000000007
	for i := 0; i < n; i++ {
		x, y = y, (x+y)%cons
	}
	return x
}
