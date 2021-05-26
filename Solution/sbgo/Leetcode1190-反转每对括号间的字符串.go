package sbgo

func reverseParentheses(s string) string {
	n := len(s)
	cur := []byte{}
	stk := [][]byte{}
	for i := 0; i < n; i++ {
		if s[i] == '(' {
			stk = append(stk, cur)
			cur = []byte{}
		} else if s[i] == ')' {
			for j, n := 0, len(cur); j < len(cur)/2; j++ {
				cur[j], cur[n-1-j] = cur[n-1-j], cur[j]
			}
			cur = append(stk[len(stk)-1], cur...)
			stk = stk[:len(stk)-1]
		} else {
			cur = append(cur, s[i])
		}
	}
	return string(cur)
}
