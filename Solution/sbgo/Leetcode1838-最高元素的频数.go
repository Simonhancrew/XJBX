package sbgo

import "sort"

func maxFrequency(nums []int, k int) int {
	sort.Ints(nums)
	res, l, n, need := 1, 0, len(nums), 0
	for r := 1; r < n; r++ {
		need += (r - l) * (nums[r] - nums[r-1])
		for need > k {
			need -= (nums[r] - nums[l])
			l++
		}
		res = max(res, r-l+1)
	}
	return res
}
