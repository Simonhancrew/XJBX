package sbgo

func makeConnected(n int, connections [][]int) int {
	parent := make([]int, n)
	for i := range parent {
		parent[i] = i
	}
	size := make([]int, n)
	for i := range size {
		size[i] = 1
	}
	Area := n
	var find func(i int) int
	find = func(i int) int {
		if parent[i] == i {
			return parent[i]
		}
		parent[i] = find(parent[i])
		return parent[i]
	}
	union := func(x, y int) {
		fx, fy := find(x), find(y)
		if fx == fy {
			return
		}
		if size[fx] < size[fy] {
			fx, fy = fy, fx
		}
		Area--
		parent[fy] = fx
		size[fx] += size[fy]
	}
	mp := make(map[int]int)
	for _, conn := range connections {
		mp[conn[0]]++
		mp[conn[1]]++
		if find(conn[0]) == find(conn[1]) {
			continue
		}
		union(conn[0], conn[1])
	}
	if Area == 1 {
		return 0
	}
	m := len(mp)
	edges := len(connections)
	if edges-Area+1 >= m-1 {
		return Area - 1
	}
	return -1
}
