package sbgo

func regionsBySlashes(grid []string) int {
	n := len(grid)
	parent := make([]int, 4*n*n)
	for i := range parent {
		parent[i] = i
	}
	var find func(i int) int
	find = func(x int) int {
		if parent[x] == x {
			return x
		}
		parent[x] = find(parent[x])
		return parent[x]
	}
	union := func(x, y int) {
		fx, fy := find(x), find(y)
		if fx == fy {
			return
		}
		parent[fy] = fx
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			s := 4 * (i*n + j)
			if grid[i][j] == '/' {
				union(s, s+3)
				union(s+1, s+2)
			} else {
				union(s, s+1)
				union(s+2, s+3)
			}
			if grid[i][j] == ' ' {
				union(s, s+3)
			}
			//合并上下左右的块联通
			if i > 0 {
				union(s, s-4*n+2)
			}
			if j > 0 {
				union(s+3, s-3)
			}
		}
	}
	cnt := 0
	for i := range parent {
		if parent[i] == i {
			cnt++
		}
	}
	return cnt
}
