package sbgo

func numWays(n int, relation [][]int, k int) int {
	edges := make([][]int, n)
	for _, s2d := range relation {
		edges[s2d[0]] = append(edges[s2d[0]], s2d[1])
	}
	var dfs func(int, int)
	ans := 0
	dfs = func(idx, step int) {
		if step == k {
			if idx == n-1 {
				ans += 1
			}
			return
		}
		for _, dst := range edges[idx] {
			dfs(dst, step+1)
		}
	}
	dfs(0, 0)
	return ans
}
