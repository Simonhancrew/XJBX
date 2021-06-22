package sbgo

import "sort"

func permutation(s string) []string {
	n := len(s)
	ans, st := make([]string, 0), make([]bool, n)
	path := []byte{}
	ss := []byte(s)
	sort.Slice(ss, func(i, j int) bool { return ss[i] < ss[j] })
	var dfs func([]byte, int)
	dfs = func(ss []byte, idx int) {
		if idx == len(s) {
			ans = append(ans, string(path))
			return
		}
		for i := 0; i < len(ss); i++ {
			if !st[i] {
				if i > 0 && ss[i-1] == ss[i] && st[i-1] == false {
					continue
				}
				st[i] = true
				path = append(path, ss[i])
				dfs(ss, idx+1)
				st[i] = false
				path = path[0 : len(path)-1]
			}
		}
	}
	dfs(ss, 0)
	return ans
}
