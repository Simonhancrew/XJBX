package sbgo

func nthUglyNumber(n int) int {
	p2, p3, p5 := 0, 0, 0
	dp := make([]int, n)
	dp[0] = 1
	for i := 1; i < n; i++ {
		dp[i] = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5))
		if dp[i] == dp[p2]*2 {
			p2++
		}
		if dp[i] == dp[p3]*3 {
			p3++
		}
		if dp[i] == dp[p5]*5 {
			p5++
		}
	}
	return dp[n-1]
}
