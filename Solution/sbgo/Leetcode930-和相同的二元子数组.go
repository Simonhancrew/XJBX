package sbgo

func numSubarraysWithSum(nums []int, goal int) int {
	res, l1, l2, s1, s2 := 0, 0, 0, 0, 0
	n := len(nums)
	for r := 0; r < n; r++ {
		s1 += nums[r]
		for l1 <= r && s1 > goal {
			s1 -= nums[l1]
			l1++
		}
		s2 += nums[r]
		for l2 <= r && s2 >= goal {
			s2 -= nums[l2]
			l2++
		}
		res += l2 - l1
	}
	return res
}
