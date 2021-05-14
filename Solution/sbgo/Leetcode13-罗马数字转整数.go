package sbgo

var hash = map[byte]int{'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

func romanToInt(s string) int {
	n := len(s)
	res := hash[s[n-1]]
	for i := n - 2; i >= 0; i-- {
		cur := hash[s[i]]
		right := hash[s[i+1]]
		if right <= cur {
			res += cur
		} else {
			res -= cur
		}
	}
	return res
}
