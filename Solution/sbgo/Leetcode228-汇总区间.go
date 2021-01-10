package sbgo

import "strconv"

func summaryRanges(nums []int) []string {
	n := len(nums)
	i := 0
	ans := []string{}
	for i < n {
		start := i
		i++
		for i < n && nums[i-1]+1 == nums[i] {
			i++
		}
		end := i - 1
		res := strconv.Itoa(nums[start])
		if start < end {
			res += "->" + strconv.Itoa(nums[end])
		}
		ans = append(ans, res)
	}
	return ans
}
