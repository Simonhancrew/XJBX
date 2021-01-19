package sbgo

func hitBricks(grid [][]int, hits [][]int) []int {
	row := len(grid)
	col := len(grid[0])
	size := row * col
	parent := make([]int, size+1)
	for i := range parent {
		parent[i] = i
	}
	rank := make([]int, size+1)
	for i := range rank {
		rank[i] = 1
	}
	var find func(i int) int
	find = func(i int) int {
		if parent[i] != i {
			parent[i] = find(parent[i])
		}
		return parent[i]
	}
	union := func(x, y int) {
		fx := find(x)
		fy := find(y)
		if fx == fy {
			return
		}
		parent[fy] = fx
		rank[fx] += rank[fy]
	}
	getindex := func(x, y int) int {
		return x*col + y
	}
	//注意slice的拷贝要浅拷贝，只传递值
	copy := make([][]int, row)
	for i := range copy {
		copy[i] = append(copy[i], grid[i]...)
	}
	for _, hit := range hits {
		copy[hit[0]][hit[1]] = 0
	}
	for i := 0; i < col; i++ {
		if copy[0][i] == 1 {
			union(size, i)
		}
	}
	for i := 1; i < row; i++ {
		for j := 0; j < col; j++ {
			if copy[i][j] == 1 {
				if copy[i-1][j] == 1 {
					union(getindex(i, j), getindex(i-1, j))
				}
				if j > 0 && copy[i][j-1] == 1 {
					union(getindex(i, j), getindex(i, j-1))
				}
			}
		}
	}
	//补回砖块
	n := len(hits)
	ans := make([]int, n)
	inArea := func(x, y int) bool { return x >= 0 && y >= 0 && y < col && x < row }
	directions := [4][2]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
	for i := n - 1; i >= 0; i-- {
		x := hits[i][0]
		y := hits[i][1]
		if grid[x][y] == 0 {
			continue
		}
		origin := rank[find(size)]
		if x == 0 {
			union(size, y)
		}
		for _, direction := range directions {
			prex := x + direction[0]
			prey := y + direction[1]
			if inArea(prex, prey) && copy[prex][prey] == 1 {
				union(getindex(prex, prey), getindex(x, y))
			}
		}
		cur := rank[find(size)]
		ans[i] = max(0, cur-origin-1)
		copy[x][y] = 1
	}
	return ans
}
