package sbgo

func countPairs(deliciousness []int) int {
	mp := map[int]int{}
	res := 0
	m := -1
	for _, val := range deliciousness {
		if m < val {
			m = val
		}
	}
	m = m * 2
	for _, d := range deliciousness {
		for i := 1; i <= m; i <<= 1 {
			res = (res + mp[i-d]) % (1e9 + 7)
		}
		mp[d]++
	}
	return res
}
