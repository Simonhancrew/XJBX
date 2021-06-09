package sbgo

func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
	MOD := int(1e9 + 7)
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, minProfit+1)
		dp[i][0] = 1
	}
	for i := 0; i < len(group); i++ {
		g, p := group[i], profit[i]
		for j := n; j >= g; j-- {
			for k := minProfit; k >= 0; k-- {
				dp[j][k] = (dp[j][k] + dp[j-g][max(0, k-p)]) % MOD
			}
		}
	}
	return dp[n][minProfit]
}
