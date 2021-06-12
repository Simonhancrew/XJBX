package sbgo

import "math"

func largestNumber(cost []int, target int) string {
	dp := make([]int, target+1)
	for i := 1; i <= target; i++ {
		dp[i] = math.MinInt32
	}
	for i := 0; i < 9; i++ {
		for j := cost[i]; j <= target; j++ {
			dp[j] = max(dp[j], dp[j-cost[i]]+1)
		}
	}

	if dp[target] < 0 {
		return "0"
	}
	ans := []byte{}
	j := target
	for i := 8; i >= 0; i-- {
		for j >= cost[i] && dp[j] == dp[j-cost[i]]+1 {
			ans = append(ans, byte('1'+i))
			j -= cost[i]
		}
	}
	return string(ans)
}
