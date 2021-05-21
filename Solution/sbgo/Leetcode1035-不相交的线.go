package sbgo

func maxUncrossedLines(nums1 []int, nums2 []int) int {
	n, m := len(nums1), len(nums2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j])
			}
		}
	}
	return dp[n][m]
}
