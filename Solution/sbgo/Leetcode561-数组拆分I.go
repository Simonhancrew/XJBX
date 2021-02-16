package sbgo

import "sort"

func arrayPairSum(nums []int) int {
	n := len(nums)
	sort.Ints(nums)
	ans := 0
	for i := 0; i < n; i += 2 {
		ans += nums[i]
	}
	return ans
}
