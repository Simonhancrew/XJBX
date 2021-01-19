package sbgo

import "sort"

func minCostConnectPoints(points [][]int) int {
	n := len(points)
	parent := make([]int, n)
	for i := range parent {
		parent[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if x == parent[x] {
			return x
		}
		parent[x] = find(parent[x])
		return parent[x]
	}
	union := func(x, y int) bool {
		fx, fy := find(x), find(y)
		if fx == fy {
			return false
		}
		parent[fy] = fx
		return true
	}
	manhattan := func(x, y int) int {
		return abs(points[x][0]-points[y][0]) + abs(points[x][1]-points[y][1])
	}
	type edge struct{ x, y, len int }
	edges := []edge{}
	for i := range points {
		for j := i + 1; j < n; j++ {
			edges = append(edges, edge{i, j, manhattan(i, j)})
		}
	}
	sort.Slice(edges, func(i, j int) bool { return edges[i].len < edges[j].len })
	ans := 0
	num := 1
	for _, eg := range edges {
		if union(eg.x, eg.y) {
			ans += eg.len
			num++
			if num == n {
				break
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}
