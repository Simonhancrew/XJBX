package sbgo

import "sort"

func maxEnvelopes(envelopes [][]int) int {
	if len(envelopes) == 0 {
		return 0
	}
	n := len(envelopes)
	dp := make([]int, n)
	for i := range dp {
		dp[i] = 1
	}
	sort.Slice(envelopes, func(i, j int) bool {
		a, b := envelopes[i], envelopes[j]
		return a[0] < b[0] || a[0] == b[0] && a[1] > b[1]
	})
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if envelopes[j][1] < envelopes[i][1] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
	}
	return max(dp...)
}

func max(a ...int) int {
	ans := 0
	for _, val := range a {
		if val > ans {
			ans = val
		}
	}
	return ans
}
