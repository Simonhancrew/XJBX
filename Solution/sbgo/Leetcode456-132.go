package sbgo

func find132pattern(nums []int) bool {
	n := len(nums)
	if n < 3 {
		return false
	}
	mini := make([]int, n)
	mini[0] = nums[0]
	for i := 1; i < n; i++ {
		mini[i] = min(mini[i-1], nums[i])
	}
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && stk[len(stk)-1] <= mini[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 && stk[len(stk)-1] < nums[i] {
			return true
		}
		stk = append(stk, nums[i])
	}
	return false
}

// func min(i, j int) int {
// 	if i < j {
// 		return i
// 	}
// 	return j
// }
