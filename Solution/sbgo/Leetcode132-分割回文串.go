package sbgo

func minCut(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}
	jucdge := make([][]int, n)
	for i := 0; i < n; i++ {
		jucdge[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		l, r := i, i
		for l >= 0 && r < n && s[l] == s[r] {
			jucdge[l][r] = 1
			l--
			r++
		}
		l, r = i, i+1
		for l >= 0 && r < n && s[l] == s[r] {
			jucdge[l][r] = 1
			l--
			r++
		}
	}
	dp := make([]int, n+1)
	dp[0] = 0
	for i := 1; i <= n; i++ {
		dp[i] = 1 << 20
	}
	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			if jucdge[j][i-1] == 1 {
				dp[i] = min(dp[j]+1, dp[i])
			}
		}
	}
	return dp[n] - 1
}
