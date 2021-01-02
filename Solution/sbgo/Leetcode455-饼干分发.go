package sbgo

import "sort"

//饼干数作为索引
//小饼干先满足小胃口
//递增可能的结果

func findContentChildren(g []int, s []int) int {
	sort.Slice(g, func(i, j int) bool { return g[i] < g[j] })
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	index := 0
	res := 0
	for i := 0; i < len(s); i++ {
		if index < len(g) && g[index] <= s[i] {
			index++
			res++
		}
	}
	return res
}
