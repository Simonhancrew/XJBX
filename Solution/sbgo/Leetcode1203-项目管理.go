package sbgo

func sortItems(n int, m int, group []int, beforeItems [][]int) []int {
	//每个组的项目集合
	groupItem := make([][]int, m+n)
	//组间依赖，组内依赖
	groupGraph := make([][]int, m+n)
	itemGraph := make([][]int, n)
	//组间入度，组内入度
	groupDegree := make([]int, m+n)
	itemDegree := make([]int, n)
	//一个有多少组，-1的组从m开始算起，往上+
	id := make([]int, m+n)
	for i := 0; i < m+n; i++ {
		id[i] = i
	}
	leftID := m
	//构建一下每个组里有那些项目
	for i := 0; i < n; i++ {
		if group[i] == -1 {
			group[i] = leftID
			leftID++
		}
		groupItem[group[i]] = append(groupItem[group[i]], i)
	}
	//构建组间入读和组间关系，组内入度和组内关系
	for i := 0; i < n; i++ {
		curGroupID := group[i]
		for _, item := range beforeItems[i] {
			beforeGroupID := group[item]
			if beforeGroupID == curGroupID {
				itemDegree[i]++
				itemGraph[item] = append(itemGraph[item], i)
			} else {
				groupDegree[curGroupID]++
				groupGraph[beforeGroupID] = append(groupGraph[beforeGroupID], curGroupID)
			}
		}
	}
	//先组间拓扑排序，之后依照组间的关系排序组内的
	groupTopSort := topSort(groupDegree, groupGraph, id)
	if len(groupTopSort) == 0 {
		return []int{}
	}
	ans := []int{}
	for _, curGroupID := range groupTopSort {
		size := len(groupItem[curGroupID])
		//没有项目就不管
		if size == 0 {
			continue
		}
		//组内的排序
		res := topSort(itemDegree, itemGraph, groupItem[curGroupID])
		if len(res) == 0 {
			return []int{}
		}
		//放入数组中
		for _, item := range res {
			ans = append(ans, item)
		}
	}
	return ans
}

//入度，图的依赖关系，需要排序的项目或者组
func topSort(deg []int, graph [][]int, items []int) []int {
	que := []int{}
	//先完成所有入度都为0的
	for _, item := range items {
		if deg[item] == 0 {
			que = append(que, item)
		}
	}
	res := []int{}
	for len(que) > 0 {
		tmp := que[0]
		que = que[1:]
		res = append(res, tmp)
		for _, item := range graph[tmp] {
			deg[item]--
			if deg[item] == 0 {
				que = append(que, item)
			}
		}
	}
	if len(res) == len(items) {
		return res
	}
	return []int{}
}
