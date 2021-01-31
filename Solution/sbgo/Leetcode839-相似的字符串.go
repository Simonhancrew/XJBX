package sbgo

type unionFind struct {
	parent, rank []int
	Area         int
}

func newUnionFind(n int) *unionFind {
	parent := make([]int, n)
	rank := make([]int, n)
	Area := n
	for i := range parent {
		parent[i] = i
		rank[i] = 1
	}
	return &unionFind{parent: parent, rank: rank, Area: Area}
}

func (uf *unionFind) find(x int) int {
	if x == uf.parent[x] {
		return x
	}
	uf.parent[x] = uf.find(uf.parent[x])
	return uf.parent[x]
}

func (uf *unionFind) union(x, y int) {
	fx, fy := uf.find(x), uf.find(y)
	if fx == fy {
		return
	}
	if uf.rank[fx] < uf.rank[fy] {
		fx, fy = fy, fx
	}
	uf.parent[fy] = fx
	uf.rank[fx] += uf.rank[fy]
	uf.Area--
}

func numSimilarGroups(strs []string) int {
	n := len(strs)
	uf := newUnionFind(n)
	check := func(strs1, strs2 string) bool {
		num := 0
		for i := range strs1 {
			if strs1[i] != strs2[i] {
				num++
			}
			if num > 2 {
				return false
			}
		}
		return true
	}
	for i := 0; i < n-1; i++ {
		for j := 1; j < n; j++ {
			if strs[i] == strs[j] {
				uf.union(i, j)
				continue
			}
			if check(strs[i], strs[j]) {
				uf.union(i, j)
			}
		}
	}
	return uf.Area
}
