package sbgo

func wiggleMaxLength(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}
	curdiff, prediff := 0, 0
	ans := 1
	for i := 1; i < n; i++ {
		curdiff = nums[i] - nums[i-1]
		if (curdiff > 0 && prediff <= 0) || (curdiff < 0 && prediff >= 0) {
			ans++
			prediff = curdiff
		}
	}
	return ans
}
