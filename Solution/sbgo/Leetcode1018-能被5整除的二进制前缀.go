package sbgo

func prefixesDivBy5(A []int) []bool {
	n := len(A)
	cur := 0
	res := make([]bool, n)
	for i := range A {
		cur <<= 1
		if cur >= 10 {
			cur -= 10
		}
		num := A[i]
		cur += num
		if cur%5 == 0 {
			res[i] = true
		}
	}
	return res
}
