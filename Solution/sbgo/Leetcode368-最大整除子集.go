package sbgo

import "sort"

func largestDivisibleSubset(nums []int) []int {
	n := len(nums)
	sort.Ints(nums)
	k := 0
	dp := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if nums[i]%nums[j] == 0 {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		if dp[i] > dp[k] {
			k = i
		}
	}

	res := []int{}
	for true {
		res = append(res, nums[k])
		if dp[k] == 1 {
			break
		}
		for i := 0; i < k; i++ {
			if nums[k]%nums[i] == 0 && dp[i] == dp[k]-1 {
				k = i
				break
			}
		}
	}
	return res
}
