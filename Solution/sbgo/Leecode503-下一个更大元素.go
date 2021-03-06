package sbgo

func nextGreaterElements(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	s := []int{}
	for i := 2*n - 1; i >= 0; i-- {
		for len(s) > 0 && s[len(s)-1] <= nums[i%n] {
			s = s[:len(s)-1]
		}
		if len(s) > 0 {
			ans[i%n] = s[len(s)-1]
		} else {
			ans[i%n] = -1
		}
		s = append(s, nums[i%n])
	}
	return ans
}
