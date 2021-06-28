package sbgo

func numBusesToDestination(routes [][]int, source int, target int) int {
	if target == source {
		return 0
	}
	n := len(routes)
	dist := make([]int, n)
	for i := 0; i < n; i++ {
		dist[i] = int(1e8)
	}
	que := []int{}
	g := map[int][]int{}
	for i := 0; i < n; i++ {
		for _, j := range routes[i] {
			if j == source {
				que = append(que, i)
				dist[i] = 1
			}
			g[j] = append(g[j], i)
		}
	}

	for len(que) > 0 {
		t := que[0]
		que = que[1:]
		for _, x := range routes[t] {
			if x == target {
				return dist[t]
			}
			for _, y := range g[x] {
				if dist[y] > dist[t]+1 {
					dist[y] = dist[t] + 1
					que = append(que, y)
				}
			}
			delete(g, x)
		}
	}
	return -1
}
