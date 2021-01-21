package sbgo

func lastStoneWeightII(stones []int) int {
	res := 0
	for _, stone := range stones {
		res += stone
	}
	target := int(res / 2)
	dp := make([]int, target+1)
	n := len(stones)
	for i := 0; i < n; i++ {
		for j := target; j >= stones[i]; j-- {
			dp[j] = max(dp[j], dp[j-stones[i]]+stones[i])
		}
	}
	return res - 2*dp[target]
}
