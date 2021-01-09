package sbgo

//分阶段，135阶段手中不持有股票
//246手中持有股票
//细节就是开始的边界处理
//还有奇偶的情况详细考虑
func maxProfit(prices []int) int {
	n := len(prices)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 6)
	}
	dp[0][1] = 0
	const IntMax = int(^uint(0) >> 1)
	const IntMin = ^IntMax
	dp[0][2], dp[0][3], dp[0][4], dp[0][5] = IntMin, IntMin, IntMin, IntMin
	for i := 1; i <= n; i++ {
		//手中没股票的阶段
		for j := 1; j <= 5; j += 2 {
			//前一天也在阶段1，继续不买入
			dp[i][j] = dp[i-1][j]
			//前一天在阶段2或者4，今天卖了，不买入
			if j > 1 && i > 1 && dp[i-1][j-1] != IntMin {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+prices[i-1]-prices[i-2])
			}
		}
		for j := 2; j < 5; j += 2 {
			//前一天不持有股票，今天买入，收入不计算
			dp[i][j] = dp[i-1][j-1]
			//昨天就持有股票，今天继续获利
			if i > 1 && dp[i-1][j] != IntMin {
				dp[i][j] = max(dp[i][j], dp[i-1][j]+prices[i-1]-prices[i-2])
			}
			//昨天持有上一次的股票，今天卖完了立马买入
			if j > 2 && dp[i-1][j-2] != IntMin {
				dp[i][j] = max(dp[i][j], dp[i-1][j-2]+prices[i-1]-prices[i-2])
			}
		}
	}
	return max(max(dp[n][1], dp[n][3]), dp[n][5])
}
