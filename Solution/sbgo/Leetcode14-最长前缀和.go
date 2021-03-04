package sbgo

//golang里的字符串要修改的话需复制到一个缓冲区
//s := "hello"
//sc := []rune(s) or []byte(s)

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	m, n := len(strs[0]), len(strs)
	for i := 0; i < m; i++ {
		c := strs[0][i]
		for j := 0; j < n; j++ {
			if i == len(strs[j]) || strs[j][i] != c {
				return strs[0][:i]
			}
		}
	}
	return strs[0]
}
