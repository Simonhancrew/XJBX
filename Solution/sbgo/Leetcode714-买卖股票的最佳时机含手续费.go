package sbgo

func maxProfit(prices []int, fee int) int {
	n := len(prices)
	if n < 2 {
		return 0
	}
	dp := make([][]int, 2)
	dp[0] = make([]int, 2)
	dp[0][0] = 0
	dp[0][1] = -prices[0]
	dp[1] = make([]int, 2)
	old, now := 0, 0
	for i := 0; i < n; i++ {
		old = now
		now = 1 - now
		dp[now][0] = max(dp[old][0], dp[old][1]+prices[i]-fee)
		dp[now][1] = max(dp[old][0]-prices[i], dp[old][1])
	}
	return dp[now][0]
}
