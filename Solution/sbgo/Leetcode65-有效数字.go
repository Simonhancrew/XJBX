package sbgo

import "strings"

// go的字符串不可改变，可以进行比较.编码采用uft-8
// 如果要修改可以变为byte slice  s := []byte(s)

func isNumber(s string) bool {
	eps := strings.Index(s, "e")
	Eps := strings.Index(s, "E")
	if eps != -1 {
		return ispurenumber(s[:eps], false) && ispurenumber(s[eps+1:], true)
	}
	if Eps != -1 {
		return ispurenumber(s[:Eps], false) && ispurenumber(s[Eps+1:], true)
	}
	return ispurenumber(s, false)
}

func ispurenumber(s string, must_be_int bool) bool {
	if len(s) == 0 {
		return false
	}
	has_digit, has_dot := false, false
	st := 0
	if s[0] == '+' || s[0] == '-' {
		st = 1
	}
	for i := st; i < len(s); i++ {
		if s[i] == '.' {
			if must_be_int {
				return false
			}
			if has_dot {
				return false
			}
			has_dot = true
		} else if s[i] >= '0' && s[i] <= '9' {
			has_digit = true
		}
	}
	return has_digit
}
