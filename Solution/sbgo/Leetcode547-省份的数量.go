package sbgo

func findCircleNum(isConnected [][]int) int {
	n := len(isConnected)
	visited := make([]int, n)
	ans := 0
	for i := 0; i < n; i++ {
		if visited[i] == 0 {
			ans++
			dfs(isConnected, visited, i)
		}
	}
	return ans
}

func dfs(isConnected [][]int, visited []int, index int) {
	for j := 0; j < len(isConnected); j++ {
		if isConnected[index][j] == 1 && visited[j] == 0 {
			visited[j] = 1
			dfs(isConnected, visited, j)
		}
	}
}

//并查集实现,一个find，一个union，亲戚问题
func findCircleNum2(isConnected [][]int) int {
	n := len(isConnected)
	parent := make([]int, n)
	for i := range parent {
		parent[i] = i
	}
	//递归的话要先定义，不能推导
	var find func(int) int
	find = func(i int) int {
		for parent[i] != i { //if parent[i] != i
			i = parent[parent[i]] //parent[i] = find(parent[i])
		}
		return parent[i]
	}

	union := func(parent []int, i, j int) {
		parent[find(i)] = parent[find(j)]
	}

	for i, val := range isConnected {
		for j := i + 1; j < n; j++ {
			if val[j] == 1 {
				union(parent, i, j)
			}
		}
	}
	ans := 0
	for i, p := range parent {
		if i == p {
			ans++
		}
	}
	return ans
}
