package sbgo

func isValidSerialization(preorder string) bool {
	n := len(preorder)
	stk := []int{1}
	i := 0
	for i < n {
		if len(stk) == 0 {
			return false
		}

		if preorder[i] == ',' {
			i++
		} else if preorder[i] == '#' {
			stk[len(stk)-1]--
			if stk[len(stk)-1] == 0 {
				stk = stk[:len(stk)-1]
			}
			i++
		} else {
			for i < n && preorder[i] != ',' {
				i++
			}
			stk[len(stk)-1]--
			if stk[len(stk)-1] == 0 {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, 2)
		}
	}
	return len(stk) == 0
}
