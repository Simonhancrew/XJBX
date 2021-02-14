package sbgo

func minSwapsCouples(row []int) int {
	n := len(row)
	node := n / 2
	parent := make([]int, node)
	for i := 0; i < node; i++ {
		parent[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if parent[x] == x {
			return x
		}
		parent[x] = find(parent[x])
		return parent[x]
	}
	union := func(x, y int) {
		fx, fy := find(x), find(y)
		parent[fy] = fx
	}

	for i := 0; i < n; i += 2 {
		lhs := row[i] / 2
		rhs := row[i+1] / 2
		union(lhs, rhs)
	}

	mp := make(map[int]int)

	for i := 0; i < node; i++ {
		fi := find(i)
		mp[fi]++
	}
	ret := 0
	for _, v := range mp {
		ret += v - 1
	}
	return ret
}
