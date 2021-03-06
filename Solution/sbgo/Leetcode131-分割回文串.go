package sbgo

func partition(s string) [][]string {
	path := []string{}
	ans := [][]string{}
	dfs(s, 0, path, &ans)
	return ans
}

func dfs(s string, start int, path []string, ans *[][]string) {
	if start == len(s) {
		//共享内存，需要复制path的内容，不然会被后修修改
		tmp := make([]string, len(path))
		copy(tmp, path)
		*ans = append(*ans, tmp)
	}
	for i := start; i < len(s); i++ {
		if ispa(s, start, i) {
			path = append(path, s[start:i+1])
			dfs(s, i+1, path, ans)
			path = path[:len(path)-1]
		} else {
			continue
		}
	}
}

func ispa(s string, l, r int) bool {
	for l < r {
		if s[l] == s[r] {
			l--
			r++
		} else {
			return false
		}
	}
	return true
}
