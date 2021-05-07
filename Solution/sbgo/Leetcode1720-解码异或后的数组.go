package sbgo

func decode(encoded []int, first int) []int {
	n := len(encoded) + 1
	res := make([]int, n)
	res[0] = first
	for i := 1; i < n; i++ {
		res[i] = res[i-1] ^ encoded[i-1]
	}
	return res
}
