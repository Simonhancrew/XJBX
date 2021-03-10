package sbgo

func calculate(s string) int {
	n := len(s)
	i := 0
	ops := []int{1}
	ret := 0
	sign := 1
	for i < n {
		if s[i] == ' ' {
			i++
		} else if s[i] == '+' {
			sign = ops[len(ops)-1]
			i++
		} else if s[i] == '-' {
			sign = -ops[len(ops)-1]
			i++
		} else if s[i] == '(' {
			ops = append(ops, sign)
			i++
		} else if s[i] == ')' {
			ops = ops[:len(ops)-1]
			i++
		} else {
			sum := 0
			for i < n && s[i] >= '0' && s[i] <= '9' {
				sum = sum*10 + int(s[i]-'0')
				i++
			}
			ret += sum * sign
		}
	}
	return ret
}
