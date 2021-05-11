package sbgo

func decode(encoded []int) []int {
	n := len(encoded) + 1
	ans := make([]int, n)
	x := 0
	for i := 1; i <= n; i++ {
		x ^= i
	}
	cur := 0
	for i := 0; i < n-1; i += 2 {
		cur ^= encoded[i]
	}
	last := cur ^ x
	ans[n-1] = last
	for i := n - 2; i >= 0; i-- {
		ans[i] = ans[i+1] ^ encoded[i]
	}
	return ans
}
