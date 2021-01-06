package sbgo

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	link := make(map[string]int)
	//str到id的映射
	for _, eq := range equations {
		if _, has := link[eq[0]]; !has {
			link[eq[0]] = len(link)
		}
		if _, has := link[eq[1]]; !has {
			link[eq[1]] = len(link)
		}
	}
	//创建一下边,混合类型用struct
	type edge struct {
		to     int
		weight float64
	}
	//建图
	gragh := make([][]edge, len(link))
	for i, eq := range equations {
		from, to := link[eq[0]], link[eq[1]]
		gragh[from] = append(gragh[from], edge{to, values[i]})
		gragh[to] = append(gragh[to], edge{from, 1.0 / values[i]})
	}
	bfs := func(start, end int) float64 {
		//防止进入闭环
		ratio := make([]float64, len(gragh))
		ratio[start] = 1
		que := []int{start}
		for len(que) > 0 {
			v := que[0]
			que = que[1:]
			if v == end {
				return ratio[v]
			}
			for _, e := range gragh[v] {
				if w := e.to; ratio[w] == 0 {
					ratio[w] = ratio[v] * e.weight
					que = append(que, w)
				}
			}
		}
		return -1
	}
	ans := make([]float64, len(queries))
	for i, q := range queries {
		start, hasS := link[q[0]]
		end, hasE := link[q[1]]
		if !hasS || !hasE {
			ans[i] = -1
		} else {
			ans[i] = bfs(start, end)
		}
	}
	return ans
}
