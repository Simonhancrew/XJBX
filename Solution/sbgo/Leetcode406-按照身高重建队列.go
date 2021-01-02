package sbgo

import "sort"

//先排序,从达到小,然后从从前往后按照k插入
func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i, j int) bool {
		a, b := people[i], people[j]
		return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1])
	})
	ans := make([][]int, len(people))
	for i, person := range people {
		pos := person[1]
		copy(ans[pos+1:i+1], ans[pos:i])
		ans[pos] = person
	}
	return ans
}
