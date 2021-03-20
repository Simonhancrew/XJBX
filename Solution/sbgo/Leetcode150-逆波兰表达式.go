package sbgo

import "strconv"

func evalRPN(tokens []string) int {
	stk := []int{}
	eval := func(s string) {
		a, b := stk[len(stk)-2], stk[len(stk)-1]
		stk = stk[:len(stk)-2]
		if s == "+" {
			stk = append(stk, a+b)
		} else if s == "-" {
			stk = append(stk, a-b)
		} else if s == "*" {
			stk = append(stk, a*b)
		} else {
			stk = append(stk, a/b)
		}
	}
	for _, tt := range tokens {
		if tt == "+" || tt == "-" || tt == "*" || tt == "/" {
			eval(tt)
		} else {
			num, err := strconv.Atoi(tt)
			if err == nil {
				stk = append(stk, num)
			}
		}
	}
	return stk[0]
}
