package sbgo

func longestValidParentheses(s string) int {
	//is this a slice?
	//stk := []int{}
	var stk []int
	res := 0
	stk = append(stk, -1)
	for i, j := range s {
		if j == '(' {
			stk = append(stk, i)
		} else {
			stk = stk[:len(stk)-1]
			if len(stk) == 0 {
				stk = append(stk, i)
			} else {
				res = max(res, i-stk[len(stk)-1])
			}
		}
	}
	return res
}
