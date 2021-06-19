package sbgo

func maxLength(arr []string) int {
	n, ans := len(arr), 0
	for i := 0; i < (1 << n); i++ {
		st := make([]int, 26)
		flag := false
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 1 {
				chars := []byte(arr[j])
				for _, ch := range chars {
					st[ch-'a']++
					if st[ch-'a'] > 1 {
						flag = true
						break
					}
				}
			}
			if flag {
				break
			}
		}
		if !flag {
			s := 0
			for _, val := range st {
				s += val
			}
			ans = max(ans, s)
		}
	}
	return ans
}
