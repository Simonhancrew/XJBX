package sbgo

import "sort"

func hIndex(citations []int) int {
	n, res := len(citations), 0
	sort.Ints(citations)
	for i := n; i >= 1; i-- {
		if citations[n-i] >= i {
			res = i
			break
		}
	}
	return res
}
