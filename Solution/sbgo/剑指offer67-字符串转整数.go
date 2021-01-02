package sbgo

import (
	"math"
	"strings"
)

func strToInt(str string) int {
	str = strings.TrimSpace(str)
	res := 0
	flage := 1
	for i := range str {
		if str[i] >= '0' && str[i] <= '9' {
			res = 10*res + int(str[i]-'0')
		} else if str[i] == '+' && i == 0 {
			flage = 1
		} else if str[i] == '-' && i == 0 {
			flage = -1
		} else {
			break
		}
		//在内部就处理掉，防外部的话可能超过int64，得到一个INT64min的值
		if res > math.MaxInt32 {
			if flage == -1 {
				return math.MinInt32
			}
			return math.MaxInt32
		}
	}
	return flage * res
}
