package sbgo

func largestRectangleArea(heights []int) int {
	stk := []int{}
	n := len(heights)
	left := make([]int, n)
	right := make([]int, n)
	for i := 0; i < n; i++ {
		for len(stk) > 0 && heights[i] <= heights[stk[len(stk)-1]] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) == 0 {
			left[i] = -1
		} else {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && heights[i] <= heights[stk[len(stk)-1]] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) == 0 {
			right[i] = n
		} else {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	ans := 0
	for i, val := range heights {
		ans = max(ans, val*(right[i]-left[i]-1))
	}
	return ans
}
