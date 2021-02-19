package sbgo

func longestOnes(A []int, K int) int {
	start, ans, n := 0, 0, len(A)
	zeros := 0
	for end := 0; end < n; end++ {
		if A[end] == 0 {
			zeros++
		}
		for zeros > K {
			if A[start] == 0 {
				zeros--
			}
			start++
		}
		ans = max(ans, end-start+1)
	}
	return ans
}
