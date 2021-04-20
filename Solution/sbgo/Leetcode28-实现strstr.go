package sbgo

func strStr(haystack string, needle string) int {
	n, m := len(haystack), len(needle)
	if m == 0 {
		return 0
	}
	var i, j int
	for i, j = 0, 0; i < n && j < m; i++ {
		if haystack[i] == needle[j] {
			j++
		} else {
			i -= j
			j = 0
		}
	}
	if j < m {
		return -1
	}
	return i - m
}
