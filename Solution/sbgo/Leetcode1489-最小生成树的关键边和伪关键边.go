package sbgo
//并查集的创建和方法的设置
type unionFind struct{
	parent,size []int
	Area int	//连通区域大小
}
//init
func newUnionFind(n int) *unionFind {
	parent := make([]int,n)
	size := make([]int,n)
	for i := range parent {
		size[i] = 1
		parent[i] = i
	}
	return &unionFind{parent,size,n}
}

func (uf *unionFind) find(x int) int{
	if uf.parent[x] == x {
		return x
	}
	uf.parent[x] = uf.find(uf.parent[x])
	return uf.parent[x]
}

func (uf *unionFind) union(x,y int)  bool {
	fx := uf.find(x)
	fy := uf.find(y)
	if fx == fy{
		return false
	}
	if uf.size[fx] < uf.size[fy]{
		fx,fy = fy,fx
	}
	uf.parent[fy] = fx
	uf.size[fx] += uf.size[fy]
	uf.Area--
	return true	
}

func findCriticalAndPseudoCriticalEdges(n int, edges [][]int) [][]int {
	m := len(edges)
	//给每条边定位
	for i := 0;i < m;i++{
		edges[i] = append(edges[i],i)
	}
	sort.Slice(edges,func(i,j int) bool {return edges[i][2] < edges[j][2]})
	//复用的部分
	calcu := func(uf *unionFind,ignore int) int {
		v  := 0
		for i,e := range  edges{
			if i != ignore && uf.union(e[0],e[1]){
				v += e[2] 
			}
		}
		if uf.Area > 1{
			return math.MaxInt64
		}
		return v
	}
	//最小构建生成代价
	minVal := calcu(newUnionFind(n),-1)

	var key1,key2 []int
	//遍历每一条边，看他的关键性
	for i,e := range edges{
		if calcu(newUnionFind(n),i) > minVal{
			key1 = append(key1,e[3])
			continue
		}

		uf := newUnionFind(n)
		uf.union(e[0],e[1])
		if e[2] + calcu(uf,i) == minVal{
			key2 = append(key2,e[3])
		}
	}
	return [][]int{key1,key2}
}