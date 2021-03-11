package sbgo

func calculate(s string) int {
	n := len(s)
	preSign := '+'
	num := 0
	st := []int{}
	isdigit := func(i byte) bool {
		if i >= '0' && i <= '9' {
			return true
		}
		return false
	}
	for i := 0; i < n; i++ {
		if isdigit(s[i]) {
			num = num*10 + int(s[i]-'0')
		}
		if !isdigit(s[i]) && s[i] != ' ' || i == n-1 {
			if preSign == '+' {
				st = append(st, num)
			} else if preSign == '-' {
				st = append(st, -num)
			} else if preSign == '*' {
				st[len(st)-1] *= num
			} else {
				st[len(st)-1] /= num
			}
			preSign = rune(s[i])
			num = 0
		}
	}
	ans := 0
	for _, v := range st {
		ans += v
	}
	return ans
}
