package sbgo

import "fmt"

func readBinaryWatch(turnedOn int) []string {
	ans := make([]string, 0)
	for i := 0; i < (1 << 10); i++ {
		s := 0
		for j := 0; j < 10; j++ {
			if (i>>j)&1 == 1 {
				s++
			}
		}
		if s == turnedOn {
			h := i >> 6
			m := i & 63
			if h < 12 && m < 60 {
				ans = append(ans, fmt.Sprintf("%d:%02d", h, m))
			}
		}
	}
	return ans
}
