package sbgo

func minKBitFlips(A []int, K int) int {
	n := len(A)
	cnt, ans := 0, 0
	dif := make([]int, n+1)
	for i := 0; i < n; i++ {
		cnt += dif[i]
		if (cnt+A[i])%2 == 0 {
			if i+K > n {
				return -1
			}
			ans++
			cnt++
			dif[i+K]--
		}
	}
	return ans
}
