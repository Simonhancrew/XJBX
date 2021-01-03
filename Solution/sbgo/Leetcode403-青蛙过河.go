package sbgo

type void struct{}

var member void

func canCross(stones []int) bool {
	n := len(stones)
	//插值之前要创建map
	dp := make(map[int]map[int]int, n)
	for _, i := range stones {
		dp[i] = make(map[int]int)
	}
	dp[0][0] = 0
	for i := 0; i < len(stones)-1; i++ {
		//拿到第二个set中的key
		for k := range dp[stones[i]] {
			for step := -1; step <= 1; step++ {
				t := stones[i] + (k + step)
				if dp[t] != nil {
					dp[t][k+step]++
				}
			}
		}
	}
	return len(dp[stones[n-1]]) != 0
}
