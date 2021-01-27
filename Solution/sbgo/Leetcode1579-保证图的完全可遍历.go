package sbgo

//对于go中外部创建并查集还是不熟悉
//定义结构
type unionFind struct {
	parent, size []int
	Area         int
}

//类似于构造函数，但是不是方法
func newUnionFind(n int) *unionFind {
	parent := make([]int, n)
	size := make([]int, n)
	for i := range parent {
		size[i] = 1
		parent[i] = i

	}
	return &unionFind{parent: parent, size: size, Area: n}
}

//内部的成员方法
func (uf *unionFind) find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.find(uf.parent[x])
	}
	return uf.parent[x]
}

func (uf *unionFind) union(x, y int) bool {
	fx, fy := uf.find(x), uf.find(y)
	if fx == fy {
		return false
	}
	if uf.size[fx] < uf.size[fy] {
		fx, fy = fy, fx
	}
	uf.Area--
	uf.parent[fy] = fx
	uf.size[fx] += uf.size[fy]
	return true
}

func maxNumEdgesToRemove(n int, edges [][]int) int {
	alice, bob := newUnionFind(n), newUnionFind(n)
	for _, edge := range edges {
		edge[1]--
		edge[2]--
	}
	ans := 0
	for _, edge := range edges {
		if edge[0] == 3 {
			if alice.union(edge[1], edge[2]) == false {
				ans++
			} else {
				bob.union(edge[1], edge[2])
			}
		}
	}
	for _, edge := range edges {
		if edge[0] == 1 {
			if alice.union(edge[1], edge[2]) == false {
				ans++
			}
		}
		if edge[0] == 2 {
			if bob.union(edge[1], edge[2]) == false {
				ans++
			}
		}
	}
	if alice.Area != 1 || bob.Area != 1 {
		return -1
	}
	return ans
}
