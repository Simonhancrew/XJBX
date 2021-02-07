package sbgo

func checkPossibility(nums []int) bool {
	n := len(nums)
	cnt := 0
	for i := 0; i < n-1; i++ {
		x, y := nums[i], nums[i+1]
		if x > y {
			cnt++
			if cnt > 1 {
				return false
			}
			if i > 0 && nums[i+1] < nums[i-1] {
				nums[i+1] = nums[i]
			}
		}
	}
	return true
}
