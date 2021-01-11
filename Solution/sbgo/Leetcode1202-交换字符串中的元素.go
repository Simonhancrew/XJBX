package sbgo

import (
	"sort"
)

func smallestStringWithSwaps(s string, pairs [][]int) string {
	n := len(s)
	unionSet := make([]int, n)
	for i := range unionSet {
		unionSet[i] = i
	}
	//路径往上优化
	find := func(i int) int {
		for i != unionSet[i] {
			unionSet[i] = unionSet[unionSet[i]]
			i = unionSet[i]
		}
		return i
	}
	union := func(x, y int) {
		fx, fy := find(x), find(y)
		if fx == fy {
			return
		}
		unionSet[fy] = fx
	}
	for _, val := range pairs {
		union(val[0], val[1])
	}
	mp := map[int][]byte{}
	//same group
	for i := range s {
		cur := find(i)
		mp[cur] = append(mp[cur], byte(s[i]))
	}
	//sort
	for _, bytes := range mp {
		sort.Slice(bytes, func(i, j int) bool { return bytes[i] < bytes[j] })
	}
	ans := make([]byte, n)
	for i := range ans {
		f := find(i)
		ans[i] = mp[f][0]
		mp[f] = mp[f][1:]
	}
	return string(ans)
}
