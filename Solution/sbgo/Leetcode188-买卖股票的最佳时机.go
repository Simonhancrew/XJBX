package sbgo

func maxProfit(k int, prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}
	if k > n/2 {
		res := 0
		for i := 0; i < n-1; i++ {
			res += max(prices[i+1]-prices[i], 0)
		}
		return res
	}
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2*k+2)
	}
	dp[0][1] = 0
	const IntMax = int(^uint(0) >> 1)
	const IntMin = ^IntMax
	for i := 2; i <= 2*k+1; i++ {
		dp[0][i] = IntMin
	}
	for i := 1; i <= n; i++ {
		//手中不持有股票
		for j := 1; j <= 2*k+1; j += 2 {
			dp[i][j] = dp[i-1][j] //前一天也不持有
			//前一天持有，今天立即卖出获利
			if j > 1 && i > 1 && dp[i-1][j-1] != IntMin {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+prices[i-1]-prices[i-2])
			}
		}
		//手中持有股票
		for j := 2; j < 2*k+2; j += 2 {
			//昨天没有持有，今天买入
			dp[i][j] = dp[i-1][j-1]
			//昨天持有，今日继续收获利润
			if i > 1 && dp[i-1][j] != IntMin {
				dp[i][j] = max(dp[i][j], dp[i-1][j]+prices[i-1]-prices[i-2])
			}
			//昨天没有持有阶段2的股票，今天卖出，立即买入。计算阶段2的收益
			if i > 1 && j > 2 && dp[i-1][j-2] != IntMin {
				dp[i][j] = max(dp[i][j], dp[i-1][j-2]+prices[i-1]-prices[i-2])
			}
		}
	}
	res := IntMin
	for i := 1; i <= 2*k+1; i += 2 {
		res = max(res, dp[n][i])
	}
	return res
}
