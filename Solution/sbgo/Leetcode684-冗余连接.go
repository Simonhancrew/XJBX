package sbgo

func findRedundantConnection(edges [][]int) []int {
	n := len(edges)
	parent := make([]int, n+1)
	for i := 1; i <= n; i++ {
		parent[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if x != parent[x] {
			parent[x] = find(parent[x])
		}
		return parent[x]
	}
	union := func(x, y int) {
		fx, fy := find(x), find(y)
		if fx == fy {
			return
		}
		parent[fy] = fx
	}
	for _, val := range edges {
		fx := find(val[0])
		fy := find(val[1])
		if fx != fy {
			union(val[0], val[1])
		} else {
			return val
		}
	}
	return []int{}
}
