package sbgo

func minCostClimbingStairs(cost []int) int {
	n := len(cost)
	dp0 := 0
	dp1 := 0
	dp2 := 0
	for i := 2; i <= n; i++ {
		dp2 = min(dp1+cost[i-1], dp0+cost[i-2])
		dp0 = dp1
		dp1 = dp2
	}
	return dp2
}

//可以用滚动优化
