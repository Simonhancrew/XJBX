package sbgo

//背包问题最重要的就是称重要进状态

func canPartition(nums []int) bool {
	//判断是必要的
	n := len(nums)
	if n < 2 {
		return false
	}
	res, maxnum := 0, 0
	for _, num := range nums {
		res += num
		maxnum = max(maxnum, num)
	}
	if res%2 == 1 {
		return false
	}
	target := res / 2
	if maxnum > target {
		return false
	}
	dp := make([][]bool, n)
	dp[0] = make([]bool, target+1)
	dp[0][nums[0]] = true
	for i := 1; i < n; i++ {
		dp[i] = make([]bool, target+1)
		dp[i][0] = true
		num := nums[i]
		for j := 1; j <= target; j++ {
			if j > num {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-num]
			} else {
				dp[i][j] = dp[i-1][j]
			}
		}
	}
	return dp[n-1][target]
}
